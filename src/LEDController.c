#include "LEDController.h"

void LEDController_init(LEDController *ledCtrl, int pinBlue, int pinRed, int pinGreen) {
    ledCtrl->pinBlue = pinBlue;
    ledCtrl->pinRed = pinRed;
    ledCtrl->pinGreen = pinGreen;
    pinMode(ledCtrl->pinBlue, OUTPUT);
    pinMode(ledCtrl->pinRed, OUTPUT);
    pinMode(ledCtrl->pinGreen, OUTPUT);
}

void LEDController_begin(LEDController *ledCtrl) {
    digitalWrite(ledCtrl->pinBlue, LOW);
    digitalWrite(ledCtrl->pinRed, LOW);
    digitalWrite(ledCtrl->pinGreen, LOW);
}

void LEDController_setBlue(LEDController *ledCtrl, uint8_t state) {
    digitalWrite(ledCtrl->pinBlue, state);
}

void LEDController_setRed(LEDController *ledCtrl, uint8_t state) {
    digitalWrite(ledCtrl->pinRed, state);
}

void LEDController_setGreen(LEDController *ledCtrl, uint8_t state) {
    digitalWrite(ledCtrl->pinGreen, state);
}
