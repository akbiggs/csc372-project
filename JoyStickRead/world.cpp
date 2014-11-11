#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "world.h"
#include "screen.h"

world* create_world(int width, int height) {
  world* result = (world*) malloc(sizeof(world));

  result->game_player = create_player(create_point(width / 2, height / 2)); 
  result->width = width;
  result->height = height;

  return result;
}

void update_world(input* in, world* game_world) {
  update_player(in, game_world->game_player);
}

void random_inbounds_pos(world* world, point* pos) {
  //pos->x = (rand() % world->width - 2) + 1;
  //pos->y = (rand() % world->height - 2) + 1;
}

void draw_world(world* game_world, screen* out) {
  for (int i = 0; i < game_world->height; i++) {
    for (int j = 0; j < game_world->width; j++) {
       if (i == 0 || j == 0 || i == game_world->height - 1 || j == game_world->width - 1) {
           set_pixel(i, j, '1', out);
       } else {
           set_pixel(i, j, '0', out);
       }
    }
  }

  draw_player(game_world->game_player, out);
}
