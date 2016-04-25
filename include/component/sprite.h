
#include "component.h"
#include "graphics.h"
#include "transform.h"

/**
 * \brief Sprite component
 */
typedef struct sprite_t
{
	component_t base; /**< Inherits from component. */
	spriteBuffer_t *sprite; /**< Pointer to image */
	transform_t *transform; /**< Pointer to obj's transform component */
} sprite_t;

typedef struct object_t object_t;

/**
 * Init component. Called from create_component.
 *
 * @param c Pointer to component
 * @param args Arguments passed from init
 */
void sprite_init(component_t *c, void  **args);
/**
 * Set sprite
 *
 * @param sprite Pointer to sprite component
 * @param sb Pointer to image to set
 */
void sprite_set(sprite_t *sprite, spriteBuffer_t *sb);

/**
 * Registered callback to event EV_RENDER
 *
 * Automatically draw sprite
 * 
 * @param c Pointer to component
 * @param args Args from event dispatcher
 */
void sprite_render(void *c, void *args);
