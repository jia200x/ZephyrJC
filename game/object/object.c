#include "object.h"
#include "scenario.h"
#include "eventdispatcher.h"
#include <stdio.h>
#include "graphics.h"

void object_init(scenario_t *scenario, object_t *obj)
{
	obj->scenario = scenario;
	linked_list_init(&obj->components);
}

void add_component(object_t *obj, struct component_t *c)
{
	linked_list_add(&obj->components, (void*) c);
}
void register_object(object_t *obj, scenario_t *scenario)
{
	scenario_add_object(scenario,obj);
}
