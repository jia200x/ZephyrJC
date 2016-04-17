#ifndef GAME_OBJECT_T
#define GAME_OBJECT_T

#include <inttypes.h>
#include "sys.h"
#include "graphics.h"
#include "scenario.h"

typedef struct component_t component_t;

typedef struct object_t
{
	int id;
	linked_list_t components;
	scenario_t *scenario;
} object_t;


void object_init(scenario_t *scenario, object_t *obj);
void add_component(object_t *obj, struct component_t *c);
void register_object(object_t *obj, scenario_t *scenario);

#endif
