#ifndef IO_H
#define IO_H
#include <stdint.h>

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t value);

uint16_t inb_word(uint16_t port);
void outb_word(uint16_t port, uint16_t value);

#endif