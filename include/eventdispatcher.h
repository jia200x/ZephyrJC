#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

/**
 * Label for events of engine's event dispatcher. Extend as necessary
 */
typedef enum
{
	EV_UPDATE, 
	EV_RENDER,
	EV_NUMOFEVENTS
} event_t;

/**
 * Snip of an event. 
 *
 * All snips are linked together and called one by one
 */
typedef struct event_container_t
{
	void *target; /**< Who is the subscriber of event*/
	void (*func)(void *target, void *args); /**< Callback function when event is triggered */
	struct event_container_t *next; /**< Pointer to next snip */
} event_container_t;

/**
 * Event dispatcher.
 *
 * Contains a list of event snips for every event.
 */
typedef struct event_dispatcher_t
{
	event_container_t *_ev_list[EV_NUMOFEVENTS]; /**< List of event snips */
} event_dispatcher_t;


/**
 * Init event dispatcher
 * @param ed Pointer to event dispatcher to initialize*/
void event_dispatcher_init(event_dispatcher_t *ed);


/**
 * Dispatch event
 * @param ed Pointer to event dispatcher
 * @param event Event to dispatch
 * @param args Args for the callback function
 * @return Nothing useful at the moment...
 */
int dispatch_event(event_dispatcher_t *ed, int event,void *args); 


/**
 * Register a callback for a given target
 *
 * @param ed Pointer to event dispatcher
 * @param event Event to subscribe.
 * @param target Subscriber of callback
 * @param func Callback function to subscribe
 * @return Nothing usefull at the moment...
 */
int register_event_callback(event_dispatcher_t *ed, int event, void *target, void (*func)(void *target, void*args));
#endif
