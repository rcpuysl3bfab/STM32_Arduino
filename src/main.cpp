#include <Arduino.h>
#include "LEDController.h"

#define LED_BLUE_PIN 5
#define LED_RED_PIN 6
#define LED_GREEN_PIN 7

LEDController ledController;

void setup() {
    Serial.begin(9600);
    LEDController_init(&ledController, LED_BLUE_PIN, LED_RED_PIN, LED_GREEN_PIN);
    LEDController_begin(&ledController);
}

void loop() {
    static uint8_t blueState = LOW;
    static uint8_t redState = LOW;
    static uint8_t greenState = LOW;

    blueState = !blueState;
    redState = !redState;
    greenState = !greenState;

    LEDController_setBlue(&ledController, blueState);
    LEDController_setRed(&ledController, redState);
    LEDController_setGreen(&ledController, greenState);

    Serial.print("Blue LED state: ");
    Serial.println(blueState ? "ON" : "OFF");
    Serial.print("Red LED state: ");
    Serial.println(redState ? "ON" : "OFF");
    Serial.print("Green LED state: ");
    Serial.println(greenState ? "ON" : "OFF");

    delay(1000);
}
