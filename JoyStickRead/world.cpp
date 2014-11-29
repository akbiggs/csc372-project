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
  result->pellet = create_collectible(0, 0, 50);
  result->walls = (point*)malloc(sizeof(point) * width * height);

  reset_world(result);

  srand(0);

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

  random_inbounds_pos(game_world, game_world->pellet->pos);
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
  collectible* pellet = game_world->pellet;

  update_player(in, game_world->walls, game_world->num_walls, pellet,
          game_world->game_player);

  if (pellet->used) {
    random_inbounds_pos(game_world, pellet->pos);
    pellet->used = false;
  }
}

bool inbounds(point* pos, world* game_world) {
  return pos->x >= 0 && pos->x < game_world->width &&
         pos->y >= 0 && pos->y < game_world->height &&
         !contains_point(pos->x, pos->y, game_world->game_player->tail,
                         game_world->game_player->tail_length) &&
         !contains_point(pos->x, pos->y, game_world->walls, game_world->num_walls);
}

void random_inbounds_pos(world* game_world, point* pos) {
  do {
    pos->x = (rand() % game_world->width - 2) + 1;
    pos->y = (rand() % game_world->height - 2) + 1;
  } while (!inbounds(pos, game_world));
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
  draw_collectible(game_world->pellet, out);
}
