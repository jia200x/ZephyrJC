#include "zephyrjc.h"
#include "graphics.h"
#include "component/transform.h"
#include "component/sprite.h"
#include "tiles.h"
#include <stdio.h>

int main(void)
{
	//Create game object
	zephyrjc_t *game = zephyrjc_init();

	//Init graphics
	zephyrjc_init_graphics(game, 640, 480, 32);

	//Create scenario and set as current
	scenario_t *test_scenario = scenario_init(game);
	zephyrjc_set_current_scenario(game, test_scenario);

	//Create an abstract object
	object_t *obj = object_init(test_scenario);

	//Add transform component to object
	component_t *transform = component_create(0,obj, sizeof(transform_t), &transform_init, NULL);

	//Add tilemap
	component_t *tileengine = component_create(2, obj, sizeof(tileengine_t), &tileengine_init, NULL);	
	tilepool_t *tp = create_tilepool("tiles.png", 16, 16, 0, 0);

	uint16_t test_array[2][2] = {{9,10},{11,12}};
	tilemap_t *tilemap = create_tilemap(tp, (uint16_t*) *test_array, 2, 2, 0);
	tileengine_t *cte = (tileengine_t*) tileengine;
	cte->current_tilemap = tilemap;
	cte->screen_x = 0;
	cte->screen_x = 0;
	cte->screen_width = 32;
	cte->screen_height = 32;

	//Add sprite component to object. Set sprite
	/*sprite_t *sp = (sprite_t*) component_create(1,obj, sizeof(sprite_t), &sprite_init, (void**) &transform);
	spriteBuffer_t *sprite = create_sprite();
	load_bmp(sprite, "mario.png");
	sprite_set(sp, sprite);*/

	//Start Zephyr Jarlsberg & Chedar engine
	puts("I'm here");
	zephyrjc_start(game);
	return 0;
}
