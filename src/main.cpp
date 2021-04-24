#include <Arduino.h>
#include <Constants.h>
#include <LED.h>

int r = 255U;
int g = 0U;
int b = 0U;
int t = 100U;

void setup() {
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(9600);
  while (!Serial)
  {
  }

  ledInit();

  Serial.println(F("initialized"));

  digitalWrite(LED_BUILTIN, LOW);
}

void setColor(const uint8_t address, const uint8_t red, const uint8_t green, const uint8_t blue)
{
  while (r != red || g != green || b != blue)
  {
    if (r < red)
      r += 1;
    if (r > red)
      r -= 1;

    if (g < green)
      g += 1;
    if (g > green)
      g -= 1;

    if (b < blue)
      b += 1;
    if (b > blue)
      b -= 1;

    led(0, r, g, b);
    led(1, r, g, b);
    led(2, r, g, b);
    led(3, r, g, b);
    led(4, r, g, b);
    led(5, r, g, b);
    led(6, r, g, b);
    delay(30);
  }
}

void loop() {
  setColor(0, 255, 0, 0);   // red
  Serial.println("red");
  setColor(0, 0, 255, 0); // green
  Serial.println("green");
  setColor(0, 0, 0, 255); // blue
  Serial.println("blue");
  setColor(0, 255, 255, 0); // yellow
  Serial.println("yellow");
  setColor(0, 80, 0, 80); // purple
  Serial.println("purple");
  setColor(0, 0, 255, 255); // aqua
  Serial.println("aqua");
}
