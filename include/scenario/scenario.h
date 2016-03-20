
#ifndef GAME_SCENARIO_H
#define GAME_SCENARIO_H
typedef struct scenario_t
{
	linked_list_t *objects;
	uint32_t view_x;
	uint32_t view_y;
} scenario_t;

void process(scenario_t *scenario);
void register_scenario(scenario_t *scenario, scenario_manager_t *sm);
void render(scenario_t *scenario, core_t *core);

#endif
