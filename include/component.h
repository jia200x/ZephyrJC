#ifndef COMPONENT_H
#define COMPONENT_H
#include "object.h"

/**
 * \brief Base component struct.
 *
 *		Should be extended by components.
 */
typedef struct component_t
{
	object_t *obj; /**< Pointer to object holding the component */
	uint8_t type; /**< Type of component (e.g Collision, Sprite, etc) */
} component_t;

/**
 * Create a component.
 * 
 * \param type Type of component
 * \param obj Pointer to object holding the component
 * \param size Size of the component. (Pass sizeof of child component)
 * \return Pointer to created component
 */
static inline component_t *component_create(uint8_t type, object_t *obj, size_t size)
{
	component_t *c = malloc(size);
	c->obj = obj;
	c->type = type;
	add_component(obj, c);
	return c;
}
#endif
