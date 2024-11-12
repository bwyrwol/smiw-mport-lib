#ifndef LED_H
#define LED_H

#include <stdint.h>

#define LED0 0x01
#define LED1 0x02
#define LED2 0x04
#define LED3 0x08
#define LED4 0x10
#define LED5 0x20
#define LED6 0x40
#define LED7 0x80

enum LED_STATE {LED_OFF = 0, LED_ON = 1};

extern void led_init(void) __attribute__((constructor, weak));
extern void led_set(uint8_t led) __attribute__((weak));
extern uint8_t led_get(void) __attribute__((weak));

void led_on(uint8_t led);
void led_off(uint8_t led);
void led_toggle(uint8_t led);

void led_shift_left(enum LED_STATE right_led);
void led_shift_right(enum LED_STATE left_led);
void led_rotate_left(void);
void led_rotate_right(void);

#endif//LED_H
