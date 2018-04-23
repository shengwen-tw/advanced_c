#include <stdio.h>
#include <stdlib.h>

/* shaple class */
typedef struct {
	//position of the shape
	int x;
	int y;
} Shape;

//new operator of shape class
int shape_new(Shape **self)
{
	if(NULL == (*self = (Shape *)malloc(sizeof(Shape)))) return -1;

	return 0;
}

//constructor of shape class
int shape_ctor(Shape * const self, int x, int y)
{
	self->x = x;
	self->y = y;
}

//member function of shape class
void shape_move_by(Shape * const self, int dx, int dy)
{
	self->x += dx;
	self->y += dy;
}

/* rectangle class inherite from shape */
typedef struct {
	Shape super;

	int width;
	int height;
} Rectangle;

//member function of rectangle
int rectangle_new(Rectangle ** self)
{
	if(NULL == (*self = (Rectangle *)malloc(sizeof(Rectangle)))) return -1;

	return 0;
}

void rectangle_ctor(Rectangle * const self, int x, int y, int width, int height)
{
	//call super class's constructor
	shape_ctor(&(self->super), x, y);

	self->width = width;
	self->height = height;
}

int rectangle_size(Rectangle * const self)
{
	return self->width * self->height;
}

int main(void)
{
	Rectangle *rectangle = NULL;
	if(rectangle_new(&rectangle) == -1) exit(1);
	rectangle_ctor(rectangle, 5, 15, 20, 30);

	printf("create rectangle [%p] at position (%d, %d)\n",
	       rectangle, rectangle->super.x, rectangle->super.y);

	printf("rectangle size is %dx%d=%d\n",
	       rectangle->width, rectangle->height, rectangle_size(rectangle));

	//re-use inherited function from super class "Shape"
	shape_move_by(&(rectangle->super), 21, 4);

	printf("the rectangle is now moved to (%d, %d)\n", rectangle->super.x, rectangle->super.y);

	return 0;
}
