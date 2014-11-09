#include "pos.h"

pos* create_pos(int x, int y) {
  pos* result = (pos*) malloc(sizeof(pos));
  result->x = x;
  result->y = y;
  return result;
}

pos* add(pos* p1, pos* p2) {
  return create_pos(p1->x + p2->x, p1->y + p2->y);
}

pos* negate(pos* p) {
  return create_pos(-(p->x), -(p->y));
}

pos* mul(pos* p, int scalar) {
  return create_pos(p->x * scalar, p->y * scalar);
}

