#ifndef GAME_SCEN_MAN_H
#define GAME_SCEN_MAN_H

#include "sys.h"
#include "core.h"
#include "scenario.h"

/**
 * \brief Scenario Manager
 */
typedef struct scenario_manager_t
{
	scenario_t *current_scenario; /**< Current scenario */
	core_t *core; /**< TODO: Implement*/
	linked_list_t scenarios; /**< List of scenarios */

	scenario_t *_head; /**< Not used*/
} scenario_manager_t;

/**
 * Init scenario manager
 *
 * @param sm Pointer to scenario manager
 * @param core Pointer to core (not used yet!)
 */
void sm_init(scenario_manager_t *sm, core_t *core);




/**
 * Add a scenario to Scenario Manager
 *
 * @param sm Pointer to scenario manager
 * @param scenario Scenario to add
 */
void sm_add_scenario(scenario_manager_t *sm, scenario_t *scenario);




/**
 * Call current scenario process function
 *
 * @param sm Pointer to scenario manager
 */
void sm_process(scenario_manager_t *sm);




/**
 * Call current scenario render function
 *
 * @param sm Pointer to scenario manager
 */
void sm_render(scenario_manager_t *sm);

#endif

