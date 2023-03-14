#include "encoder.h"
#include "oled/oled.h"



/* Encoder Callback*/
/*
        "LEVEL_LOW",  // 0x1
        "LEVEL_HIGH", // 0x2
        "EDGE_FALL",  // 0x4
        "EDGE_RISE"   // 0x8
*/
#define ENCODER_RESOLUTION 2;

static int8_t encoderLUT[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

static uint8_t encoderState = 0;

static int8_t encoderPulses = 0;

static bool changed = false;

void encoder_init()
{
    //gpio_init(ENC_SW);					//Initialise a GPIO for (enabled I/O and set func to GPIO_FUNC_SIO)
    //gpio_set_dir(ENC_SW,GPIO_IN);
	//gpio_pull_up(ENC_SW);

	gpio_init(ENC_A);
    gpio_set_dir(ENC_A,GPIO_IN);
	gpio_pull_up(ENC_A);

	gpio_init(ENC_B);
    gpio_set_dir(ENC_B,GPIO_IN);
	gpio_pull_up(ENC_B);

	gpio_set_irq_enabled_with_callback(ENC_A, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &encoder_callback);
    gpio_set_irq_enabled_with_callback(ENC_B, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &encoder_callback);
	//gpio_set_irq_enabled(ENC_SW, GPIO_IRQ_EDGE_FALL, true);

	encoderState |= (gpio_get(ENC_A) << 0) | (gpio_get(ENC_B) << 1);
}

void encoder_callback(uint gpio, uint32_t events)
{
	bool aState = gpio_get(ENC_A), bState = gpio_get(ENC_B);

    uint8_t newState = 0;

    newState |= aState;
    newState |= (bState << 1);

    encoderState = encoderState << 2;

    encoderState |= newState;

    changed = true;

    const uint8_t resolution = ENCODER_RESOLUTION;

    encoderPulses += encoderLUT[encoderState & 0xF];

    if (encoderPulses >= resolution) 
    {
        gpio_put(25, true);
    }

    if (encoderPulses <= -resolution) 
    {
        gpio_put(25, false);
    }

    encoderPulses %= resolution;
}
