#include <stdlib.h>

#include "player.h"

player* create_player(int start_x, int start_y) {
  player* result = (player*)malloc(sizeof(player));

  // x and y values are set when player resets to avoid
  // repeated game logic
  result->pos = create_point(0, 0);
  result->dir = create_point(0, 0);
  result->tail = (point*)malloc(sizeof(point) * MAX_TAIL_LENGTH);

  reset_player(start_x, start_y, result);

  return result;
}

void reset_player(int start_x, int start_y, player* game_player) {
  set_point(start_x, start_y, game_player->pos);
  set_point(0, 0, game_player->dir);

  game_player->move_delay = START_MOVE_DELAY;
  game_player->alive = 1;
  game_player->ticks_without_move = 0;
  game_player->move_requested = false;
  game_player->tail_length = 0;
}

point get_tail_end(player* game_player) {
  if (game_player->tail_length == 0)
    return *(game_player->pos);
  return game_player->tail[game_player->tail_length - 1];
}

point get_tail_direction(player* game_player) {
  point player_dir = *(game_player->dir);
  if (game_player->tail_length <= 1) {
    player_dir.x *= -1;
    player_dir.y *= -1;
    return player_dir;
  }

  // tail direction is the direction between the last two points of the tail
  point tail_end = get_tail_end(game_player);
  point previous_tail = game_player->tail[game_player->tail_length - 2];

  tail_end.x -= previous_tail.x;
  tail_end.y -= previous_tail.y;
  return tail_end;
}

void extend_tail(player* game_player) {
  point* next_tail_point = game_player->tail + game_player->tail_length;

  point tail_end = get_tail_end(game_player);
  point tail_dir = get_tail_direction(game_player);

  set_point(tail_end.x + tail_dir.x, tail_end.y + tail_dir.y, next_tail_point);

  game_player->tail_length++;
}

void request_move_direction(int x, int y, player* game_player) {
    set_point(x, y, game_player->dir);
    game_player->move_requested = true;
}

void update_player(input* in, point* walls, int num_walls, collectible* pellet,
        player* game_player) {
  if (!game_player->alive)
    return;

  game_player->ticks_without_move++;

  if (moving_left(in)) {
    request_move_direction(-1, 0, game_player);
  }
  else if (moving_right(in)) {
    request_move_direction(1, 0, game_player);
  }
  else if (moving_up(in)) {
    request_move_direction(0, -1, game_player);
  }
  else if (moving_down(in)) {
    request_move_direction(0, 1, game_player);
  }


  if (game_player->move_requested ||
          game_player->ticks_without_move > game_player->move_delay / FLASH_DELAY) {
      update_tail_to(game_player->pos->x, game_player->pos->y, game_player);
      add_point(game_player->pos, *game_player->dir);

      pellet->flash_timer = -1;

      point* new_pos = game_player->pos;
      if (contains_point(new_pos->x, new_pos->y, walls, num_walls) ||
          contains_point(new_pos->x, new_pos->y, game_player->tail, game_player->tail_length)) {
        game_player->alive = 0;
      } else if (equals_point(new_pos->x, new_pos->y, *pellet->pos)) {
        pellet->used = true;
        if (game_player->tail_length < MAX_TAIL_LENGTH)
          extend_tail(game_player);
      }

      game_player->move_requested = false;
      game_player->ticks_without_move = 0;
  }
}

void update_tail_to(int newX, int newY, player* game_player) {
  if (game_player->tail_length == 0) {
    return;
  }

  int nextX = newX;
  int nextY = newY;
  for (int i = 0; i < game_player->tail_length; i++) {
    int oldX = game_player->tail[i].x;
    int oldY = game_player->tail[i].y;

    game_player->tail[i].x = nextX;
    game_player->tail[i].y = nextY;

    nextX = oldX;
    nextY = oldY;
  }
}

void draw_player(player* game_player, screen* out) {
  set_pixel(game_player->pos->y, game_player->pos->x, '1', out);

  for (int i = 0; i < game_player->tail_length; i++) {
    point tail = game_player->tail[i];
    set_pixel(tail.y, tail.x, '1', out);
  }
}
