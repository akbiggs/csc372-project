#ifndef WORLD_H
#define WORLD_H

#include "pos.h"
#include "input.h"

typedef struct world {
  pos* player_pos;
  int width;
  int height;
} world;

world* create_world();
void update_world(input* in, world* game_world);
void draw_world(world* game_world, char** out);

#endif
