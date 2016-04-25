#include "graphics.h"
#include "tiles.h"


void tileengine_init(component_t *c, void **args)
{
	tileengine_t *te = (tileengine_t*) c;
	te->current_tilemap = NULL;
	te->screen_x = 0;
	te->screen_y = 0;
	te->screen_width = 128;
	te->screen_height = 128;
	linked_list_init(&te->tilemaps);
	register_event_callback(&c->obj->scenario->ed, EV_RENDER, c, &tileengine_render);
}

tilepool_t *create_tilepool(char *filename, uint16_t tw, uint16_t th, uint16_t xoff, uint16_t yoff)
{
	tilepool_t *tp = (tilepool_t*) malloc(sizeof(tilepool_t));	
	tp->_tilemap = create_sprite();
	load_bmp(tp->_tilemap, filename);

	tp->_tw = tw;
	tp->_th = th;
	tp->_xoffset = xoff;
	tp->_yoffset = yoff;
	return tp;
}


void tileengine_render(void *component, void *args)
{
	tileengine_t *te = (tileengine_t*) component;
	graphics_t *graphics = (graphics_t*) args;
	int screen_x = te->screen_x;
	int screen_y = te->screen_y;
	int screen_width = te->screen_width;
	int screen_height = te->screen_height;

	tilemap_t *tilemap = te->current_tilemap;
	tilepool_t *pool = tilemap->pool;

	uint16_t 
	int nx = screen_width - screen_x < screen_width/pool->_tw+1;
	int ny = screen_height/pool->_th+1;


	uint16_t *tilestruct = tilemap->tilestruct;

	int c;
	rect_t src;
	rect_t dst;

	
	for(int i=0;i<ny;i++)
	{
		for(int j=0;j<nx;j++)
		{
			c = *(tilestruct+(i*tilemap->size_y+j));
			src.x = pool->_xoffset+pool->_tw*(c%tilemap->size_x);
			src.y = pool->_yoffset+pool->_th*(c/tilemap->size_y);
			src.w = pool->_tw;
			src.h = pool->_th;
			dst.x = j*src.w;
			dst.y = i*src.h;
			blit(pool->_tilemap, &graphics->screen, &src, &dst);

		}
	}

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
