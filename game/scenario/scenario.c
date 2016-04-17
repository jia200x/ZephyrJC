#include "scenario.h"
#include "zephyrjc.h"
#include "core.h"
#include "eventdispatcher.h"

void scenario_init(scenario_t *scenario)
{
	linked_list_init(&scenario->objects);
    event_dispatcher_init(&scenario->ed);
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
