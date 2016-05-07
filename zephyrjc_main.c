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
	scenario_t *test_scenario = scenario_create(game);
	zephyrjc_set_current_scenario(game, test_scenario);

	//Create an abstract object
	object_t *obj = object_create(test_scenario);

	//Add transform component to object
	component_t *transform = component_create(0,obj, sizeof(transform_t), &transform_init, NULL);
	(void) transform;

	//Add tilemap
	component_t *tileengine = component_create(2, obj, sizeof(tileengine_t), &tileengine_init, NULL);	
	tilepool_t *tp = create_tilepool("tiles.png", 16, 16, 0, 0, 55, 36);

	uint16_t test_array[36][55];
	for(int y=0;y<36;y++)
	{
		for (int x=0;x<55;x++)
		{
			test_array[y][x] = x+y*55;
		}
	}
	tilemap_t *tilemap = create_tilemap(tp, (uint16_t*) *test_array, 55, 36, 0);
	tileengine_t *cte = (tileengine_t*) tileengine;
	cte->current_tilemap = tilemap;
	cte->source.x = 0;
	cte->source.y = 0;
	cte->source.w = 640;
	cte->source.h = 480;

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
