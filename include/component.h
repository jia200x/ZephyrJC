#ifndef COMPONENT_H
#define COMPONENT_H
#include "object.h"

typedef struct component_t
{
	object_t *obj;
	uint8_t type;
} component_t;

static inline component_t *component_create(uint8_t type, object_t *obj, size_t size, void (*cb)(component_t*, void **args), void **args)
{
	component_t *c = malloc(size);
	c->obj = obj;
	c->type = type;
	cb(c, args);
	add_component(obj, c);
	return c;
}
#endif
