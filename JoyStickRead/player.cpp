#include <stdlib.h>

#include "player.h"

player* create_player(int start_x, int start_y) {
  player* result = (player*)malloc(sizeof(player));

  // x and y values are set when player resets to avoid
  // repeated game logic
  result->pos = create_point(0, 0);
  result->dir = create_point(0, 0);

  reset_player(start_x, start_y, result);

  return result;
}

void reset_player(int start_x, int start_y, player* game_player) {
  set_point(start_x, start_y, game_player->pos);
  set_point(0, 0, game_player->dir);

  game_player->move_delay = START_MOVE_DELAY;
  game_player->alive = 1;
}

void update_player(input* in, point* walls, int num_walls, player* game_player) {
  if (!game_player->alive)
    return;

  if (moving_left(in)) {
    set_point(-1, 0, game_player->dir);
  }
  else if (moving_right(in)) {
    set_point(1, 0, game_player->dir);
  }
  else if (moving_up(in)) {
    set_point(0, -1, game_player->dir);
  }
  else if (moving_down(in)) {
    set_point(0, 1, game_player->dir);
  }

  add_point(game_player->pos, *game_player->dir);

  point* new_pos = game_player->pos;
  if (contains_point(new_pos->x, new_pos->y, walls, num_walls)) {
    game_player->alive = 0;
  }
}

void draw_player(player* game_player, screen* out) {
  set_pixel(game_player->pos->y, game_player->pos->x, '1', out);
}
