#include "LEDController.h"
#include <Arduino.h> // Arduino framework

void LEDController_init(LEDController *controller, uint8_t bluePin, uint8_t redPin, uint8_t greenPin) {
    controller->bluePin = bluePin;
    controller->redPin = redPin;
    controller->greenPin = greenPin;
}

void LEDController_begin(LEDController *controller) {
    pinMode(controller->bluePin, OUTPUT);
    pinMode(controller->redPin, OUTPUT);
    pinMode(controller->greenPin, OUTPUT);
}

void LEDController_setBlue(LEDController *controller, uint8_t state) {
    digitalWrite(controller->bluePin, state);
}

void LEDController_setRed(LEDController *controller, uint8_t state) {
    digitalWrite(controller->redPin, state);
}

void LEDController_setGreen(LEDController *controller, uint8_t state) {
    digitalWrite(controller->greenPin, state);
}
