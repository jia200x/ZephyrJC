#ifndef CORE_GRAPHICS_H
#define CORE_GRAPHICS_H

/* Base struct for a layer */
typedef struct layer_t
{
	uint8_t depth;
} layer_t;

/* Struct for handling color */

typedef struct color_t
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} color_t;

/* Only one graphics_t struct, and handles all information of */
typedef struct graphics_t
{
} graphics_t;

void graphics_init(void); // Init graphics
void blit(layer_t source, layer_t dest, int source_x, int  source_y); // Draw source in dest, reading source from source_x,source_y
void fill(layer_t layer, color_t color); //Fill layer with color
void create_layer(int width, int height); //Create a layer (need more params?)
void screen_flip(void); //Flip screen (page flipping)
void screen_update(void); //Update screen
void 


#endif
