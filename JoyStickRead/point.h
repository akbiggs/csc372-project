#ifndef POS_H
#define POS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct point {
  int x;
  int y;
} point;

point* create_point(int x, int y);

void set_point(int x, int y, point* p);
void add_point(point* p1, const point p2);
void negate_point(point* p);
void multiply_point(int scalar, point* p);

int equals_point(int x, int y, const point p);
int index_of_point(int x, int y, point* points, int num_points);
int contains_point(int x, int y, point* points, int num_points);

void print_point(const point p);

#endif
