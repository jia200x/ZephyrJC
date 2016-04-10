#include "scenario/scenario_manager.h"
#include "core/graphics.h"

int main(void)
{
	core_t core;
	//
	//Add scenario manager
	scenario_manager_t sm;
	sm_init(&sm, &core);

	//Add test scenario
	scenario_t test_scenario;
	scenario_init(&test_scenario, NULL, NULL, NULL);

	sm.current_scenario = &test_scenario;

    object_t obj;
	object_init(&obj,NULL,NULL);

	scenario_add_object(&test_scenario, &obj);
	while(1)
	{
		//core.input();
		sm_process(&sm);
		sm_output(&sm);
	}
}
