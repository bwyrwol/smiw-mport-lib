#include "main.h"

void main(void)
{
	led_on(LED1 | LED3 | LED5 | LED7);
	//led_on(LED1);

	for(;;)
	{
		led_toggle(LED1 | LED3 | LED5 | LED7);
		//led_rotate_right();
		_delay_ms(200);
	}
}
