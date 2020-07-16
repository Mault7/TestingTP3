#include "leds.h"

#define LEDS_ALL_OFF 0x0000
#define LEDS_TO_BITS_OFFSET 1
#define LEDS_BIT_ON 1

uint16_t * puerto;

uint8_t LedTobit(uint8_t led){
    return (led-LEDS_TO_BITS_OFFSET);
}

uint16_t BitMask(uint8_t bit){
    return (LEDS_BIT_ON<<bit);
}

void LedsCreate(uint16_t *direccion){
    puerto=direccion;
    *direccion=LEDS_ALL_OFF;
}

void LedsTurnOn(uint8_t led){
    *puerto |=(1<<(led-1));
}

void LedsTurnOff(uint8_t led){
    *puerto &= ~(1<<(led-1));

}