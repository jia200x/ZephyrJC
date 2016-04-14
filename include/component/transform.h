#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "component.h"

typedef struct transform_t
{
	component_t base;
	int32_t x;
	int32_t y;
	int32_t x_speed;
	int32_t y_speed;

} transform_t;

typedef struct object_t object_t;
void transform_init(component_t *t, void  **args);
void transform_process(void *c, void *args);

#endif
