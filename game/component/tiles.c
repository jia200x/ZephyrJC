
#include "tiles.h"

void tilemap_render(core_t *core, tilemap_t *tilemap, int x, int y, int width, int height)
{
	int nx = width/tilemap->_tw+1;
	int ny = height/tilemap->_th+1;

	int c;
	
	for(int i=0;i<ny;i++)
	{
		for(int j=0;j<nx;j++)
		{
			c = *(tilestruct+(i*tilemap->_num_tiles_y+j));
			blit(tilemap->_tilemap, core->graphics->screen, tilemap->_xoffset+tilemap->_tw*(c%tilemap->_num_tiles_x),tilemap->_yoffset+tilemap->_th*(c/tilemap->_num_tiles_y),,);

		}
	}

}
