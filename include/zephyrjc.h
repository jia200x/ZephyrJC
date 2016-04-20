#ifndef ZEPHYRJC_H
#define ZEPHYRJC_H

#include "sys.h"
#include "core.h"

typedef struct scenario_t scenario_t;
typedef struct zephyrjc_t
{
	scenario_t *current_scenario;
	core_t core;
	linked_list_t scenarios;
	scenario_t *_head;
} zephyrjc_t;

zephyrjc_t *zephyrjc_init(void);
void zephyrjc_add_scenario(zephyrjc_t *zjc, scenario_t *scenario);
void zephyrjc_start(zephyrjc_t *zjc);
void zephyrjc_init_graphics(zephyrjc_t *zjc, int width, int height, int bpp);
static inline void zephyrjc_set_current_scenario(zephyrjc_t *zjc, scenario_t *scenario)
{
	zjc->current_scenario = scenario;
}
#endif
