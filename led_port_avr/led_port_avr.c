#include "led_port_avr.h"

void led_init(void)
{
	LED_PORT_DIR = 0xFF;
	LED_PORT_OUT = 0xFF;
}

void led_set(uint8_t led)
{
	LED_PORT_OUT = led;
}

uint8_t led_get(void)
{
	return LED_PORT_OUT;
}
