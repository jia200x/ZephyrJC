#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

typedef enum
{
	EV_UPDATE,
	EV_RENDER,
	EV_NUMOFEVENTS
} event_t;

typedef struct event_container_t
{
	void *target;
	void (*func)(void *target, void *args);
	struct event_container_t *next;
} event_container_t;

typedef struct event_dispatcher_t
{
	event_container_t *_ev_list[EV_NUMOFEVENTS];
} event_dispatcher_t;


void event_dispatcher_init(event_dispatcher_t *ed);
int dispatch_event(event_dispatcher_t *ed, int event,void *args); 
int register_event_callback(event_dispatcher_t *ed, int event, void *target, void (*func)(void *target, void*args));
#endif
