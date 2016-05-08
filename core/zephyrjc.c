#include "zephyrjc.h"
#include "scenario.h"
#include "SDL2/SDL.h"

const int FPS = 30;

zephyrjc_t *zephyrjc_init(void)
{
	zephyrjc_t *zjc = (zephyrjc_t*) malloc(sizeof(zephyrjc_t));
	zjc->current_scenario = NULL;
	linked_list_init(&zjc->scenarios);
	return zjc;
}

void zephyrjc_add_scenario(zephyrjc_t *zjc, scenario_t *scenario)
{
	linked_list_add(&zjc->scenarios, (void*) scenario);
	zjc->current_scenario = scenario;
}

void zjc_process(zephyrjc_t *zjc)
{
	scenario_process(zjc->current_scenario);
}

void zjc_render(zephyrjc_t *zjc)
{
	scenario_render(zjc->current_scenario);
}

void zephyrjc_start(zephyrjc_t *zjc)
{
	int TICKS_PER_FRAME = 1000/FPS;
	int fpsTimer = SDL_GetTicks();
	int capTimer = SDL_GetTicks();

	float avgFps;
	int framecount = 0;
	int ticks;
	while(1)
	{
		capTimer = SDL_GetTicks();
		avgFps = framecount++/((SDL_GetTicks() - fpsTimer)/1000.f);
		avgFps = avgFps > 20000 ? 0 : avgFps;

		//core.input();
		zjc_process(zjc);
		zjc_render(zjc);
	
		ticks = SDL_GetTicks()-capTimer;
		if(ticks < TICKS_PER_FRAME)
		{
			SDL_Delay(TICKS_PER_FRAME - ticks);
		}
	}
}

void zephyrjc_init_graphics(zephyrjc_t *zjc, int width, int height, int bpp)
{
	graphics_init(&zjc->core.graphics, width, height, bpp, NULL);
}
