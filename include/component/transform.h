#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "component.h"

typedef struct transform_t
{
	component_t base;
	float x;
	float y;
	float x_speed;
	float y_speed;

} transform_t;

typedef struct object_t object_t;
void transform_init(component_t *c, void  **args);
void transform_process(void *c, void *args);

#endif
