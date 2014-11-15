#ifndef PLAYER_H
#define PLAYER_H

#include "point.h"
#include "input.h"
#include "screen.h"

#define START_MOVE_DELAY 1000

typedef struct player {
    point* pos;
    point* dir;

    int move_delay;
    int alive;
} player;

player* create_player(int start_x, int start_y);
void reset_player(int start_x, int start_y, player* game_player);

void update_player(input* in, point* walls, int num_walls, player* game_player);
void draw_player(player* game_player, screen* out);

#endif
