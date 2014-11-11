#include "point.h"

point* create_point(int x, int y) {
  point* result = (point*) malloc(sizeof(point));
  result->x = x;
  result->y = y;
  return result;
}

void set_point(int new_x, int new_y, point* p) {
  p->x = new_x;
  p->y = new_y;
}

void add_point(point* p1, point* p2) {
  p1->x += p2->x;
  p1->y += p2->y;
}

void negate_point(point* p) {
  p->x = -(p->x);
  p->y = -(p->y);
}

void multiply_point(int scalar, point* p) {
  p->x *= scalar;
  p->y *= scalar;
}

int equals_point(int x, int y, point* p) {
  return p->x == x && p->y == y;
}

void print_point(point* p) {
  printf("%d, %d\n", p->x, p->y);
}
