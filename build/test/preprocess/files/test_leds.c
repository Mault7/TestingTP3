#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"






uint16_t virtuales;



void setUp(void)

{



    LedsCreate(&virtuales);

}





void test_todos_los_leds_inician_apagados(void)

{

    uint16_t virtuales = 0xFFFF;

    LedsCreate(&virtuales);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_UINT16);

}





void test_encender_un_led(void)

{



    LedsTurnOn(1);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0001)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_UINT16);

}





void test_encender_y_apagar_un_led(void)

{



    LedsTurnOn(1);

    LedsTurnOff(1);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_UINT16);

}





void test_prender_y_apagar_varios_leds(void)

{

    LedsTurnOn(3);

    LedsTurnOn(5);

    LedsTurnOff(3);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0010)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_UINT16);

}





void test_asegurarse_que_un_led_no_afecta_a_los_demas(void)

{

    LedsTurnOn(3);

    LedsTurnOn(5);

    LedsTurnOn(7);

    LedsTurnOn(9);

    LedsTurnOff(5);

    LedsTurnOff(7);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0104)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_UINT16);

}





void test_prender_todos_los_leds_simultaneamente(void)

{

    LedsTurnAllOn();



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0xFFFF)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_UINT16);

}



void test_apagar_todos_los_leds_simultaneamente(void)

{



    LedsTurnAllOn();

    LedsTurnAllOff();



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_UINT16);

}





void test_consultar_el_estado_de_un_led(void)

{



    LedsTurnAllOn();

    LedsTurnOff(8);





    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((1)), (UNITY_INT)(UNITY_UINT16)((LedState(2))), (

   ((void *)0)

   ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((LedState(8))), (

   ((void *)0)

   ), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_UINT16);

}
