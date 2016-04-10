#ifndef GAME_SCEN_MAN_H
#define GAME_SCEN_MAN_H

#include "types.h"
#include "sys.h"

struct scenario_manager_t_
{
	scenario_t *current_scenario;
	core_t *core;
	linked_list_t scenarios;

	scenario_t *_head;
};

void sm_init(scenario_manager_t *sm, core_t *core);
void sm_add_scenario(scenario_manager_t *sm, scenario_t *scenario);
void sm_process(scenario_manager_t *sm);
void sm_render(scenario_manager_t *sm);
void sm_output(scenario_manager_t *sm);

#endif

