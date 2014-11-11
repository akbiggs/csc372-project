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
} player;

player* create_player(point* start_pos);

void update_player(input* in, player* game_player);
void draw_player(player* game_player, screen* out);

#endif
