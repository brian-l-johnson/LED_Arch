#include <Arduino.h>
#include <FastLED.h>

#include "fire.h"

#define DATA_PIN 5
//ws2815 seems to just be the 12v version of ws2813, so as far as the code cares they are the same
#define LED_TYPE WS2813 
#define COLOR_ORDER RGB
#define NUM_LEDS 300

#define BRIGHTNESS 96
#define FRAMES_PER_SECOND 120

CRGB leds[NUM_LEDS];
CRGB colorArray[3];
int colorIndex;

void setup() {
  delay(3000); //3 second delay on startup
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  colorArray[0] = CRGB::OrangeRed;
  colorArray[1] = CRGB::Indigo;
  colorArray[2] = CRGB::Green;

  colorIndex = 0;

}

int i = 0;



void loop() {
  ClassicFireEffect fire(NUM_LEDS, 250, 10, 3, 5, true, true);

  while (true)
  {
    FastLED.clear();
    fire.DrawFire();
    FastLED.show(BRIGHTNESS);
    delay(3);
  }
  /*
  if(i == NUM_LEDS) {
    i = 0;
    colorIndex++;
    if(colorIndex >2) {
      colorIndex = 0;
    }

  }
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS,1);
  FastLED.delay(1000/FRAMES_PER_SECOND);

  leds[i] = colorArray[colorIndex];
  i++;
  */


}