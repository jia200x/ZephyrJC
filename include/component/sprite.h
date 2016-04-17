
#include "component.h"
#include "graphics.h"
#include "transform.h"

typedef struct sprite_t
{
	component_t base;
	spriteBuffer_t *sprite;
	transform_t *transform;
} sprite_t;

typedef struct object_t object_t;

void sprite_init(component_t *c, void  **args);
void sprite_set(sprite_t *sprite, spriteBuffer_t *sb);
void sprite_render(void *c, void *args);
