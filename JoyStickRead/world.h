#ifndef WORLD_H
#define WORLD_H

#include "point.h"
#include "player.h"
#include "input.h"

typedef struct world {
  player* game_player;

  point* pellet_pos;

  int width;
  int height;
} world;

world* create_world(int width, int height);
void random_inbounds_pos(world* game_world, point* p);

void update_world(input* in, world* game_world);
void draw_world(world* game_world, screen* out);

#endif
