#include "component/transform.h"
#include "eventdispatcher.h"

component_t *transform_create(object_t *obj)
{
	component_t *c;
	c = malloc(sizeof(transform_t));
	component_init(c, 0, obj);
	transform_init(c, obj);
	register_event_callback(&obj->scenario->ed, EV_UPDATE, obj, &transform_process);
	return c;
}
void transform_init(component_t *c, object_t *obj)
{
	transform_t *t = (transform_t*) c;

	t->x = 0;
	t->y = 0;
	t->x_speed = 0;
	t->y_speed = 0;
}

void transform_process(void *c, void *args)
{
	transform_t *t = (transform_t*) c;
	t->x += t->x_speed;
	t->y += t->y_speed;
	printf("Nice... I'm being called from here\n");
}

