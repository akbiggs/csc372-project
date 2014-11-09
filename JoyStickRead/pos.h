#ifndef POS_H
#define POS_H

typedef struct pos {
  int x;
  int y;
} pos;

pos* create_pos(int x, int y);
void pos_add(pos* p1, pos* p2);
void pos_negate(pos* p);
void pos_mul(int scalar, pos* p);
int equals_pos(int x, int y, pos* p);

#endif
