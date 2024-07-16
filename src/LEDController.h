#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <stdint.h> // Standard integer types

// LED Controller struct definition
typedef struct {
    uint8_t bluePin;
    uint8_t redPin;
    uint8_t greenPin;
} LEDController;

// Function prototypes
void LEDController_init(LEDController *controller, uint8_t bluePin, uint8_t redPin, uint8_t greenPin);
void LEDController_begin(LEDController *controller);
void LEDController_setBlue(LEDController *controller, uint8_t state);
void LEDController_setRed(LEDController *controller, uint8_t state);
void LEDController_setGreen(LEDController *controller, uint8_t state);

#endif // LED_CONTROLLER_H
