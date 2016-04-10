#include <stdlib.h>
#include "eventdispatcher.h"

void event_dispatcher_init(event_dispatcher_t *ed)
{
	for(int i=0;i<EV_NUMOFEVENTS;i++)
	{
		ed->_ev_list[i] = NULL;
	}
}
int dispatch_event(event_dispatcher_t *ed, int event,void *args)
{
	if (event < 0 || event >= EV_NUMOFEVENTS)
	{
		return -1;
	}

	event_container_t *ec = ed->_ev_list[event];	
	while(ec)
	{
		ec->func(ec->target, args);
		ec = ec->next;
	}
	return 0;
}

int register_event_callback(event_dispatcher_t *ed, int event, void *target, void (*func)(void *target, void*args))
{
	if (event < 0 || event >= EV_NUMOFEVENTS)
	{
		return -1;
	}

	event_container_t *ec = (event_container_t*) malloc(sizeof(event_container_t));	
	ec->next = NULL;
	ec->func = func;
	if (ed->_ev_list[event] == NULL)
	{
		ed->_ev_list[event] = ec;
	}
	else
	{
		ed->_ev_list[event]->next = ec;
	}
	return 0;
}
