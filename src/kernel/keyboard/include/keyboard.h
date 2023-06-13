#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <stddef.h>
#include <stdint.h>

char os2_to_ascii(uint8_t value);


void keyboard_init();

uint8_t keyboard_is_pressed();

uint8_t keyboard_read_code();

#endif