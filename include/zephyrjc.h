#ifndef ZEPHYRJC_H
#define ZEPHYRJC_H

#include "sys.h"
#include "core.h"

typedef struct scenario_t scenario_t;
/**
 * \brief ZephyrJC main engine
 */
typedef struct zephyrjc_t
{
	scenario_t *current_scenario; /**< Pointer to current scenario */
	core_t core; /**< Core. TO BE IMPLEMENTED */
	linked_list_t scenarios; /**< List of scenarios */
	scenario_t *_head; /** Unused*/
} zephyrjc_t;

/**
 * Init engine
 *
 * @return Pointer to engine
 */
zephyrjc_t *zephyrjc_init(void);

/**
 * Add scenario to engine
 *
 * @param zjc Pointer to engine
 * @param scenario Scenario to add
 */
void zephyrjc_add_scenario(zephyrjc_t *zjc, scenario_t *scenario);


/**
 * Start the engine
 *
 * @param zjc Pointer to engine
 */
void zephyrjc_start(zephyrjc_t *zjc);


/**
 * Init graphics.
 *
 * @param zjc Pointer to engine
 * @param width Width of screen
 * @param height Height of screen
 * @bpp Bpp of screen
 */
void zephyrjc_init_graphics(zephyrjc_t *zjc, int width, int height, int bpp);


/**
 * Set the current scenario
 * 
 * @param zjc Pointer to engine
 * @param scenario Scenario to set as current
 */
static inline void zephyrjc_set_current_scenario(zephyrjc_t *zjc, scenario_t *scenario)
{
	zjc->current_scenario = scenario;
}
#endif
