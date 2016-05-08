#include "graphics.h"
#include "tiles.h"


component_t *tileengine_create(object_t *obj)
{
	component_t *c = component_create(COMPONENT_TILEENGINE, obj, sizeof(tileengine_t));
	tileengine_t *te = (tileengine_t*) c;
	te->current_tilemap = NULL;
	te->source.x = 0;
	te->source.y = 0;
	te->source.w = 128;
	te->source.h = 128;
	linked_list_init(&te->tilemaps);
	register_event_callback(&c->obj->scenario->ed, EV_RENDER, c, &tileengine_render);
	return c;
}

tilepool_t *create_tilepool(char *filename, uint16_t tw, uint16_t th, uint16_t xoff, uint16_t yoff, uint16_t cols, uint16_t rows)
{
	tilepool_t *tp = (tilepool_t*) malloc(sizeof(tilepool_t));	
	tp->_tilemap = create_sprite();
	load_bmp(tp->_tilemap, filename);

	tp->_tw = tw;
	tp->_th = th;
	tp->_xoffset = xoff;
	tp->_yoffset = yoff;
	tp->_cols = cols;
	tp->_rows = rows;
	return tp;
}

static void tilemap_draw(graphics_t *graphics, tilemap_t *tilemap, rect_t *src)
{
	int tw = tilemap->pool->_tw;
	int th = tilemap->pool->_th;

	int tsrc_x = src->x/tw > 0 ? src->x/tw : 0;
	int tsrc_y = src->y/th > 0 ? src->y/th : 0;
	int nxf = ((src->x+src->w)/tw)+1 <=  tilemap->size_x ? (src->x+src->w)/tw+1 : tilemap->size_x;
	int nyf = ((src->y+src->h)/th)+1 <=  tilemap->size_y ? (src->y+src->h)/th+1 : tilemap->size_y;

	/*TODO: Clamp value and set to 0 if other component is 0*/
	int nx = nxf-tsrc_x;
	int ny = nyf-tsrc_y;

	uint16_t *tilestruct = tilemap->tilestruct;
	tilepool_t *pool = tilemap->pool;

	int c;
	rect_t tsrc;
	rect_t dst;

	int screen_xoffset = src->x > 0 ? (src->x%tw) : src->x;
	int screen_yoffset = src->y > 0 ? (src->y%th) : src->y;

	for(int i=0;i<ny;i++)
	{
		for(int j=0;j<nx;j++)
		{
			c = *(tilestruct+((i+tsrc_y)*pool->_cols+(j+tsrc_x)));
			tsrc.x = pool->_xoffset+tw*(c%pool->_cols);
			tsrc.y = pool->_yoffset+th*(c/pool->_cols);
			tsrc.w = tw;
			tsrc.h = th;
			dst.x = j*tsrc.w-screen_xoffset;
			dst.y = i*tsrc.h-screen_yoffset;
			blit(pool->_tilemap, &graphics->screen, &tsrc, &dst);
		}
	}
}

void tileengine_render(void *component, void *args)
{
	tileengine_t *te = (tileengine_t*) component;
	graphics_t *graphics = (graphics_t*) args;

	tilemap_t *tilemap = te->current_tilemap;
	te->source.x += 1;
	te->source.y += 1;

	tilemap_draw(graphics, tilemap, &te->source);
}

tilemap_t *create_tilemap(tilepool_t *pool, uint16_t *tilestruct, int size_x, int size_y, uint8_t depth)
{
	tilemap_t *tm = (tilemap_t*) malloc(sizeof(tilemap_t));
	tm->pool = pool;
	tm->tilestruct = tilestruct;
	tm->size_x = size_x;
	tm->size_y = size_y;
	tm->depth = depth;

	return tm;
}
