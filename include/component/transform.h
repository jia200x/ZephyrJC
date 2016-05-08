#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "component.h"

#define COMPONENT_TRANSFORM (2)
/**
 * \brief Transform component
 */
typedef struct transform_t
{
	component_t base; /**< Inherits from component. */
	float x; /**< x of object */
	float y; /**< y of object */
	float x_speed; /**< x speed of object */
	float y_speed; /**< y speed of object */

} transform_t;

typedef struct object_t object_t;

/**
 * Create a transform component and add to object
 * @param obj Object to add component
 * @return Pointer to new transform component
 */
component_t *transform_create(object_t *obj);


/**
 * Registered callback to event EV_UPDATE
 *
 * Process physics
 * 
 * @param c Pointer to component
 * @param args Args from event dispatcher
 */
void transform_process(void *c, void *args);

#endif
