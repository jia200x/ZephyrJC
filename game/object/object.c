#include "object/object.h"

void init(object_t *obj)
{
	obj->id = 0;
	obj->x = 0;
	obj->y = 0;
	obj->x_speed = 0;
	obj->y_speed = 0;
	obj->sprite = NULL;
}

void process(object_t *obj)
{
	obj->x += obj->x_speed;
	obj->y += obj->y_speed;
}

void register_object(object_t *obj, scenario_t *scenario)
{
	scenario->add_object(obj);
}
