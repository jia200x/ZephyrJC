#ifndef GAME_SCENARIO_H
#define GAME_SCENARIO_H

#include <inttypes.h>
#include "sys.h"
#include "object.h"
#include "eventdispatcher.h"


typedef struct scenario_manager_t scenario_manager_t;
typedef struct scenario_t
{
	linked_list_t objects;
	event_dispatcher_t ed;
	/*Access to core*/
} scenario_t;

void scenario_init(scenario_t *scenario);

//Generic
void scenario_setup(scenario_t *scenario);
void scenario_process(scenario_t *scenario);
void scenario_render(scenario_t *scenario);

void register_scenario(scenario_t *scenario, scenario_manager_t *sm);
void scenario_add_object(scenario_t *scenario, object_t *obj);

#endif
