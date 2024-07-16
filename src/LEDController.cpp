#include "LEDController.h"

LEDController::LEDController(int bluePin, int redPin, int greenPin) {
  this->bluePin = bluePin;
  this->redPin = redPin;
  this->greenPin = greenPin;
}

void LEDController::begin() {
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void LEDController::setBlue(bool state) {
  digitalWrite(bluePin, state ? HIGH : LOW);
}

void LEDController::setRed(bool state) {
  digitalWrite(redPin, state ? HIGH : LOW);
}

void LEDController::setGreen(bool state) {
  digitalWrite(greenPin, state ? HIGH : LOW);
}
