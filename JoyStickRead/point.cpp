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

void add_point(point* p1, const point p2) {
  p1->x += p2.x;
  p1->y += p2.y;
}

void negate_point(point* p) {
  p->x = -(p->x);
  p->y = -(p->y);
}

void multiply_point(int scalar, point* p) {
  p->x *= scalar;
  p->y *= scalar;
}

int equals_point(int x, int y, const point p) {
  return p.x == x && p.y == y;
}

int index_of_point(int x, int y, point* points, int num_points) {
  if (!points) {
      return -1;
  }

  for (int i = 0; i < num_points; i++) {
    point p = points[i];
    if (p.x == x && p.y == y)
      return i;
  }

  return -1;
}

int contains_point(int x, int y, point* points, int num_points) {
  return index_of_point(x, y, points, num_points) != -1;
}

void print_point(const point p) {
  printf("%d, %d\n", p.x, p.y);
}
