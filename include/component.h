#ifndef COMPONENT_H
#define COMPONENT_H
#include "object.h"

typedef struct component_t
{
	object_t *obj;
	uint8_t type;
} component_t;

static inline int component_init(component_t *c, uint8_t type, object_t *obj)
{
	c->obj = obj;
	c->type = type;
	return 0;
}
#endif
