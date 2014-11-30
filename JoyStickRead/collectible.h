#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include <stdlib.h>

#include "point.h"
#include "screen.h"

#define FLASH_DELAY 300

typedef struct collectible {
  point* pos;
  int flash_timer;
  int flash_delay;
  bool used;
} collectible;

collectible* create_collectible(int x, int y, int flash_delay);
void reset_collectible(int x, int y, int flash_delay, collectible* game_collectible);

void update_collectible(collectible* game_collectible);

bool should_draw_collectible(collectible* game_collectible);
void draw_collectible(collectible* game_collectible, screen* out);

#endif // COLLECTIBLE_H
