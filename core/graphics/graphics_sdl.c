#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "graphics.h"
#include <stdio.h>


void graphics_init(graphics_t *graphics, int width, int height, int bpp, void *args)
{
	SDL_Window *window;
	SDL_Init( SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );

	if( window == NULL )
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
	}
	
	graphics->window = (void*) window;
	graphics->screen._sprite = (void*) SDL_GetWindowSurface(window);
}

void blit(spriteBuffer_t *source, spriteBuffer_t *dest, int source_x, int  source_y, int width, int height, int dest_x, int dest_y)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;
	srcrect.x = source_x;
	srcrect.y = source_y;
	srcrect.w = width;
	srcrect.h = height;
	dstrect.x = dest_x;
	dstrect.y = dest_y;
	dstrect.w = width;
	dstrect.h = height;

	SDL_BlitSurface((SDL_Surface*) source->_sprite, &srcrect, (SDL_Surface*) dest->_sprite, &dstrect);
}


void graphics_free(void)
{
	SDL_Quit();
}
void screen_fill(spriteBuffer_t *buffer, color_t *color)
{
	SDL_Surface *screenSurface = (SDL_Surface*) buffer->_sprite;
	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, color->r, color->g, color->b ) );	
}

void screen_update(graphics_t *graphics)
{
	SDL_UpdateWindowSurface((SDL_Window*) graphics->window); 
	SDL_Delay( 5000 );
}

void load_bmp(spriteBuffer_t *sprite, char* filename)
{
	sprite->_sprite = (void*) IMG_Load(filename);
}
