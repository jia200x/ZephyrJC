#include "scenario_manager.h"
#include "scenario.h"

void sm_init(scenario_manager_t *sm, core_t *core)
{
	sm->current_scenario = NULL;
	linked_list_init(&sm->scenarios);
	sm->core = core;
}
void sm_add_scenario(scenario_manager_t *sm, scenario_t *scenario)
{
	linked_list_add(&sm->scenarios, (void*) scenario);
	sm->current_scenario = scenario;
}
void sm_process(scenario_manager_t *sm)
{
	scenario_process(sm->current_scenario);
}
void sm_render(scenario_manager_t *sm)
{
	scenario_render(sm->current_scenario);
}
