/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
modified for GEMMA sequin masquerade mask
****************************************/
#include <Adafruit_NeoPixel.h>
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
int LED_PIN = 1;           // the pin that the LED is attached to
int N_PIXELS = 63;
int MIC_PIN = 2;
int noise = 100;
int brightness = 0;    // how bright the LED is
unsigned int minMaxAve = 0;

Adafruit_NeoPixel  strip = Adafruit_NeoPixel(N_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);


uint32_t red = strip.Color(50, 0, 0);
uint32_t off = strip.Color(0, 0, 0);
 
void setup() 
{
   pinMode(MIC_PIN, INPUT);
   strip.begin();
   SetBigHeart();
}
 
 
void loop() 
{
  unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 2048;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(1);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 3.3) / 1024;  // convert to volts
   int brightness = map(peakToPeak, 0, 1023, 0, 255);
   red = strip.Color(brightness, 0, 0);
   SetBigHeart();
}


static void SetBigHeart(){ 
  for(uint16_t i=0; i<63; i++) {
      strip.setPixelColor(i, red);
  }
  strip.show();
}

static void SetMediumHeart(){
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


static void SetLittleHeart(){
  for(uint16_t i=44; i<63; i++) {
      strip.setPixelColor(i, off);
  }
  
  strip.setPixelColor(41, off);
  
  for(uint16_t i=34; i<39; i++) {
      strip.setPixelColor(i, off);
  }

  for(uint16_t i=23; i<27; i++) {
      strip.setPixelColor(i, off);
  }

  for(uint16_t i=14; i<18; i++) {
      strip.setPixelColor(i, off);
  }

  for(uint16_t i=7; i<11; i++) {
      strip.setPixelColor(i, off);
  }
  
  for(uint16_t i=0; i<6; i++) {
      strip.setPixelColor(i, off);
  }
  strip.show();
}

