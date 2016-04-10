#ifndef GAME_SCEN_MAN_H
#define GAME_SCEN_MAN_H

#include "sys.h"
#include "core.h"
#include "scenario.h"

typedef struct scenario_manager_t
{
	scenario_t *current_scenario;
	core_t *core;
	linked_list_t scenarios;

	scenario_t *_head;
} scenario_manager_t;

void sm_init(scenario_manager_t *sm, core_t *core);
void sm_add_scenario(scenario_manager_t *sm, scenario_t *scenario);
void sm_process(scenario_manager_t *sm);
void sm_render(scenario_manager_t *sm);

#endif

