#include "object.h"
#include "scenario.h"
#include "eventdispatcher.h"
#include <stdio.h>

void dummy_test(void *obj, void *nothing)
{
	(void) obj;
	(void) nothing;
	printf("Dummy but registered!\n");
}

void dummy_render(void *obj, void *nothing)
{
	(void) obj;
	(void) nothing;
	printf("Dummy renderer but registered!\n");
}

void object_init(scenario_t *scenario, object_t *obj)
{
	register_event_callback(&scenario->ed, EV_UPDATE, obj, &dummy_test);
	register_event_callback(&scenario->ed, EV_RENDER, obj, &dummy_render);
}
void add_component(object_t *obj, component_t *component)
{
	linked_list_add(&obj->components, (void*) component);
}
void register_object(object_t *obj, scenario_t *scenario)
{
	scenario_add_object(scenario,obj);
}
