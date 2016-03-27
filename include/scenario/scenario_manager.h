#ifndef GAME_SCEN_MAN_H
#define GAME_SCEN_MAN_H

#include "core/graphics.h"
typedef struct scenario_manager_t
{
	scenario_t *current_scenario;
	core_t *core;
	link_list_t scenarios;

	scenario_t *_head;
} scenario_manager_t;

void init(scenario_manager_t *sm);
void add_scenario(scenario_manager_t *sm, scenario_t *sm);
void process(scenario_manager_t *sm);
void render(scenario_manager_t *sm);

#endif

