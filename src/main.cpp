#include <Arduino.h>
#include <Constants.h>
#include <LED.h>
#include <LowPower.h>

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);
  while (!Serial) ;
  digitalWrite(LED_BUILTIN, HIGH);
  ledInit();
  Serial.println(F("initialized"));
}

void loop() {
  int r = 255U;
  int g = 0U;
  int b = 0U;
  int t = 100U;

  for (; r >= 0, b < 255; b++, r--)
  {
    led(r, g, b);
    delay(t);
  }

  for (; b >= 0, g < 255; g++, b--)

  {
    led(r, g, b);
    delay(t);
  }

  for (;g >= 0, r < 255; r++, g--)
  {
    led(r, g, b);
    delay(t);
  }
}