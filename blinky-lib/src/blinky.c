#include "blinky.h"
#include "avr/io.h"

void initialize_led() {
    DDRB |= (1 << PORTB5);
}

void turn_on_led() {
    PORTB |= (1 << PORTB5);
}

void turn_off_led() {
    PORTB &= ~(1 << PORTB5);
}