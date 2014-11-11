#ifndef INPUT_H
#define INPUT_H

#define LOWER_THRESHOLD 400
#define UPPER_THRESHOLD 700

typedef struct input {
  int joyX;
  int joyY;
} input;

input* create_input();
void update_input(input* in);

int moving_left(input* in);
int moving_right(input* in);
int moving_up(input* in);
int moving_down(input* in);

#endif
