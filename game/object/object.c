#include "object/object.h"

void dummy_test(object_t *obj, void *nothing)
{
	(void) obj;
	(void) nothing;
	printf("Hello!");
}
void object_init(scenario_t *scenario, object_t *obj)
{
	register_event_callback(scenario, EV_UPDATE, NULL);
}
void add_component(object_t *obj, component_t *component)
{
	linked_list_add(obj->components, (void*) component);
}
void register_object(object_t *obj, scenario_t *scenario)
{
	scenario->add_object(obj);
}
