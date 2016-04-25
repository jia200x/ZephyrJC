#ifndef CORE_GRAPHICS_H
#define CORE_GRAPHICS_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>


/**
 * Wrapper of buffer
 *
 * Abstraction for a layer, surface, bitmap, etc. In case of SDL, represents a pointer to a SDL Surface.
 */
typedef struct spriteBuffer_t
{
	void *_sprite; /**< Pointer to layer, surface, bitmap, or whatever.*/
} spriteBuffer_t;

/**
 * Color RGB representation
 */
typedef struct color_t
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} color_t;

/**
 * Representation of a rectangle
 */
typedef struct rect_t
{
	int x;
	int y;
	int w;
	int h;
} rect_t;

/* Only one graphics_t struct, and handles all information of */
/**
 * Graphics controller
 */
typedef struct graphics_t
{
	int d; 
	spriteBuffer_t  screen; /**< Screen (a.k.a where to draw)*/
	void *window;  /**< Pointer to window. */
} graphics_t;

/**
 * Init graphics.
 *
 * Should be called once at the beginning.
 * @param graphics Pointer to graphics controller
 * @param width Width of screen
 * @param height Height of screen
 * @param bpp Bpp of screen
 * @param args Args for init.
 */
void graphics_init(graphics_t *graphics, int width, int height, int bpp, void *args);

/**
 * Loads an image.
 *
 * TODO: Change name to load_img
 * @param sprite Sprite holding the loaded image
 * @param filename File name of image file
 */
void load_bmp(spriteBuffer_t *sprite, char* filename); //Create a layer (need more params?)


/**
 * Draw a piece of source into dest.
 *
 * @param source Source buffer
 * @param dest Destination buffer
 * @param rsrc Area of source to read from.
 * @param rdst Location of source in dest. Width and height are ignored.
 * @return Nothing useful at the moment.
 */
int blit(spriteBuffer_t *source, spriteBuffer_t *dest, rect_t *rsrc, rect_t *rdst);

/**
 * Fill a buffer with given color.
 *
 * TODO: Change name of function to SpriteBufferFill
 * @param buffer Buffer to be filled
 * @param color Color of fill.
 */
void screen_fill(spriteBuffer_t *buffer, color_t *color); //Fill layer with color

/**
 * Create a sprite
 * @return Pointer to created sprite.
 */
spriteBuffer_t *create_sprite(void); //Create a layer (need more params?)

/**
 * Refresh screen. 
 *
 * Should be called after drawing everything
 * @param graphics Pointer to graphics controller
 */
void screen_update(graphics_t *graphics);

/**
 * Not implemented yet
 */
void graphics_free(void);


#endif
