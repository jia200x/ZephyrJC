#include "zephyrjc.h"
#include "scenario.h"
#include "SDL2/SDL.h"
#include "core/timer.h"
#include "core/keyboard.h"

const int FPS = 30;

zephyrjc_t *zephyrjc_init(void)
{
	zephyrjc_t *zjc = (zephyrjc_t*) malloc(sizeof(zephyrjc_t));
	zjc->current_scenario = NULL;
	linked_list_init(&zjc->scenarios);
	core_init(&zjc->core);
	return zjc;
}

void zephyrjc_add_scenario(zephyrjc_t *zjc, scenario_t *scenario)
{
	linked_list_add(&zjc->scenarios, (void*) scenario);
	zjc->current_scenario = scenario;
}

void zjc_input(zephyrjc_t *zjc)
{
	core_input(&zjc->core);
	keyboard_process(&zjc->core.keyboard);
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
	LTimer fpsTimer, capTimer;
	timer_zero(&fpsTimer);

	float avgFps;
	int framecount = 0;
	int ticks;
	while(1)
	{
		timer_zero(&capTimer);
		avgFps = framecount++/(timer_getTicks(&fpsTimer)/1000.f);
		avgFps = avgFps > 20000 ? 0 : avgFps;

		zjc_input(zjc);
		zjc_process(zjc);
		zjc_render(zjc);
	
		if(zjc->core.flags & FLAG_EXIT)
			break;
		ticks = timer_getTicks(&capTimer);
		if(ticks < TICKS_PER_FRAME)
		{
			timer_delay(TICKS_PER_FRAME - ticks);
		}
	}
}

void zephyrjc_init_graphics(zephyrjc_t *zjc, int width, int height, int bpp)
{
	graphics_init(&zjc->core.graphics, width, height, bpp, NULL);
}

void zephyrjc_keyboard_init(zephyrjc_t *zjc)
{
	keyboard_init(&zjc->core.keyboard);
}
