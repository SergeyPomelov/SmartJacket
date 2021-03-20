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
  Serial.setTimeout(2000);
  while (!Serial)
  {
  }

  ledInit();

  Serial.println(F("initialized"));

  digitalWrite(LED_BUILTIN, LOW);
}

void setColor(int red, int green, int blue)
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

    led(r, g, b);
    delay(30);
  }
}

void loop() {
  setColor(255, 0, 0);   // red
  Serial.println("red");
  setColor(0, 255, 0);   // green
  Serial.println("green");
  setColor(0, 0, 255);   // blue
  Serial.println("blue");
  setColor(255, 255, 0); // yellow
  Serial.println("yellow");
  setColor(80, 0, 80);   // purple
  Serial.println("purple");
  setColor(0, 255, 255); // aqua
  Serial.println("aqua");
}
