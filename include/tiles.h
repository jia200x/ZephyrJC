#ifndef TILES_H
#define TILES_H

#include "core.h"
#include <inttypes.h>

typedef struct tilepool_t
{
	spriteBuffer_t *_tilemap;
	uint16_t _tw;
	uint16_t _th;
	uint16_t _xoffset;
	uint16_t _yoffset;
} tilepool_t;

typedef struct tilemap_t
{
	tilepool_t *pool;
	uint16_t **tilestruct;
	int size_x;
	int size_y;
	uint8_t depth;
} tilemap_t;

typedef struct tileengine_t
{
	component_t base;
	linked_list_t *tilemaps;
	tilemap_t *current_tilemap;
	int x;
	int y;
	int width;
	int height;
} tileengine_t;


void tilemap_init(component_t *c, void **args);
void tilemap_render(void *component, void *args);
int tilemap_load_img(void);
int tilemap_load_data(void);
tilepool_t *load_tilepool(char *filename, uint16_t tw, uint16_t th, uint16_t xoff, uint16_t yoff);

#endif
