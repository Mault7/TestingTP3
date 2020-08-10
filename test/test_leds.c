/**
*Todos los leds empiezan apagados
*Encender un led
*Prender y apagar un led
*Prender y apagar algunos leds
*Asegurarse que un led no afecta los demas
*Prender todos los leds simultaneamente
*Apagar todos los leds simultamneamente
*Consultar el estado de un led
*/
#include "unity.h"
#include "leds.h"



uint16_t virtuales;

void setUp(void)
{

    LedsCreate(&virtuales);
}

//! @test Todos los leds empiezan apagados
void test_todos_los_leds_inician_apagados(void)
{
    uint16_t virtuales = 0xFFFF;
    LedsCreate(&virtuales);

    TEST_ASSERT_EQUAL_UINT16(0x0000, virtuales);
}

// !@test Encender un led
void test_encender_un_led(void)
{

    LedsTurnOn(1);

    TEST_ASSERT_EQUAL_UINT16(0x0001, virtuales);
}

//!@test Prender y apagar un led
void test_encender_y_apagar_un_led(void)
{

    LedsTurnOn(1);
    LedsTurnOff(1);

    TEST_ASSERT_EQUAL_UINT16(0x0000, virtuales);
}

//!@test Prender y apagar algunos leds
void test_prender_y_apagar_varios_leds(void)
{
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOff(3);

    TEST_ASSERT_EQUAL_UINT16(0x0010, virtuales);
}

//!@test_Asegurarse que un led no afecta los demas
void test_asegurarse_que_un_led_no_afecta_a_los_demas(void)
{
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOn(7);
    LedsTurnOn(9);
    LedsTurnOff(5);
    LedsTurnOff(7);

    TEST_ASSERT_EQUAL_UINT16(0x0104, virtuales);
}

//!@test Prender todos los leds simultaneamente
void test_prender_todos_los_leds_simultaneamente(void)
{
    LedsTurnAllOn();

    TEST_ASSERT_EQUAL_UINT16(0xFFFF, virtuales);
}
//!@test Apagar todos los leds simultamneamente
void test_apagar_todos_los_leds_simultaneamente(void)
{

    LedsTurnAllOn();
    LedsTurnAllOff();

    TEST_ASSERT_EQUAL_UINT16(0, virtuales);
}

//!@test Consultar el estado de un led
void test_consultar_el_estado_de_un_led(void)
{

    LedsTurnAllOn();
    LedsTurnOff(8);


    TEST_ASSERT_EQUAL_UINT16(1, LedState(2));
    TEST_ASSERT_EQUAL_UINT16(0, LedState(8));
}