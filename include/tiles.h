#ifndef TILES_H
#define TILES_H

#include "core.h"
#include <inttypes.h>
#include "component.h"

/**
 * \brief Tile pool.
 *
 * Represents the strip of tiles (a.k.a source of tiles)
 */
typedef struct tilepool_t
{
	spriteBuffer_t *_tilemap; /**< Pointer to strip of tiles*/
	uint16_t _tw; /**< Tile width*/
	uint16_t _th; /**< Tile height*/
	uint16_t _xoffset; /** X offset of strip */
	uint16_t _yoffset; /** Y offset of strip */
} tilepool_t;

/**
 * \brief Tile map
 *
 * Represents a tile map.
 */
typedef struct tilemap_t
{
	tilepool_t *pool; /**< Source of tiles */
	uint16_t *tilestruct; /**< Tile map*/
	int size_x; /**< Number of columns in tile map */
	int size_y; /**< Number of rows in tile map */
	uint8_t depth; /**< Depth of current tile map */
} tilemap_t;

/** \brief Tile engine component
 */
typedef struct tileengine_t
{
	component_t base;i /**< Inherits from component */
	linked_list_t tilemaps; /**< List of tile maps*/
	rect_t source; /**< Area of tilemap to draw*/
} tileengine_t;


/**
 * Callback of component init
 *
 * @param c Pointer to tileengine base
 * @param args Arguments for initialization
 */
void tileengine_init(component_t *c, void **args);

/**
 * Callback of render subscription.
 *
 * Draws the list of tilemaps.
 *
 * @param component Pointer to tile engine
 * @param Args from event dispatcher
 */
void tileengine_render(void *component, void *args);

/**
 * Create a tilepool
 *
 * @param filename File name of tile pool image
 * @param tw Tile width of tile pool
 * @param th Tile height of tile pool
 * @param xoff X offset of tile pool
 * @param yoff Y offset of tile pool
 */
tilepool_t *create_tilepool(char *filename, uint16_t tw, uint16_t th, uint16_t xoff, uint16_t yoff);

/**
 * Create a tile map
 *
 * @param Pointer to tile pool
 * @param tilestruct Pointer to tilemap
 * @param size_x Number of columns of tile map
 * @param size_y Number of rows of tile map
 * @param depth Depth of tile map.
 */
tilemap_t *create_tilemap(tilepool_t *pool, uint16_t *tilestruct, int size_x, int size_y, uint8_t depth);
#endif
