#include <stdlib.h>
#include "pos.h"

pos* create_pos(int x, int y) {
  pos* result = (pos*) malloc(sizeof(pos));
  result->x = x;
  result->y = y;
  return result;
}

void pos_add(pos* p1, pos* p2) {
  p1->x += p2->x;
  p1->y += p2->y;
}

void pos_negate(pos* p) {
  p->x = -(p->x);
  p->y = -(p->y);
}

void pos_mul(int scalar, pos* p) {
  p->x *= scalar;
  p->y *= scalar;
}

int equals_pos(int x, int y, pos* p) {
  return p->x == x && p->y == y;
}
