#include "timer.h"
#include "../interupts/include/isr.h"
#include "../io/include/io.h"

#include "../../libc/include/stdio.h"

uint32_t tick = 0;

static void timer_callback( __attribute__((unused)) registers_t regs) {
    tick++;
    printf("Tick: %d \n", tick);
}

void init_timer(uint32_t freq) {
    /* Install the function we just wrote */
    register_interrupt_handler(IRQ0, timer_callback);

    printf("\n%d", freq);
    /* Get the PIT value: hardware clock at 1193180 Hz */
    uint32_t divisor = 1193180 / freq;
    uint32_t low  = (uint8_t)(divisor & 0xFF);
    uint32_t high = (uint8_t)( (divisor >> 8) & 0xFF);
    /* Send the command */
    outb(0x43, 0x36); /* Command port */
    outb_word(0x40, low);
    outb_word(0x40, high);
}