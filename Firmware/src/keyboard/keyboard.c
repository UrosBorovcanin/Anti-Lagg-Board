

#include "keyboard.h"
#include "bsp/board.h"

//A function that calculates the mask for the matrix pins of the keyboard
void initialize_kbd_gpio()
{
  uint8_t colPins[] = COL_PINS;
  uint8_t rowPins[] = ROW_PINS;

  for (int i = 0; i < NUMBER_OF_COL_PINS; i++)
  {
    gpio_init(colPins[i]);
    gpio_pull_up(colPins[i]);
  }

  for (int i = 0; i < NUMBER_OF_ROW_PINS; i++)
  {
    gpio_init(rowPins[i]);
  }
}


//A function that calculates the mask for the column pins of the keyboard matrix
void set_kbd_input_pins()
{
  uint8_t colPins[] = COL_PINS;

  for (int i = 0; i < NUMBER_OF_COL_PINS; i++)
  {
    gpio_set_dir(colPins[i], false);
  }
}


//A function that calculates the mask for the row pins of the keyboard matrix
void set_kbd_output_pins()
{
  uint8_t rowPins[] = ROW_PINS;

  for (int i = 0; i < NUMBER_OF_ROW_PINS; i++)
  {
    gpio_set_dir(rowPins[i], true);
  }
}


//A function that goes through columns, then rows of pins and checks for connections between them
//thus detecting keypresses
bool detect_keypresses(KEY_VALUE *keyList)
{
  bool keyPressDetected = false;

  int keyMatrix[NUMBER_OF_COL_PINS][NUMBER_OF_ROW_PINS] = KEY_MATRIX;
  uint8_t rowPins[] = ROW_PINS;
  uint8_t colPins[] = COL_PINS;

  advance_debounce_countdown(keyList);

  for (int i = 0; i < NUMBER_OF_COL_PINS; i++)
  {
    for (int j = 0; j < NUMBER_OF_ROW_PINS; j++)
    {
      if (keyMatrix[i][j] > -1)
      {
        gpio_put(rowPins[j], false);

        int currentPinNumber = keyMatrix[i][j];

        if (!gpio_get(colPins[i]))
        {
          if (keyList[currentPinNumber].value == false)
          {
            keyList[currentPinNumber].debounceCountdown = DEBOUNCE_TIME;
          }
          keyList[currentPinNumber].value = true;

          keyPressDetected = true;
        }
        else 
        {
          if (keyList[currentPinNumber].debounceCountdown == 0)
          {
            keyList[currentPinNumber].value = false;
          }
        }

        gpio_put(rowPins[j], true);
      }
    }
  }
  return keyPressDetected;
}


//A function used to manage the debounce timers on key presses
void advance_debounce_countdown(KEY_VALUE *keyList)
{
  static uint64_t lastCallTime = 0;
  uint64_t currentCallTime = time_us_64();
  uint64_t callTimeDelta = currentCallTime - lastCallTime;
  lastCallTime = currentCallTime;

  for (int i = 0; i < TOTAL_NUMBER_OF_KEYS; i++)
  {
    if (keyList[i].value)
    {
      if (keyList[i].debounceCountdown > 0)
      {
        if (keyList[i].debounceCountdown <= callTimeDelta)
        {
          keyList[i].debounceCountdown = 0;
        }
        else 
        {
          keyList[i].debounceCountdown -= callTimeDelta;
        }
      }
    }
  }
}

//A function used to translate keypresses(after the debounce period) into a bitmap message to send via USB
bool translate_keypresses_to_bitmap(KEY_VALUE *keyList, uint8_t *bitmap)
{
  bool hasKey = false;

  uint8_t layerZeroMap[TOTAL_NUMBER_OF_KEYS][2] = KEYBINDS_LAYER_0;

  for (int i = 0; i < TOTAL_NUMBER_OF_KEYS; i++)
  {
    //if ((keyList[i].value) && (keyList[i].debounceCountdown == 0))
    {
      bitmap[layerZeroMap[i][0]] | layerZeroMap[i][1];
      hasKey = true;
    }
  }
  
  return hasKey;
}