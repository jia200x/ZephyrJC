#ifndef GAME_OBJECT_T
#define GAME_OBJECT_T

#include <inttypes.h>
#include "component.h"
#include "sys.h"
#include "graphics.h"

typedef struct object_t
{
	int id;
	linked_list_t components;
	spriteBuffer_t test;
} object_t;

typedef struct scenario_t scenario_t;

void object_init(scenario_t *scenario, object_t *obj);
void add_component(object_t *obj, component_t *component);
void register_object(object_t *obj, scenario_t *scenario);

#endif
