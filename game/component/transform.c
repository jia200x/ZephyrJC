#include "component/transform.h"

void transform_init(transform_t *t)
{
	t->x = 0;
	t->y = 0;
	t->x_speed = 0;
	t->y_speed = 0;
}

void transform_process(transform_t *t)
{
	t->x += t->x_speed;
	t->y += t->y_speed;
}
