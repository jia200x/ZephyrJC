#include "scenario/scenario_manager.h"
#include "core/graphics.h"

int main(void)
{
	core_t core;
	scenario_manager_t sm;

	while(1)
	{
		//core.input();
		sm.process();
		sm.output();
	}
}
