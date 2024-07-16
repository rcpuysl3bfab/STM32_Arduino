#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

// LEDController yapısı
typedef struct {
    int pinBlue;
    int pinRed;
    int pinGreen;
} LEDController;

// LEDController fonksiyonları
void LEDController_init(LEDController *ledCtrl, int pinBlue, int pinRed, int pinGreen);
void LEDController_begin(LEDController *ledCtrl);
void LEDController_setBlue(LEDController *ledCtrl, uint8_t state);
void LEDController_setRed(LEDController *ledCtrl, uint8_t state);
void LEDController_setGreen(LEDController *ledCtrl, uint8_t state);

#ifdef __cplusplus
}
#endif

#endif // LED_CONTROLLER_H
