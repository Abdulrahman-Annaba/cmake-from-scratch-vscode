#include "blinky-lib/blinky.h"
#include "util/delay.h"
#include "stddef.h"
#include "stdbool.h"

#define MAX_DELAY_MILLISECONDS (262.14 / 16)

void second_resolution_delay(uint16_t seconds) {
    uint16_t iterations = round(seconds / MAX_DELAY_MILLISECONDS * 1000);
    for (uint16_t i = 0; i < iterations; i++)
    {
        _delay_ms(MAX_DELAY_MILLISECONDS);
    }
}

void main() {
    initialize_led();
    while (true)
    {
        turn_on_led();
        second_resolution_delay(1);
        turn_off_led();
        second_resolution_delay(1);
    }
    
}