#ifndef SCREEN_H
#define SCREEN_H

#include <stdlib.h>

typedef struct screen {
    int width;
    int height;
    char* pixels;
} screen;

screen* create_screen(int width, int height);
char get_pixel(int row, int col, screen* s);
void set_pixel(int row, int col, char value, screen* s);

#endif
