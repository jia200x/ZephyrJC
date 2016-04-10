#ifndef GAME_SCENARIO_H
#define GAME_SCENARIO_H

#include "types.h"
#include <inttypes.h>
#include "sys.h"


struct scenario_t_
{
	linked_list_t *objects;
	int32_t view_x;
	int32_t view_y;

	void (*setup)(scenario_t *scenario);
	void (*process)(scenario_t *scenario);
	void (*render)(scenario_t *scenario);
};

void scenario_init(scenario_t *scenario, void (*setup)(scenario_t*), void (*process)(scenario_t*), void (*render)(scenario_t*, core_t*));

//Generic
void scenario_setup(scenario_t *scenario);
void scenario_process(scenario_t *scenario);
void scenario_render(scenario_t *scenario, core_t *core);

void register_scenario(scenario_t *scenario, scenario_manager_t *sm);
void scenario_add_object(scenario_t *scenario, object_t *obj);

#endif
