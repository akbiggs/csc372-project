#ifndef PLAYER_H
#define PLAYER_H

#include "point.h"
#include "input.h"
#include "screen.h"

#define START_MOVE_DELAY 1000
#define MAX_TAIL_LENGTH 10

typedef struct player {
    point* pos;
    point* dir;

    point* tail;
    int tail_length;

    int move_delay;
    int alive;
} player;

player* create_player(int start_x, int start_y);
void reset_player(int start_x, int start_y, player* game_player);

point get_tail_end(player* game_player);
point get_tail_direction(player* game_player);
void extend_tail(player* game_player);

void update_player(input* in, point* walls, int num_walls, player* game_player);
void update_tail_to(int newX, int newY, player* game_player);
void draw_player(player* game_player, screen* out);

#endif
