#include <stdint.h>

void LedsCreate(uint16_t *direccion);

void LedsTurnOn(uint8_t led);

void LedsTurnOff(uint8_t led);

void LedsTurnAllOn(void);

void LedsTurnAllOff(void);

uint16_t LedState(uint16_t led);