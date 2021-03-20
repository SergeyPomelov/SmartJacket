#include <Arduino.h>
#include <Constants.h>
#include <FastLED.h>

#define DATA_PIN 11U

CRGB leds[NUM_LEDS];

void led(const uint8_t red, const uint8_t green, const uint8_t blue)
{
  leds[0] = CRGB(red, green, blue);
  FastLED.show();
}

void ledInit()
{
  pinMode(LED_BUILTIN, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  led(0, 0, 0);
}
