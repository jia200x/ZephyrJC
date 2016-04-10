
void event_dispatcher_init(event_dispatcher_t *ed)
{
	for(int i=0;i<EV_NUMOFEVENTS;i++)
	{
		ed->_ev_list = NULL;
	}
}
int dispatch_event(event_dispatcher_t *ed, int event,void *args)
{
	if (event < 0 || EV >= EV_NUMOFEVENTS)
	{
		return -1;
	}

	event_container_t *ec = _ev_list[event];	
	while(ec)
	{
		ec->func(ec->target, args);
		ec = ec->next;
	}
	return 0;
}

void register_event_callback(scenario_t *scenario, int event, void *target, void (*func)(void *target, void*args))
{
	if (event < 0 || EV >= EV_NUMOFEVENTS)
	{
		return -1;
	}

	event_container_t *ec = (event_container_t*) malloc(sizeof(event_container_t));	
	if (scenario->_ev_list[event] == NULL)
	{
		scenario->_ev_list[event] = ec;
	}
	else
	{
		scenario->_ev_list[event]->next = ec;
		ec->next = NULL;
	}
}
