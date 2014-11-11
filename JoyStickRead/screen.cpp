#include "screen.h"


screen* create_screen(int width, int height) {
    screen* result = (screen*)malloc(sizeof(screen));

    result->width = width;
    result->height = height;
    result->pixels = (char*)malloc(width * height);

    return result;
}

char get_pixel(int row, int col, screen* s) {
    return s->pixels[row * s->width + col];
}

void set_pixel(int row, int col, char value, screen* s) {
    s->pixels[row * s->width + col] = value;
}
