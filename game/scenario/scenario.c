#include "scenario.h"
#include "scenario_manager.h"
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
void register_scenario(scenario_t *scenario, scenario_manager_t *sm)
{
	sm_add_scenario(sm, scenario);
}
void scenario_render(scenario_t *scenario)
{
	dispatch_event(&scenario->ed, EV_RENDER, NULL);
}
void scenario_add_object(scenario_t *scenario, object_t *obj)
{
	linked_list_add(&scenario->objects, (void*) obj);
}
