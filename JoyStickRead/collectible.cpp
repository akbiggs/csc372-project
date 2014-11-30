#include "collectible.h"

collectible* create_collectible(int x, int y, int flash_delay) {
  collectible* result = (collectible*)malloc(sizeof(collectible));

  result->pos = (point*)malloc(sizeof(point));

  reset_collectible(x, y, flash_delay, result);

  return result;
}

void reset_collectible(int x, int y, int flash_delay, collectible* game_collectible) {
  set_point(x, y, game_collectible->pos);

  game_collectible->flash_timer = -1;
  game_collectible->flash_delay = flash_delay;

  game_collectible->used = false;
}

void update_collectible(collectible* game_collectible) {
  game_collectible->flash_timer++;
}

bool should_draw_collectible(collectible* game_collectible) {
  int delay = game_collectible->flash_delay;
  return !game_collectible->used && game_collectible->flash_timer % (delay * 2) < delay;
}

void draw_collectible(collectible* game_collectible, screen* out) {
  if (!should_draw_collectible(game_collectible))
    return;

  set_pixel(game_collectible->pos->y, game_collectible->pos->x, '1', out);
}
