#include "zephyrjc.h"
#include "scenario.h"

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
	while(1)
	{
		//core.input();
		zjc_process(zjc);
		zjc_render(zjc);
	}
}
void zephyrjc_init_graphics(zephyrjc_t *zjc, int width, int height, int bpp)
{
	graphics_init(&zjc->core.graphics, width, height, bpp, NULL);
}
