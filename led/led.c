#include "led.h"

// active state is 0

void led_on(uint8_t led)
{
	led_set(led_get() & ~led);
}

void led_off(uint8_t led)
{
	led_set(led_get() | led);
}

void led_toggle(uint8_t led)
{
	led_set(led_get() ^ led);
}

void led_shift_left(enum LED_STATE right_led)
{
	uint8_t tled = led_get();
	
	tled = tled << 1;
	if (right_led == LED_ON) tled &= 0xFE;
	else tled |= 0x01;
	
	led_set(tled);
}

void led_shift_right(enum LED_STATE left_led)
{
	uint8_t tled = led_get();
	
	tled = tled >> 1;
	if (left_led == LED_ON) tled &= 0x7F;
	else tled |= 0x80;
	
	led_set(tled);
}

void led_rotate_left(void)
{
	uint8_t tled = led_get();
	
	if ((tled & 0x80) == 0)
	  led_shift_left(LED_ON);
	else
	  led_shift_left(LED_OFF);
}

void led_rotate_right(void)
{
	uint8_t tled = led_get();
	
	if ((tled & 0x01) == 0)
	  led_shift_right(LED_ON);
	else
	  led_shift_right(LED_OFF);
}
