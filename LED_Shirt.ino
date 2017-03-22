// Simple NeoPixel test.  Lights just a few pixels at a time so a
// 1m strip can safely be powered from Arduino 5V pin.  Arduino
// may nonetheless hiccup when LEDs are first connected and not
// accept code.  So upload code first, unplug USB, connect pixels
// to GND FIRST, then +5V and digital pin 6, then re-plug USB.
// A working strip will show a few pixels moving down the line,
// cycling between red, green and blue.  If you get no response,
// might be connected to wrong end of strip (the end wires, if
// any, are no indication -- look instead for the data direction
// arrows printed on the strip).
 
#include <Adafruit_NeoPixel.h>
 
#define PIN      1
#define N_LEDS  63
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t red = strip.Color(100, 0, 0);
uint32_t off = strip.Color(0, 0, 0);

void setup() {
  strip.begin();
  SetBigHeart();
  SetLittleHeart();
}
 
void loop() {
  delay(1000);
  SetBigHeart();
  delay(250);
  SetLittleHeart();
}


static void SetBigHeart(){
  for(uint16_t i=0; i<63; i++) {
      strip.setPixelColor(i, red);
  }
  strip.show();
}

static void SetLittleHeart(){
  for(uint16_t i=55; i<63; i++) {
      strip.setPixelColor(i, off);
  }

  strip.setPixelColor(52, off);
  strip.setPixelColor(51, off);

  for(uint16_t i=46; i<49; i++) {
      strip.setPixelColor(i, off);
  }

  strip.setPixelColor(41, off);

  strip.setPixelColor(36, off);
  strip.setPixelColor(35, off);
  
  strip.setPixelColor(25, off);
  strip.setPixelColor(24, off);

  strip.setPixelColor(16, off);
  strip.setPixelColor(15, off);

  strip.setPixelColor(9, off);
  strip.setPixelColor(8, off);

  strip.setPixelColor(4, off);
  strip.setPixelColor(3, off);

  strip.setPixelColor(1, off);
  strip.setPixelColor(0, off);
  
  strip.show();
}
<<<<<<< HEAD

=======

>>>>>>> 7ca6a74259dbd21d7351d60e0e1005e10baa4eb6
