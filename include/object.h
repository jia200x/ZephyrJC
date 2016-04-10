#ifndef GAME_OBJECT_T
#define GAME_OBJECT_T

#include "types.h"
#include <inttypes.h>

struct object_t_
{
	int id;
	link_list_t components;
};

void object_init(object_t *obj)
void add_component(object_t *obj, ll_node_t component)
void register_object(object_t *obj, scenario_t *scenario);

#endif
