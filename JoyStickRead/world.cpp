#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "world.h"
#include "screen.h"

world* create_world(int width, int height) {
  world* result = (world*) malloc(sizeof(world));

  result->width = width;
  result->height = height;
  result->game_player = create_player(0, 0);
  result->walls = (point*)malloc(sizeof(point) * width * height);

  reset_world(result);

  return result;
}

void reset_world(world* game_world) {
  reset_player(game_world->width / 2, game_world->height / 2, 
          game_world->game_player);

  game_world->num_walls = 0;
  for (int i = 0; i < game_world->width; i++) {
    add_wall(i, 0, game_world);
    add_wall(i, game_world->height - 1, game_world);
  }
  for (int i = 0; i < game_world->height; i++) {
    add_wall(0, i, game_world);
    add_wall(game_world->width - 1, i, game_world);
  }
}

void add_wall(int x, int y, world* game_world) {
  game_world->walls[game_world->num_walls].x = x;
  game_world->walls[game_world->num_walls].y = y;
  game_world->num_walls++;
}

void remove_wall(int x, int y, world* game_world) {
  int wall_index = index_of_point(x, y, game_world->walls, game_world->num_walls);
  if (wall_index == -1)
    return;

  for (; wall_index < game_world->num_walls - 1; wall_index++) {
    game_world->walls[wall_index] = game_world->walls[wall_index + 1];
  }
  game_world->num_walls--;
}

void update_world(input* in, world* game_world) {
  update_player(in, game_world->walls, game_world->num_walls,
          game_world->game_player);
}

void random_inbounds_pos(world* world, point* pos) {
  //pos->x = (rand() % world->width - 2) + 1;
  //pos->y = (rand() % world->height - 2) + 1;
}

void draw_world(world* game_world, screen* out) {
  for (int i = 0; i < game_world->height; i++) {
    for (int j = 0; j < game_world->width; j++) {
      set_pixel(i, j, '0', out);
    }
  }

  for (int i = 0; i < game_world->num_walls; i++) {
    point wall = game_world->walls[i];
    set_pixel(wall.y, wall.x, '1', out);
  }

  draw_player(game_world->game_player, out);
}
