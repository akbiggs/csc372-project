typedef struct pos {
  int x;
  int y;
} pos;

pos* add(pos* p1, pos* p2);
pos* negate(pos* p);
pos* mul(pos* p, int scalar);

