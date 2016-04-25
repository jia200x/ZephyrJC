#include "object.h"
#include "scenario.h"
#include "eventdispatcher.h"
#include <stdio.h>
#include "graphics.h"

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
void register_object(object_t *obj, scenario_t *scenario)
{
	scenario_add_object(scenario,obj);
}
