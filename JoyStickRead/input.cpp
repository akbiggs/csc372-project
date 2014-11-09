#include <stdlib.h>
#include "input.h"

input* create_input(void) {
  input* result = (input*)malloc(sizeof(input));
  result->joyX = 0;
  result->joyY = 0;
  return result;
}

int moving_left(input* in) {
  return in->joyX < 400;
}

int moving_right(input* in) {
  return in->joyX > 700;
}

int moving_up(input* in) {
  return in->joyY > 700;
}

int moving_down(input* in) {
  return in->joyY < 400;
}


