//#include <stdio.h>
//#include <ncurses.h>
//#include <stdlib.h>
//
//#include "world.h"
//#include "collectible.h"
//#include "input.h"
//#include "screen.h"
//
//static world* game_world;
//static input* in;
//static screen* game_screen;
//
//void setup() {
//  in = create_input();
//  game_screen = create_screen(8, 8);
//  game_world = create_world(game_screen->width, game_screen->height);
//
//  initscr();
//}
//
//void loop() {
//  in->joyX = (UPPER_THRESHOLD + LOWER_THRESHOLD) / 2;
//  in->joyY = (UPPER_THRESHOLD + LOWER_THRESHOLD) / 2;
//
//  timeout(FLASH_DELAY);
//
//  switch (getch()) {
//    case '\n':
//        if (!game_world->game_player->alive) {
//            reset_world(game_world);
//        }
//        break;
//    case 'w':
//        in->joyY = UPPER_THRESHOLD;
//        break;
//    case 's':
//        in->joyY = LOWER_THRESHOLD;
//        break;
//    case 'a':
//        in->joyX = LOWER_THRESHOLD;
//        break;
//    case 'd':
//        in->joyX = UPPER_THRESHOLD;
//        break;
//    case 't':
//        extend_tail(game_world->game_player);
//        break;
//  }
//
//  erase();
//
//  update_world(in, game_world);
//  draw_world(game_world, game_screen);
//
//  for (int i = 0; i < game_screen->height; i++) {
//    for (int j = 0; j < game_screen->width; j++) {
//      addch(get_pixel(i, j, game_screen));
//      if (j != game_screen->width - 1) {
//        addstr(", ");
//      }
//    }
//    addch('\n');
//  }
//
//  if (!game_world->game_player->alive) {
//    addstr("The player is dead.\n");
//  }
//}
//
//int main() {
//    setup();
//    while (true) {
//        loop();
//    }
//}
