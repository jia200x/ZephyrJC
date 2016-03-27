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
	sm->current_scenario->process();
}
void render(scenario_manager_t *sm)
{
	/* TODO: To be done... (Ya pue Patricio!)
	self.core.graphics.screen.fill((0,0,0))
	*/

	sm->current_scenario->render(sm->core)
		/*TODO: Culpa de Patricio
	self.core.graphics.flip()
	*/
}
#endif
