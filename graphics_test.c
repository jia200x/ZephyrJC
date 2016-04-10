#include <stdio.h>
#include "graphics.h"

int main(void)
{
	graphics_t graphics;
	graphics_init(&graphics, 640, 480, 32, NULL);

	spriteBuffer_t sprite;
	load_bmp(&sprite, "mario.png");
	color_t color;

	color.r = 0;
	color.g = 0;
	color.b = 0;

	screen_fill(&graphics.screen, &color);
	blit(&sprite, &graphics.screen, 0,0,500,500,0,60);
	screen_update(&graphics);
	graphics_free();
	return 0;
}
