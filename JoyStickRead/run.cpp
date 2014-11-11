#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#include "world.h"
#include "input.h"
#include "screen.h"

static world* game_world;
static input* in;
static screen* game_screen;

void setup() {
  in = create_input();
  game_screen = create_screen(8, 8);
  game_world = create_world(game_screen->width, game_screen->height);

  initscr();
}

void loop() {
  in->joyX = (UPPER_THRESHOLD + LOWER_THRESHOLD) / 2;
  in->joyY = (UPPER_THRESHOLD + LOWER_THRESHOLD) / 2;

  timeout(game_world->game_player->move_delay);
  switch (getch()) {
    case '\n':
        return;
    case 'w':
        in->joyY = UPPER_THRESHOLD;
        break;
    case 's':
        in->joyY = LOWER_THRESHOLD;
        break;
    case 'a':
        in->joyX = LOWER_THRESHOLD;
        break;
    case 'd':
        in->joyX = UPPER_THRESHOLD;
        break;
  }

  erase();

  update_world(in, game_world);
  draw_world(game_world, game_screen);

  for (int i = 0; i < game_screen->height; i++) {
    for (int j = 0; j < game_screen->width; j++) {
      addch(get_pixel(i, j, game_screen));
      if (j != game_screen->width - 1) {
        addstr(", ");
      }
    }
    addch('\n');
  }
}

int main() {
    setup();
    while (true) {
        loop();
    }
}
