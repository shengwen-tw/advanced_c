#include <stdio.h>
#include <stdlib.h>

typedef struct {
	//position of the shape
	int x;
	int y;
} Shape;

//constructor
int shape_init(Shape **self, int x, int y)
{
	if(NULL == (*self = (Shape *)malloc(sizeof(Shape)))) return -1;

	(*self)->x = x;
	(*self)->y = y;

	return 0;
}

//member function
void shape_move_by(Shape * const self, int dx, int dy)
{
	self->x += dx;
	self->y += dy;
}

int main(void)
{
	Shape *shape = NULL;
	if(shape_init(&shape, 10, 5) == -1) exit(1);

	printf("create shape [%p] at position (%d, %d)\n", shape, shape->x, shape->y);

	shape_move_by(shape, 21, 4);

	printf("the shape is now moved to (%d, %d)\n", shape->x, shape->y);

	return 0;
}
