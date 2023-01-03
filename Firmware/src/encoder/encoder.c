#include "encoder.h"
#include "oled/oled.h"



/* Encoder Callback*/
/*
        "LEVEL_LOW",  // 0x1
        "LEVEL_HIGH", // 0x2
        "EDGE_FALL",  // 0x4
        "EDGE_RISE"   // 0x8
*/

void encoder_callback(uint gpio, uint32_t events)
{
	static bool ccw = false, cw = false;

	static bool ledValue = false;

	static bool screenValue = false;

	static uint64_t lastCallTime = 0;
	uint64_t currentCallTime = 0;
	
	lastCallTime = currentCallTime;
	
	if (gpio == ENC_SW)
	{
		screenValue = !screenValue;

		if (screenValue)
		{
			oled_send_cmd(0xA5);
		}
		else
		{
			oled_send_cmd(0xA4);
		}
	}

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

	gpio_set_irq_enabled_with_callback(ENC_A, GPIO_IRQ_EDGE_FALL, true, &encoder_callback);
    gpio_set_irq_enabled(ENC_B, GPIO_IRQ_EDGE_FALL, true);
	gpio_set_irq_enabled(ENC_SW, GPIO_IRQ_EDGE_FALL, true);
}