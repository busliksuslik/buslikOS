#include<tty.h>
#include<keyboard.h>
#include<stdio.h>
#include<gdt.h>
#include<interupts/include/isr.h>
#include <timer/include/timer.h>

struct gdt {
        unsigned int address;
        unsigned short size;
} __attribute__((packed));

void kernel_main(void) 
{

	/* Initialize terminal interface */
	terminal_initialize();
	keyboard_init();
	printf("%d", 37);
	init_gdt();
	isr_install();

	asm volatile("sti");
    init_timer(50);

	printf("%d", 37);
 
	/* Newline support is left as an exercise. */
	
	while(1){
		//printf("Hello world ");

		char lol = os2_to_ascii(keyboard_read_code());
		if (lol != 0){
			terminal_putchar(lol);
		}
		
		
	}
	printf("%d", 37);
}