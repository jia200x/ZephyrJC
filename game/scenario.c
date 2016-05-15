#include "scenario.h"
#include "zephyrjc.h"
#include "core.h"
#include "eventdispatcher.h"

scenario_t *scenario_create(zephyrjc_t *zjc)
{
	scenario_t *s = (scenario_t*) malloc(sizeof(scenario_t));	
	s->graphics = &zjc->core.graphics;
	s->core = &zjc->core;
	linked_list_init(&s->objects);
    event_dispatcher_init(&s->ed);
	return s;
}

void scenario_process(scenario_t *scenario)
{
	dispatch_event(&scenario->ed, EV_UPDATE, NULL);
}

void register_scenario(scenario_t *scenario, zephyrjc_t *zjc)
{
	zephyrjc_add_scenario(zjc, scenario);
}

void scenario_render(scenario_t *scenario)
{
	color_t color;
	color.r = 0;
	color.g = 0;
	color.b = 0;

	screen_fill(&scenario->graphics->screen, &color);
	dispatch_event(&scenario->ed, EV_RENDER, (void*) scenario->graphics);
	screen_update(scenario->graphics);
}

void scenario_add_object(scenario_t *scenario, object_t *obj)
{
	linked_list_add(&scenario->objects, (void*) obj);
}
