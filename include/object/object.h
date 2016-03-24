#ifndef GAME_OBJECT_T
#define GAME_OBJECT_T

typedef linked_list_t object_list_t
typedef ll_node_t object_elem_t;

typedef struct object_t
{
	int id;
	int32_t x;
	int32_t y;
	int32_t x_speed;
	int32_t y_speed;
	layer_t sprite;
} object_t;

void init(object_t *obj);
void process(object_t *obj);
void register_object(object_t *obj, scenario_t *scenario);

#endif
