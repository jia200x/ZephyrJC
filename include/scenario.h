#ifndef GAME_SCENARIO_H
#define GAME_SCENARIO_H

#include <inttypes.h>
#include "sys.h"
#include "eventdispatcher.h"
#include "graphics.h"


typedef struct object_t object_t;
typedef struct zephyrjc_t zephyrjc_t;
typedef struct scenario_t
{
	linked_list_t objects;
	event_dispatcher_t ed;
	/*Access to core*/
	graphics_t *graphics;
} scenario_t;

scenario_t *scenario_init(zephyrjc_t *zjc);

//Generic
void scenario_setup(scenario_t *scenario);
void scenario_process(scenario_t *scenario);
void scenario_render(scenario_t *scenario);

void register_scenario(scenario_t *scenario, zephyrjc_t *zjc);
void scenario_add_object(scenario_t *scenario, object_t *obj);

#endif
