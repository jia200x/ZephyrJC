#include "component/transform.h"
#include "eventdispatcher.h"
#include "core.h"

component_t *transform_create(object_t *obj)
{
	component_t *c = component_create(COMPONENT_TRANSFORM, obj, sizeof(transform_t));
	transform_t *t = (transform_t*) c;
	t->x = 90;
	t->y = 0;
	t->x_speed = 0;
	t->y_speed = 0;
	register_event_callback(&c->obj->scenario->ed, EV_UPDATE, c, &transform_process);
	return c;
}

void transform_process(void *c, void *args)
{
	transform_t *t = (transform_t*) c;
	t->x += t->x_speed;
	t->y += t->y_speed;
	core_t *core = (core_t*) args;
	printf("Release keyboard: %i\n", keyboard_get_keyreleased(&core->keyboard, VK_LEFT));
}

