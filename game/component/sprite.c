#include "component/sprite.h"
#include "eventdispatcher.h"


void sprite_init(component_t *c, void  **args)
{
	sprite_t *s = (sprite_t*) c;
	s->sprite = NULL;
	s->sprite = create_sprite();
	s->transform = (transform_t*) *args;
	register_event_callback(&c->obj->scenario->ed, EV_RENDER, c, &sprite_render);
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


