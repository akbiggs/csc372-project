#define ARDUINO_H

#include <stdlib.h>

#include <Wire.h>
#include <Adafruit_NFCShield_I2C.h>
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
int start = 0;

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

#define IRQ   (2)
#define RESET (3)  // Not connected by default on the NFC Shield

int incomingByte = 0;

Adafruit_NFCShield_I2C nfc(IRQ, RESET);

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  matrix.begin(0x70);
  matrix.blinkRate(2);

  in = create_input();
  game_screen = create_screen(8, 8);
  game_world = create_world(game_screen->width, game_screen->height);
  
  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board, please try again.");
    while (1); // halt
  }
  
  nfc.SAMConfig();
  
  Serial.println("Waiting for an ISO14443A Card ...");
}

void loop() {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
    
  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength); 
  
  Serial.println(success);
  
  in->joyX = (UPPER_THRESHOLD + LOWER_THRESHOLD) / 2;
  in->joyY = (UPPER_THRESHOLD + LOWER_THRESHOLD) / 2;

  delay(FLASH_DELAY);
 
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
