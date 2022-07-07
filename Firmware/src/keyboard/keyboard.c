

#include "keyboard.h"

//A function that calculates the mask for the matrix pins of the keyboard
uint32_t kbd_mask()
{
  uint32_t mask = 0;

  mask |= col_pin_mask();

  mask |= row_pin_mask();  
  
  return mask;
}


//A function that calculates the mask for the column pins of the keyboard matrix
uint32_t col_pin_mask()
{
  uint32_t mask = 0;

  uint8_t colPins[] = COL_PINS;

  for (int i = 0; i < NUMBER_OF_COL_PINS; i++)
  {
    uint32_t currentKeyMask = 1;
    currentKeyMask << colPins[i];

    mask |= currentKeyMask;
  }

  return mask;
}


//A function that calculates the mask for the row pins of the keyboard matrix
uint32_t row_pin_mask()
{
  uint32_t mask = 0;

  uint8_t rowPins[] = ROW_PINS;

  for (int i = 0; i < NUMBER_OF_ROW_PINS; i++)
  {
    uint32_t currentKeyMask = 1;
    currentKeyMask << rowPins[i];

    mask |= currentKeyMask;
  }

  return mask;
}


//A function that goes through columns, then rows of pins and checks for connections between them
//thus detecting keypresses
bool detect_keypresses(KEY_VALUE *keyList)
{
  bool numberOfKeyPresses = 0;

  int keyMatrix[NUMBER_OF_COL_PINS][NUMBER_OF_ROW_PINS] = KEY_MATRIX;
  uint8_t rowPins[] = ROW_PINS;
  uint8_t colPins[] = COL_PINS;

  advance_debounce_countdown(keyList);

  for (int i = 0; i < NUMBER_OF_COL_PINS; i++)
  {
    gpio_pull_up(colPins[i]);
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
    gpio_pull_down(colPins[i]);
  }
  return numberOfKeyPresses;
}


//A function used to manage the debounce timers on key presses
void advance_debounce_countdown(KEY_VALUE *keyList)
{
  static uint64_t lastCallTime = 0;
  uint64_t currentCallTime = time_us_64();
  uint64_t callTimeDelta = currentCallTime - lastCallTime;

  for (int i = 0; i < TOTAL_NUMBER_OF_KEYS; i++)
  {
    if (keyList[i].value == true)
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
void translate_keypresses_to_bitmap(KEY_VALUE *keyList, uint8_t *bitmap)
{
  uint8_t keyMatrix[NUMBER_OF_COL_PINS][NUMBER_OF_ROW_PINS] = KEY_MATRIX;

  uint16_t layerZeroMap[TOTAL_NUMBER_OF_KEYS][2] = KEYBINDS_LAYER_0;

  for (int i = 0; i < TOTAL_NUMBER_OF_KEYS; i++)
  {
    if ((keyList[i].value) && (keyList[i].debounceCountdown == 0))
    {
      
    }
  }
}