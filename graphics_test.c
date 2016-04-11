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

	rect_t src;
	src.x = 30;
	src.y = 30;
	src.w = 200;
	src.h = 200;
	screen_fill(&graphics.screen, &color);
	blit(&sprite, &graphics.screen, &src, &src);
	screen_update(&graphics);
	graphics_free();
	return 0;
}
