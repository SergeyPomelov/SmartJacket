#include <Arduino.h>
#include <Constants.h>

void ledInit()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
}

void led(const uint8_t red, const uint8_t green, const uint8_t blue)
{
  analogWrite(LED_RED_PIN, red);
  analogWrite(LED_GREEN_PIN, green);
  analogWrite(LED_BLUE_PIN, blue);
  Serial.println(red);
}
