#ifndef GAME_OBJECT_T
#define GAME_OBJECT_T

#include <inttypes.h>
#include "sys.h"
#include "graphics.h"
#include "scenario.h"

typedef struct component_t component_t;

/**
 * \brief Base object. All objects must inherit from this one
 */
typedef struct object_t
{
	int id; /**< Id of object.*/
	linked_list_t components; /**< Linked list of components*/
	scenario_t *scenario; /** Pointer to scenario containing the object */
} object_t;


/**
 * Create a new object
 * 
 * @param scenario Pointer scenario containg the object.
 * @return Pointer to new object
 */
object_t*object_create(scenario_t *scenario);

/**
 * Add component to object
 *
 * @param obj Object containing the component.
 * @param c Component to add.
 */
void add_component(object_t *obj, struct component_t *c);

/**
 * Register object in scenario
 *
 * @param obj Object to register.
 * @param scenario Scenario containing the object.
 */
void register_object(object_t *obj, scenario_t *scenario);

#endif
