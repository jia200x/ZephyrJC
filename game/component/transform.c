#include "component/transform.h"
#include "eventdispatcher.h"

void transform_init(component_t *c, void  **args)
{
	transform_t *t = (transform_t*) c;
	t->x = 0;
	t->y = 0;
	t->x_speed = 0;
	t->y_speed = 0;
	register_event_callback(&c->obj->scenario->ed, EV_UPDATE, c->obj, &transform_process);
}

void transform_process(void *c, void *args)
{
	transform_t *t = (transform_t*) c;
	t->x += t->x_speed;
	t->y += t->y_speed;
	printf("Nice... I'm being called from here\n");
}

