#include <stdlib.h>
#include <ncurses.h>
#include "input.h"

input* create_input(void) {
  input* result = (input*)malloc(sizeof(input));
  result->joyX = 0;
  result->joyY = 0;
  return result;
}

int moving_left(input* in) {
  return in->joyX <= LOWER_THRESHOLD;
}

int moving_right(input* in) {
  return in->joyX >= UPPER_THRESHOLD;
}

int moving_up(input* in) {
  return in->joyY >= UPPER_THRESHOLD;
}

int moving_down(input* in) {
  return in->joyY <= LOWER_THRESHOLD;
}

