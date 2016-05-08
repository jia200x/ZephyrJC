#include "component/sprite.h"
#include "eventdispatcher.h"


component_t *sprite_create(object_t *obj)
{
	component_t *c = component_create(COMPONENT_SPRITE, obj, sizeof(sprite_t));
	component_t *t = get_component_by_type(obj, COMPONENT_TRANSFORM);
	sprite_t *s = (sprite_t*) c;
	s->sprite = NULL;
	s->sprite = create_sprite();
	s->transform = (transform_t*) t;
	register_event_callback(&c->obj->scenario->ed, EV_RENDER, c, &sprite_render);
	return c;
}

void sprite_set(sprite_t *sprite, spriteBuffer_t *sb)
{
	sprite->sprite = sb;
}

void sprite_render(void *c, void *args)
{
	sprite_t *s = (sprite_t*) c;
	if(!s->sprite)
		return;

	graphics_t *graphics = (graphics_t*) args;
	rect_t src;
	src.x = 0;
	src.y = 0;
	src.w = 200;
	src.h = 200;

	rect_t dst;
	dst.x = s->transform->x;
	dst.y = s->transform->y;
	dst.w = 200;
	dst.h = 200;

	blit(s->sprite, &graphics->screen, &src, &dst);
}


