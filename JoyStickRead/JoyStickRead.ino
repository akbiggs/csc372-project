#include "world.h"
#include "input.h"

static struct world* game_world;
static struct input* in;
static char** screen;

int ledPin = 13;
int joyPinX = 0;                 // slider variable connecetd to analog pin 0
int joyPinY = 1;                 // slider variable connecetd to analog pin 1

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
  in = create_input();
  game_world = create_world();
  screen = (char**)malloc(8 * 8);
}

void loop() {
  // reads the value of the variable resistor
  in->joyX = analogRead(joyPinX);
  
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(1);
  
  // reads the value of the variable resistor
  in->joyY = analogRead(joyPinY);
  
  delay(1000);
  Serial.println("wtf");
//  update_world(in, game_world);
  draw_world(game_world, screen);
  Serial.println(screen[0]);
//
//  for (int i = 0; i < 8; i++) {
//    for (int j = 0; j < 8; j++) {
//      Serial.print(screen[i][j]);
//      if (j != 7) {
//        Serial.print(", ");
//      }
//    }
//    Serial.println("x");
//  }
  
  delay(1000);
}
