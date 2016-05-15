#ifndef GAME_SCENARIO_H
#define GAME_SCENARIO_H

#include <inttypes.h>
#include "sys.h"
#include "eventdispatcher.h"
#include "core.h"


typedef struct object_t object_t;
typedef struct zephyrjc_t zephyrjc_t;
/**
 * \brief A scenario.
 *
 * This struct represent a scenario
 */
typedef struct scenario_t
{
	linked_list_t objects; /**< List of objects */
	event_dispatcher_t ed; /**< Event dispatcher of current scenario */
	/*Access to core*/
	graphics_t *graphics; /**< Pointer to graphics controller */
	core_t *core;
} scenario_t;

/**
 * Create a scenario
 *
 * @param zjc Pointer to main engine.
 * @return Pointer to new scenario
 */
scenario_t *scenario_create(zephyrjc_t *zjc);

/**
 * Scenario process. Triggers EV_UPDATE event through event dispatcher.
 * @param scenario Scenario to trigger event
 */
void scenario_process(scenario_t *scenario);

/**
 * Scenario render. Triggers EV_RENDER event through event dispatcher.
 * @param scenario Scenario to trigger event
 */
void scenario_render(scenario_t *scenario);

/**
 * Register a scenario in main engine.
 * @param scenario Scenario to register
 * @param zjc Pointer to main engine
 */
void register_scenario(scenario_t *scenario, zephyrjc_t *zjc);

/**
 * Register object in scenario
 *
 * @param scenario Scenario where the object will be added.
 * @param obj Object to be registered.
 */
void scenario_add_object(scenario_t *scenario, object_t *obj);

#endif
