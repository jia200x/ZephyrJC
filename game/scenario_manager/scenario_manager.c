#ifndef SCENARIO_MANAGER_H
#define SCENARIO_MANAGER_H
#include "scenario/scenario-manager.h"

void init(scenario_manager_t *sm, core_t *core)
{
	sm->current_scenario = NULL;
	linked_list_init(&sm->scenarios);
	sm->core = core;
}
void add_scenario(scenario_manager_t *sm, scenario_t *scenario)
{
	linked_list_add(&sm->scenarios, (void*) scenario);
	sm->current_scenario = scenario;
}
void process(scenario_manager_t *sm)
{
	scenario_process(sm->current_scenario, sm->core->input_state);
}
void sm_render(scenario_manager_t *sm)
{
	scenario_render(sm->current_scenario, sm->core)
}
