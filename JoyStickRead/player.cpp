#include <stdlib.h>

#include "player.h"

player* create_player(point* start_pos) {
    player* result = (player*)malloc(sizeof(player));

    result->pos = start_pos;
    result->dir = create_point(0, 0);
    result->move_delay = START_MOVE_DELAY;

    return result;
}

void update_player(input* in, player* game_player) {
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

  add_point(game_player->pos, game_player->dir);
}

void draw_player(player* game_player, screen* out) {
  set_pixel(game_player->pos->y, game_player->pos->x, '1', out);
}
