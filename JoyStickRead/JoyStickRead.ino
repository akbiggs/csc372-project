#include <stdlib.h>

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

#include "world.h"
#include "input.h"
#include "screen.h"

int ledPin = 13;
int joyPinX = 1;                 // slider variable connecetd to analog pin 0
int joyPinY = 0;                 // slider variable connecetd to analog pin 1

static world* game_world;
static input* in;
static screen* game_screen;

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  matrix.begin(0x70);
  matrix.blinkRate(2);
  
  in = create_input();
  game_screen = create_screen(8, 8);
  game_world = create_world(game_screen->width, game_screen->height);
}

void loop() {
  in->joyX = (UPPER_THRESHOLD + LOWER_THRESHOLD) / 2;
  in->joyY = (UPPER_THRESHOLD + LOWER_THRESHOLD) / 2;

  delay(game_world->game_player->move_delay);
 
  // reads the value of the variable resistor
  in->joyX = analogRead(joyPinX);
  
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(1);
  
  // reads the value of the variable resistor
  in->joyY = analogRead(joyPinY);
  
  update_world(in, game_world);
  draw_world(game_world, game_screen);

  matrix.clear();
  
  for (int i = 0; i < game_screen->height; i++) {
    for (int j = 0; j < game_screen->width; j++) {
      char pixel = get_pixel(i, j, game_screen);
      matrix.drawPixel(j, i, pixel == '1' ? LED_ON : LED_OFF);
      
//      Serial.print(get_pixel(i, j, game_screen));
//      if (j != game_screen->width - 1) {
//        Serial.print(", ");
//      }
    }
//    Serial.println("");
  }
  
  matrix.writeDisplay();
  
//  delay(300);
}
