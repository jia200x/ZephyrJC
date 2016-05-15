#include "core/timer.h"
#include "SDL2/SDL.h"

void timer_zero(LTimer *timer)
{
	timer->_setpoint = SDL_GetTicks();
}

int timer_getTicks(LTimer *timer)
{
	return SDL_GetTicks()-timer->_setpoint;
}

void timer_delay(int time)
{
	SDL_Delay(time);
}
