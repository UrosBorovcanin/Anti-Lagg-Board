#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "stdlib.h"

/*Encoder GPIO*/
// GPIO 10 is Encoder phase A,  
// GPIO 11 is Encoder phase B,
// GPIO 12 is the encoder push botton switch.
// change these as needed

#define ENC_A	3
#define ENC_B	7
#define ENC_SW	2

void encoder_callback(uint gpio, uint32_t events);

void encoder_callback1(uint gpio, uint32_t events);

void encoder_init();