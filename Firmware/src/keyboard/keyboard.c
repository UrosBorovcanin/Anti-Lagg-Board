

#include "keyboard.h"

//A function that calculates the mask for the matrix pins of the keyboard
uint32_t kbd_mask()
{
  uint32_t mask = 0;

  uint8_t rowPins[] = {ROW_PIN_0, ROW_PIN_1, ROW_PIN_2, ROW_PIN_3, ROW_PIN_4};
  uint8_t colPins[] = {COL_PIN_0, COL_PIN_1, COL_PIN_2, COL_PIN_3, COL_PIN_4, COL_PIN_5, COL_PIN_6, COL_PIN_7,\
                      COL_PIN_8, COL_PIN_9, COL_PIN_10, COL_PIN_11, COL_PIN_12, COL_PIN(13)};

  for (int i = 0; i < NUMBER_OF_ROW_PINS; i++)
  {
    uint32_t currentKeyMask = 1;
    currentKeyMask << rowPins[i];

    mask |= currentKeyMask;
  }

  for (int i = 0; i < NUMBER_OF_COL_PINS; i++)
  {
    uint32_t currentKeyMask = 1;
    currentKeyMask << colPins[i];

    mask |= currentKeyMask;
  }

  return mask;
}

void detect_keypresses(bool *keyMatrix)
{
  
}


void translate_keypresses_to_bitmap(bool *keyMatrix, bool *bitmap)
{

}