#include <stdlib.h>
#include "world.h"

world* create_world(void) {
  world* result = (world*) malloc(sizeof(world));
  result->player_pos = create_pos(4, 4);
  
  result->width = 8;
  result->height = 8;
  
  return result;
}

void update_world(input* in, world* game_world) {
  if (moving_left(in)) {
    game_world->player_pos->x -= 1;
  }
  else if (moving_right(in)) {
    game_world->player_pos->x += 1;
  }
  else if (moving_up(in)) {
    game_world->player_pos->y -= 1;
  }
  else if (moving_down(in)) {
    game_world->player_pos->y += 1;
  }
}

void draw_world(world* game_world, char* out) {
  for (int i = 0; i < game_world->height; i++) {
    for (int j = 0; j < game_world->width; j++) {
      if (equals_pos(j, i, game_world->player_pos)) {
        out[i * 8 + j] = '0';
      } else {
        out[i * 8 + j] = '1';
      }
    }
  }
}
