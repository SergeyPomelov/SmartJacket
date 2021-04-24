#include <Arduino.h>
#include <Constants.h>
#include <FastLED.h>

#define DATA_PIN 1U

CRGB leds[NUM_LEDS];

void led(const uint8_t led, const uint8_t red, const uint8_t green, const uint8_t blue)
{
  leds[led] = CRGB(red, green, blue);
  FastLED.show();
}

void ledInit()
{
  pinMode(LED_BUILTIN, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  led(0, 0, 0, 0);
  led(1, 0, 0, 0);
  led(2, 0, 0, 0);
  led(3, 0, 0, 0);
  led(4, 0, 0, 0);
}
