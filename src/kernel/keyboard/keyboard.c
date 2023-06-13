#include <stddef.h>
#include <stdint.h>
#include <io.h>


#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define KEYBOARD_ACK_RESPONSE 0xFA


void keyboard_init(){
	uint8_t status = inb(KEYBOARD_STATUS_PORT);
	outb(KEYBOARD_STATUS_PORT, status &~(1 << 0));
	outb(KEYBOARD_STATUS_PORT, status | (1 << 0) | (1 << 1));
}

uint8_t keyboard_is_pressed(){
	return ((inb(KEYBOARD_STATUS_PORT) & (1 << 0)) != 0);
} 

uint8_t keyboard_read_code(){
	while(!keyboard_is_pressed());

	uint8_t scan_code = inb(KEYBOARD_DATA_PORT);

	if (scan_code == KEYBOARD_ACK_RESPONSE){
		inb(KEYBOARD_DATA_PORT);
	}

	return scan_code;
}
char os2_to_ascii(uint8_t value){

    unsigned char ascii[256] =
	{
		0x0, 0x0, '1', '2', '3', '4', '5', '6',		// 0 - 7
		'7', '8', '9', '0', '-', '=', 0x0, 0x0,		// 8 - 15
		'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',		// 16 - 23
		'o', 'p', '[', ']', '\n', 0x0, 'a', 's',	// 24 - 31
		'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',		// 32 - 39
		'\'', '`', 0x0, '\\', 'z', 'x', 'c', 'v',	// 40 - 47
		'b', 'n', 'm', ',', '.', '/', 0x0, '*',		// 48 - 55
		0x0, ' ', 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,		// 56 - 63
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, '7',		// 64 - 71
		'8', '9', '-', '4', '5', '6', '+', '1',		// 72 - 79
		'2', '3', '0', '.'				// 80 - 83
	};

    return ascii[value];
}
