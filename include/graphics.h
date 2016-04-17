#ifndef CORE_GRAPHICS_H
#define CORE_GRAPHICS_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>


/* Base struct for a layer */
typedef struct spriteBuffer_t
{
	void *_sprite;
} spriteBuffer_t;

/* Struct for handling color */

typedef struct color_t
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} color_t;

typedef struct rect_t
{
	int x;
	int y;
	int w;
	int h;
} rect_t;

/* Only one graphics_t struct, and handles all information of */
typedef struct graphics_t
{
	int d;
	spriteBuffer_t  screen;
	void *window;
} graphics_t;

void graphics_init(graphics_t *graphics, int width, int height, int bpp, void *args);
void load_bmp(spriteBuffer_t *sprite, char* filename); //Create a layer (need more params?)
int blit(spriteBuffer_t *source, spriteBuffer_t *dest, rect_t *rsrc, rect_t *rdst);
void screen_fill(spriteBuffer_t *buffer, color_t *color); //Fill layer with color
spriteBuffer_t *create_sprite(void); //Create a layer (need more params?)
void screen_update(graphics_t *graphics);
void graphics_free(void);


#endif
