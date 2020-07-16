/**
*Todos los leds empiezan apagados
*Encender un led
*Prender y apagar un led
*Prender y apagar algunos leds
*Asegurarse que un led no afecta los demas
*Prender todos los leds simultaneamente
*Apagar todos los leds simultamneamente
*Consultar el estado de un led
*Patametros son invalidos
*Parametros en los valores de borde bit mas significativo y bit menos significativo
*/
#include "unity.h"
#include "leds.h"

uint16_t virtuales;

void setUp(void){

    LedsCreate(&virtuales);

}

//! @test Todos los leds empiezan apagados
void test_todos_los_leds_inician_apagados(void){
    uint16_t virtuales= 0xFFFF;
    LedsCreate(&virtuales);
    TEST_ASSERT_EQUAL_UINT16(0x0000,virtuales);
}

// !@test Encender un led 
void test_encender_un_led(void){

    LedsTurnOn(1);
    TEST_ASSERT_EQUAL_UINT16(0x0001,virtuales);

}

//!@test Prender y apagar un led
void test_encender_y_apagar_un_led(void)
{
  
    LedsTurnOn(1);
    LedsTurnOff(1);
    TEST_ASSERT_EQUAL_UINT16(0x0000,virtuales);

}

//!@test Prender y apagar algunos leds
void test_prender_y_apagar_varios_leds(void){
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOff(3);
    TEST_ASSERT_EQUAL_UINT16(0x0010,virtuales);

}