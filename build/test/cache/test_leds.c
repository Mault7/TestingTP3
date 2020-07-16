#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


uint16_t virtuales;



void setUp(void){



    LedsCreate(&virtuales);



}





void test_todos_los_leds_inician_apagados(void){

    uint16_t virtuales= 0xFFFF;

    LedsCreate(&virtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_UINT16);

}





void test_encender_un_led(void){



    LedsTurnOn(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0001)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_UINT16);



}





void test_encender_y_apagar_un_led(void)

{



    LedsTurnOn(1);

    LedsTurnOff(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_UINT16);



}





void test_prender_y_apagar_varios_leds(void){

    LedsTurnOn(3);

    LedsTurnOn(5);

    LedsTurnOff(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0010)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_UINT16);



}
