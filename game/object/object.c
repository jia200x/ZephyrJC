#include "object.h"
#include "scenario.h"
#include "eventdispatcher.h"
#include <stdio.h>
#include "graphics.h"

void dummy_test(void *obj, void *nothing)
{
	(void) obj;
	(void) nothing;
}

void dummy_render(void *obj, void *nothing)
{
	rect_t src;
	src.x = 30;
	src.y = 30;
	src.w = 200;
	src.h = 200;

	spriteBuffer_t *screen = &((graphics_t*) nothing)->screen;
	spriteBuffer_t *sprite = &((object_t*) obj)->test;

	blit(sprite, screen , &src, &src);
}

void object_init(scenario_t *scenario, object_t *obj)
{
	load_bmp(&obj->test, "mario.png");
	register_event_callback(&scenario->ed, EV_UPDATE, obj, &dummy_test);
	register_event_callback(&scenario->ed, EV_RENDER, obj, &dummy_render);
}
void add_component(object_t *obj, component_t *component)
{
	linked_list_add(&obj->components, (void*) component);
}
void register_object(object_t *obj, scenario_t *scenario)
{
	scenario_add_object(scenario,obj);
}
