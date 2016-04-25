#ifndef TILES_H
#define TILES_H

#include "core.h"
#include <inttypes.h>
#include "component.h"

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
	uint16_t *tilestruct;
	int size_x;
	int size_y;
	uint8_t depth;
} tilemap_t;

typedef struct tileengine_t
{
	component_t base;
	linked_list_t tilemaps;
	tilemap_t *current_tilemap;
	int screen_x;
	int screen_y;
	int screen_width;
	int screen_height;
} tileengine_t;


void tileengine_init(component_t *c, void **args);
void tileengine_render(void *component, void *args);
tilepool_t *create_tilepool(char *filename, uint16_t tw, uint16_t th, uint16_t xoff, uint16_t yoff);
tilemap_t *create_tilemap(tilepool_t *pool, uint16_t *tilestruct, int size_x, int size_y, uint8_t depth);
#endif
