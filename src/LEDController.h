#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <Arduino.h>

class LEDController {
public:
  LEDController(int bluePin, int redPin, int greenPin);

  void begin();
  void setBlue(bool state);
  void setRed(bool state);
  void setGreen(bool state);

private:
  int bluePin;
  int redPin;
  int greenPin;
};

#endif
