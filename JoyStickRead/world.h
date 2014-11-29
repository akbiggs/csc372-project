#ifndef WORLD_H
#define WORLD_H

#include "point.h"
#include "collectible.h"
#include "player.h"
#include "input.h"

typedef struct world {
  player* game_player;

  collectible* pellet;

  point* walls;
  int num_walls;

  int width;
  int height;
} world;

world* create_world(int width, int height);
void reset_world(world* game_world);

void add_wall(int x, int y, world* game_world);
void remove_wall(int x, int y, world* game_world);

void random_inbounds_pos(world* game_world, point* p);

void update_world(input* in, world* game_world);
void draw_world(world* game_world, screen* out);

#endif
