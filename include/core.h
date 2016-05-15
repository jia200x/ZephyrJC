#ifndef CORE_H
#define CORE_H
#include "graphics.h"
#include "core/keyboard.h"

#define FLAG_EXIT (1)
/**
 * Core holder. To be implemented
 */

typedef struct core_t
{
	int dummy;
	graphics_t graphics;
	keyboard_t keyboard;
	int flags;
} core_t;

void core_init(core_t *core);
int core_input(core_t *core);
#endif
