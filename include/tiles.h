#ifndef TILES_H
#define TILES_H

#include "core.h"

struct tilemap_t_
{
	spriteBuffer_t _tilemap;
	uint16_t _tw;
	uint16_t _th;
	uint16_t _xoffset;
	uint16_t _yoffset;
	uint16_t _num_tiles_x;
	uint16_t _num_tiles_y;
	uint16_t **tilestruct;
};

typedef struct tilemap_t_ tilemap_t;

int tilemap_init(void);
int tilemap_load_img(void);
int tilemap_load_data(void);
void tilemap_render(core_t *core, tilemap_t *tilemap, int x, int y, int width, int height);


#endif
