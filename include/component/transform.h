#ifndef TRANSFORM_H
#define TRANSFORM_H

typedef struct transform_t
{
	int32_t x;
	int32_t y;
	int32_t x_speed;
	int32_t y_speed;

} transform_t;

void transform_setup(transform_t *t);
void transform_process(transform_t *t);

#endif
