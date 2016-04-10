#include "scenario/scenario.h"

void scenario_init(scenario_t *scenario)
{
	linked_list_init(scenario->objects);
}


void scenario_process(scenario_t *scenario, input_state_t *input_state)
{
	dispatch_event(scenario, EV_UPDATE, (void*) input_state);
}
void register_scenario(scenario_t *scenario, scenartio_manager_t *sm)
{
	sm->add_scenario(self)
}
void render(scenario_t *scenario, core_t *core)
{
	dispatch_event(scenario, EV_RENDER, (void*) core->graphics);
}
void add_object(scenario_t *scenario, object_t *obj)
{
	linked_list_add(scenario->objects, (void*) obj);
}
