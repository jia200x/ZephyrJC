#include "object.h"
#include "scenario.h"
#include "eventdispatcher.h"
#include <stdio.h>
#include "graphics.h"
#include "component.h"

object_t *object_create(scenario_t *scenario)
{
	object_t *obj = (object_t*) malloc(sizeof(object_t));
	obj->scenario = scenario;
	linked_list_init(&obj->components);
	scenario_add_object(scenario, obj);
	return obj;
}

void add_component(object_t *obj, struct component_t *c)
{
	linked_list_add(&obj->components, (void*) c);
}

component_t *get_component_by_type(object_t *obj, uint8_t type)
{
	ll_node_t *node = linked_list_get_head_obj(&obj->components);
	component_t *c = NULL;
	while(node)
	{
		c = (component_t*) node->data;
		if(c->type == type)
			return c;
		node = node->next;
	}
	return NULL;
}

void register_object(object_t *obj, scenario_t *scenario)
{
	scenario_add_object(scenario,obj);
}
