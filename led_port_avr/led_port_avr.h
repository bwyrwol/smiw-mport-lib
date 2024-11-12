#ifndef LED_AVRPORT_H
#define LED_AVRPORT_H

#include "..\led\led.h"
#include "main.h"
#include <avr/io.h>

// deklaracja makr
#define DDR(x)  _SFR_IO8(_SFR_IO_ADDR(x)-1)
#define PIN(x)  _SFR_IO8(_SFR_IO_ADDR(x)-2)
#define PORT(x) _SFR_IO8(_SFR_IO_ADDR(x)-0)

// deklaracja sposobu dolaczenia urzadzen we/wy do portu
#define LED_PORT_OUT PORT(LED_PORT)
#define LED_PORT_DIR DDR(LED_PORT)

void led_init(void);
void led_set(uint8_t led);
uint8_t led_get(void);

#endif//LED_AVRPORT_H
