#include "zephyrjc.h"
#include "graphics.h"
#include "component/transform.h"
#include "component/sprite.h"
#include <stdio.h>

int main(void)
{
	zephyrjc_t *game = zephyrjc_init();
	zephyrjc_init_graphics(game, 640, 480, 32);

	//Add test scenario
	scenario_t test_scenario;
	test_scenario.graphics = &game->core.graphics;
	scenario_init(&test_scenario);

	game->current_scenario = &test_scenario;

    object_t obj;
	object_init(&test_scenario, &obj);

	component_t *transform = component_create(0,&obj, sizeof(transform_t), &transform_init, NULL);

	sprite_t *sp = (sprite_t*) component_create(1,&obj, sizeof(sprite_t), &sprite_init, (void**) &transform);

	spriteBuffer_t *sprite = create_sprite();
	load_bmp(sprite, "mario.png");
	sprite_set(sp, sprite);

	scenario_add_object(&test_scenario, &obj);
	zephyrjc_start(game);
}
