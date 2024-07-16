#include <Arduino.h>
#include "LEDController.h"
#include <SPI.h>

#define LED_BLUE_PIN 5
#define LED_RED_PIN 6
#define LED_GREEN_PIN 7

LEDController ledController(LED_BLUE_PIN, LED_RED_PIN, LED_GREEN_PIN);

void setup() {
  Serial.begin(9600);
  ledController.begin();
}

void loop() {
  static bool blueState = false;
  static bool redState = false;
  static bool greenState = false;

  // Toggle LED states
  blueState = !blueState;
  redState = !redState;
  greenState = !greenState;

  ledController.setBlue(blueState);
  ledController.setRed(redState);
  ledController.setGreen(greenState);

  Serial.print("Blue LED state: ");
  Serial.println(blueState ? "ON" : "OFF");
  Serial.print("Red LED state: ");
  Serial.println(redState ? "ON" : "OFF");
  Serial.print("Green LED state: ");
  Serial.println(greenState ? "ON" : "OFF");

  delay(1000);
}
