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

int blit(spriteBuffer_t *source, spriteBuffer_t *dest, rect_t *rsrc, rect_t *rdst)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	SDL_Rect *final_src = NULL;
	SDL_Rect *final_dst = NULL;

	if(rsrc != NULL)
	{
		srcrect.x = rsrc->x;
		srcrect.y = rsrc->y;
		srcrect.w = rsrc->w;
		srcrect.h = rsrc->h;
		final_src = &srcrect;
	}
	if(rdst != NULL)
	{
		dstrect.x = rdst->x;
		dstrect.y = rdst->y;
		dstrect.w = rdst->w;
		dstrect.h = rdst->h;
		final_dst = &dstrect;
	}


	SDL_BlitSurface((SDL_Surface*) source->_sprite, final_src, (SDL_Surface*) dest->_sprite, final_dst);
	return 0;
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
}

spriteBuffer_t *create_sprite(void)
{
	return (spriteBuffer_t*) malloc(sizeof(spriteBuffer_t));
}

void load_bmp(spriteBuffer_t *sprite, char* filename)
{
	sprite->_sprite = (void*) IMG_Load(filename);
}
int delete_sprite(spriteBuffer_t *sprite);
