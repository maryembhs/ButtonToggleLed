

#ifndef __GPIO_H
#define __GPIO_H

#include <stdint.h>
#include <assert.h>

#define GPIOA                   (uint32_t*)0x40020000
#define GPIOD                   (uint32_t*)0x40020c00

#define PIN0                    0u
#define PIN12                   12u
#define PIN15                   15u

#define INPUT                   0x0u
#define OUTPUT                  0x1u

void  InputOutputConfig (uint32_t *GPIOx, uint8_t Pin, uint8_t Mode);
uint8_t  ButtonToggleLed(uint32_t *GPIOx, uint8_t Pin);

#endif