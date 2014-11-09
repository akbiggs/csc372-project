#ifndef INPUT_H
#define INPUT_H

typedef struct input {
  int joyX;
  int joyY;
} input;

input* create_input();

int moving_left(input* in);
int moving_right(input* in);
int moving_up(input* in);
int moving_down(input* in);

#endif
