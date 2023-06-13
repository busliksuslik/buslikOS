#include <stdint.h>

uint8_t inb(uint16_t port){
	uint8_t data;

	__asm__ __volatile__ (
		"inb %1" :
		 "=a" (data) :
		"dN" (port));

	return data;
}

void outb(uint16_t port, uint8_t value){

	__asm__ __volatile__ (
		"outb %0, %1" :
		 "=a" (value) :
		"Nd" (port)
		);
}

uint16_t inb_word(uint16_t port){
	uint16_t data;
	__asm__("in %%dx, %%ax" : 
	"=a" (data) : 
	"d" (port));

	return data;
}

void outb_word(uint16_t port, uint16_t value){

	__asm__ __volatile__ (
		"out %0, %1" :
		 "=a" (value) :
		"Nd" (port)
		);
}