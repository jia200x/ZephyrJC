#ifndef GAME_OBJECT_T
#define GAME_OBJECT_T

typedef struct object_t
{
	int id;
	uint32_t x;
	uint32_t y;
	uint32_t x_speed;
	uint32_t y_speed;
	layer_t sprite;
} object_t;

void process(object_t *obj);
void register_object(object_t *obj, scenario_t *scenario);

#endif
