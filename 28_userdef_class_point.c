#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Point {
    double x;
    double y;

    void (*dump)(const struct Point *self); 
    // dump is the method name and it is a pointer to a function which is defined somewhere else.
    // It takes one argument named self. self is a pointer to struct Point.
    void (*del)(const struct Point* self);
    double (*origin)(const struct Point* self);
};

// methods definitions
void point_dump(const struct Point* self)
{
    printf("Object Point@ %p, x=%f, y=%f\n", self,self->x, self->y);
}

void point_del(const struct Point* self)
{
    free((void *)self);
}

double point_origin(const struct Point* self)
{
    return sqrt(self->x*self->x + self->y*self->y);
}

// constructor
struct Point * point_new(double x, double y)
{
    struct Point *p = malloc(sizeof(*p));
    p->x = x;
    p->y = y;
    p->dump = &point_dump;
    p->del = &point_del;
    p->origin = &point_origin;
    return p;
}

// main
int main() {
    struct Point * pt = point_new(4.0, 5.0);
    pt->dump(pt);
    printf("Origin %f\n",pt->origin(pt));
    pt->del(pt);
    return 0;
}