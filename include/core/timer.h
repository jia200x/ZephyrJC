#ifndef TIMER_H
#define TIMER_H

typedef struct LTimer
{
	int _setpoint;
} LTimer;

void timer_zero(LTimer *timer);
int timer_getTicks(LTimer *timer);

#endif
