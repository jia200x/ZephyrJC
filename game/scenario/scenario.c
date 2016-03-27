#include "scenario/scenario.h"

void init(scenario_t *scenario)
{
	linked_list_init(scenario->objects);
	scenario->view_x = 0;
	scenario->view_y = 0;
}

void process(scenario_t *scenario)
{
	object_elem_t *curr_obj = linked_list_get_head_obj(sm->objects);

	while(curr_obj != NULL)
	{
		obj->data->process();
	}
}
void register_scenario(scenario_t *scenario, scenartio_manager_t *sm)
{
	sm->add_scenario(self)
}
void render(scenario_t *scenario, core_t *core)
{
	/*
	for o in self.objects:
		#By default, render current sprite at x, y
		core.graphics.screen.blit(o.sprite, (o.x-self.view_x, o.y-self.view_y)) 
	*/
}
void add_object(scenario_t *scenario, object_t *obj)
{
	linked_list_add(scenario->objects, (void*) obj);
}
