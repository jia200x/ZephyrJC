#include "scenario_manager.h"
#include "graphics.h"

int main(void)
{
	graphics_t graphics;
	graphics_init(&graphics, 640, 480, 32, NULL);
	core_t core;
	
	//Add scenario manager
	scenario_manager_t sm;
	sm_init(&sm, &core);

	//Add test scenario
	scenario_t test_scenario;
	test_scenario.graphics = &graphics;
	scenario_init(&test_scenario);

	sm.current_scenario = &test_scenario;

    object_t obj;
	object_init(&test_scenario, &obj);

	scenario_add_object(&test_scenario, &obj);
	while(1)
	{
		//core.input();
		sm_process(&sm);
		sm_render(&sm);
	}
}
