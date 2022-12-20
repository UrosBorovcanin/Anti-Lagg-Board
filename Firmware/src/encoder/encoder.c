#include "encoder.h"




/* Encoder Callback*/
/*
        "LEVEL_LOW",  // 0x1
        "LEVEL_HIGH", // 0x2
        "EDGE_FALL",  // 0x4
        "EDGE_RISE"   // 0x8
*/
void encoder_callback(uint gpio, uint32_t events) 
{
    static bool ccw_fall = 0;  //bool used when falling edge is triggered
	static bool cw_fall = 0;


	static bool ledValue = false;
	
	uint8_t enc_value = 0;

    if (!gpio_get(ENC_A))
    {
        enc_value += 1;
    }

    if (!gpio_get(ENC_B))
    {
        enc_value += 2;
    }

	
	if (gpio == ENC_A) 
	{
		if ((!cw_fall) && (enc_value == 0b10)) // cw_fall is set to TRUE when phase A interrupt is triggered
			cw_fall = 1; 

		if ((ccw_fall) && (enc_value == 0b00)) // if ccw_fall is already set to true from a previous B phase trigger, the ccw event will be triggered 
		{
			cw_fall = 0;
			ccw_fall = 0;
			//do something here
            gpio_put(25, ledValue);
			ledValue = !ledValue;
		}

	}	


	if (gpio == ENC_B) 
	{
		if ((!ccw_fall) && (enc_value == 0b01)) //ccw leading edge is true
			ccw_fall = 1;

		if ((cw_fall) && (enc_value == 0b00)) //cw trigger
		{
			cw_fall = 0;
			ccw_fall = 0;
			//do something here
            gpio_put(25, ledValue);
			ledValue = !ledValue;
		}

	}
	
}

void encoder_callback1(uint gpio, uint32_t events)
{
	static bool ccw = false, cw = false;

	static bool ledValue = false;

	static uint64_t lastCallTime = 0, currentCallTime = 0;

	currentCallTime = time_us_64();

	if ((currentCallTime - lastCallTime) > 10000)
	{
		lastCallTime = currentCallTime;
			
		if (gpio_get(ENC_B))
		{
			ccw = true;
			cw = false;
			gpio_put(25, ledValue);
			ledValue = !ledValue;
		}
		else 
		{
			cw = true;
			ccw = false;
			gpio_put(25, ledValue);
			ledValue = !ledValue;
		}
	}
}

void encoder_init()
{
    gpio_init(ENC_SW);					//Initialise a GPIO for (enabled I/O and set func to GPIO_FUNC_SIO)
    gpio_set_dir(ENC_SW,GPIO_IN);
	gpio_pull_up(ENC_SW);

	gpio_init(ENC_A);
    gpio_set_dir(ENC_A,GPIO_IN);
	gpio_pull_up(ENC_A);

	gpio_init(ENC_B);
    gpio_set_dir(ENC_B,GPIO_IN);
	gpio_pull_up(ENC_B);

	gpio_set_irq_enabled_with_callback(ENC_SW, GPIO_IRQ_EDGE_FALL, true, &encoder_callback1);
    gpio_set_irq_enabled(ENC_A, GPIO_IRQ_EDGE_FALL, true);
	//gpio_set_irq_enabled(ENC_B, GPIO_IRQ_EDGE_FALL, true);
}