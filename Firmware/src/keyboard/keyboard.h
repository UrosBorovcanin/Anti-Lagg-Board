

#ifndef KBD_MODULE
#define KBD_MODULE

#include <stdio.h>
#include <stdbool.h>

#include "pico/stdlib.h"

//A structure used to represent a value of the key and the absolute time in which it changed value outside of a debounce timer
typedef struct KEY_VALUE
{
    bool value;
    uint64_t debounceCountdown;
} KEY_VALUE;

//Function used to calculate the keyboard matrix GPIO mask
uint32_t kbd_mask();

//Function used to calculate the keyboard matrix column pin GPIO mask
uint32_t col_pin_mask();

//Function used to calculate the keyboard matrix row pi GPIO mask
uint32_t row_pin_mask();

//Function used to scan the GPIO pins for keypresses
bool detect_keypresses(KEY_VALUE *keyList);

//decreases the necesary debounce countdown variables of keys by the time passed since last call
void advance_debounce_countdown(KEY_VALUE *keyList);

//Function used to translate the key matrix into a specific keypress bitmap
void translate_keypresses_to_bitmap(KEY_VALUE *keyList, uint8_t *bitMap);

//Total amount of debounce time in microseconds
#define DEBOUNCE_TIME       2000

//Total number of pins connected to rows
#define NUMBER_OF_ROW_PINS  5

//Microcontroller pins connected to row pins
#define ROW_PIN_0   (uint8_t)7
#define ROW_PIN_1   (uint8_t)8
#define ROW_PIN_2   (uint8_t)9
#define ROW_PIN_3   (uint8_t)10
#define ROW_PIN_4   (uint8_t)11

//Array of row pins initialization
#define ROW_PINS    {ROW_PIN_0, ROW_PIN_1, ROW_PIN_2, ROW_PIN_3, ROW_PIN_4}

//Total number of pins connected to columns
#define NUMBER_OF_COL_PINS  14

//Microcontroller pins connected to row pins
#define COL_PIN_0   (uint8_t)0
#define COL_PIN_1   (uint8_t)1
#define COL_PIN_2   (uint8_t)2
#define COL_PIN_3   (uint8_t)3
#define COL_PIN_4   (uint8_t)4
#define COL_PIN_5   (uint8_t)5
#define COL_PIN_6   (uint8_t)6
#define COL_PIN_7   (uint8_t)22
#define COL_PIN_8   (uint8_t)21
#define COL_PIN_9   (uint8_t)20
#define COL_PIN_10  (uint8_t)19
#define COL_PIN_11  (uint8_t)18
#define COL_PIN_12  (uint8_t)17
#define COL_PIN_13  (uint8_t)16

//Array of column pins initialization
#define COL_PINS    {COL_PIN_0, COL_PIN_1, COL_PIN_2, COL_PIN_3, COL_PIN_4, COL_PIN_5, COL_PIN_6, COL_PIN_7,\
COL_PIN_8, COL_PIN_9, COL_PIN_10, COL_PIN_11, COL_PIN_12, COL_PIN_13}

//The total number of physical keys on the keyboard
#define TOTAL_NUMBER_OF_KEYS 61

//Key matrix for the 60 percent board
//!!Numbers mark the INTERNAL key code, where -1 is NOT CONNECTED!!
#define KEY_MATRIX {\
{0, 1, 2, 3, 4}, /*Keys in column 0 */\
{5, 6, 7, -1, 8}, /*Keys in column 1 */\
{9, 10, 11, 12, 13}, /*Keys in column 2 */\
{14, 15, 16, 17, -1}, /*Keys in column 3 */\
{18, 19, 20, 21, -1}, /*Keys in column 4 */\
{22, 23, 24, 25, -1}, /*Keys in column 5 */\
{26, 27, 28, 29, 30}, /*Keys in column 6 */\
{31, 32, 33, 34, -1}, /*Keys in column 7 */\
{35, 36, 37, 38, -1}, /*Keys in column 8 */\
{39, 40, 41, 42, -1}, /*Keys in column 9 */\
{43, 44, 45, 46, 47}, /*Keys in column 10 */\
{48, 49, 50, 51, 52}, /*Keys in column 11 */\
{53, 54, -1, 55, 56}, /*Keys in column 12 */\
{57, 58, 59, -1, 60} /*Keys in column 13 */\
}


//Keybinds for the first layer
#define KEYBINDS_LAYER_0 {\
HID_NKRO_KEY_GRAVE, \
HID_NKRO_KEY_1, \
HID_NKRO_KEY_2, \
HID_NKRO_KEY_3, \
HID_NKRO_KEY_4, \
HID_NKRO_KEY_5, \
HID_NKRO_KEY_6, \
HID_NKRO_KEY_7, \
HID_NKRO_KEY_8, \
HID_NKRO_KEY_9, \
HID_NKRO_KEY_0, \
HID_NKRO_KEY_MINUS, \
HID_NKRO_KEY_EQUAL, \
HID_NKRO_KEY_BACKSPACE, \
HID_NKRO_KEY_TAB, \
HID_NKRO_KEY_Q, \
HID_NKRO_KEY_W, \
HID_NKRO_KEY_E, \
HID_NKRO_KEY_R, \
HID_NKRO_KEY_T, \
HID_NKRO_KEY_Y, \
HID_NKRO_KEY_U, \
HID_NKRO_KEY_I, \
HID_NKRO_KEY_O, \
HID_NKRO_KEY_P, \
HID_NKRO_KEY_BRACKET_LEFT, \
HID_NKRO_KEY_BRACKET_RIGHT, \
HID_NKRO_KEY_BACKSLASH, \
HID_NKRO_KEY_CAPS_LOCK, \
HID_NKRO_KEY_A, \
HID_NKRO_KEY_S, \
HID_NKRO_KEY_D, \
HID_NKRO_KEY_F, \
HID_NKRO_KEY_G, \
HID_NKRO_KEY_H, \
HID_NKRO_KEY_J, \
HID_NKRO_KEY_K, \
HID_NKRO_KEY_L, \
HID_NKRO_KEY_SEMICOLON, \
HID_NKRO_KEY_APOSTROPHE, \
HID_NKRO_KEY_ENTER, \
HID_NKRO_KEY_RIGHT_SHIFT, \
HID_NKRO_KEY_Z, \
HID_NKRO_KEY_X, \
HID_NKRO_KEY_C, \
HID_NKRO_KEY_V, \
HID_NKRO_KEY_B, \
HID_NKRO_KEY_N, \
HID_NKRO_KEY_M, \
HID_NKRO_KEY_COMMA, \
HID_NKRO_KEY_PERIOD, \
HID_NKRO_KEY_SLASH, \
HID_NKRO_KEY_LEFT_SHIFT, \
HID_NKRO_KEY_LEFT_CONTROL, \
HID_NKRO_KEY_LEFT_GUI, \
HID_NKRO_KEY_LEFT_ALT, \
HID_NKRO_KEY_SPACE, \
HID_NKRO_KEY_RIGHT_ALT, \
HID_NKRO_KEY_RIGHT_GUI, \
HID_NKRO_KEY_APPLICATION, \
HID_NKRO_KEY_RIGHT_CONTROL, \
}

//Key masks for writing proper USB report packets
#define HID_NKRO_KEY_A                         {0 ,0x10}
#define HID_NKRO_KEY_B                         {0 ,0x20}
#define HID_NKRO_KEY_C                         {0 ,0x40}
#define HID_NKRO_KEY_D                         {0 ,0x80}
#define HID_NKRO_KEY_E                         {1 ,0x01}
#define HID_NKRO_KEY_F                         {1 ,0x02}
#define HID_NKRO_KEY_G                         {1 ,0x04}
#define HID_NKRO_KEY_H                         {1 ,0x08}
#define HID_NKRO_KEY_I                         {1 ,0x10}
#define HID_NKRO_KEY_J                         {1 ,0x20}
#define HID_NKRO_KEY_K                         {1 ,0x40}
#define HID_NKRO_KEY_L                         {1 ,0x80}
#define HID_NKRO_KEY_M                         {2 ,0x01}
#define HID_NKRO_KEY_N                         {2 ,0x02}
#define HID_NKRO_KEY_O                         {2 ,0x04}
#define HID_NKRO_KEY_P                         {2 ,0x08}
#define HID_NKRO_KEY_Q                         {2 ,0x10}
#define HID_NKRO_KEY_R                         {2 ,0x20}
#define HID_NKRO_KEY_S                         {2 ,0x40}
#define HID_NKRO_KEY_T                         {2 ,0x80}
#define HID_NKRO_KEY_U                         {3 ,0x01}
#define HID_NKRO_KEY_V                         {3 ,0x02}
#define HID_NKRO_KEY_W                         {3 ,0x04}
#define HID_NKRO_KEY_X                         {3 ,0x08}
#define HID_NKRO_KEY_Y                         {3 ,0x10}
#define HID_NKRO_KEY_Z                         {3 ,0x20}
#define HID_NKRO_KEY_1                         {3 ,0x40}
#define HID_NKRO_KEY_2                         {3 ,0x80}
#define HID_NKRO_KEY_3                         {4 ,0x01}
#define HID_NKRO_KEY_4                         {4 ,0x02}
#define HID_NKRO_KEY_5                         {4 ,0x04}
#define HID_NKRO_KEY_6                         {4 ,0x08}
#define HID_NKRO_KEY_7                         {4 ,0x10}
#define HID_NKRO_KEY_8                         {4 ,0x20}
#define HID_NKRO_KEY_9                         {4 ,0x40}
#define HID_NKRO_KEY_0                         {4 ,0x80}
#define HID_NKRO_KEY_ENTER                     {5 ,0x01}
#define HID_NKRO_KEY_ESCAPE                    {5 ,0x02}
#define HID_NKRO_KEY_BACKSPACE                 {5 ,0x04}
#define HID_NKRO_KEY_TAB                       {5 ,0x08}
#define HID_NKRO_KEY_SPACE                     {5 ,0x10}
#define HID_NKRO_KEY_MINUS                     {5 ,0x20}
#define HID_NKRO_KEY_EQUAL                     {5 ,0x40}
#define HID_NKRO_KEY_BRACKET_LEFT              {5 ,0x80}
#define HID_NKRO_KEY_BRACKET_RIGHT             {6 ,0x01}
#define HID_NKRO_KEY_BACKSLASH                 {6 ,0x02}
#define HID_NKRO_KEY_EUROPE_1                  {6 ,0x04}
#define HID_NKRO_KEY_SEMICOLON                 {6 ,0x08}
#define HID_NKRO_KEY_APOSTROPHE                {6 ,0x10}
#define HID_NKRO_KEY_GRAVE                     {6 ,0x20}
#define HID_NKRO_KEY_COMMA                     {6 ,0x40}
#define HID_NKRO_KEY_PERIOD                    {6 ,0x80}
#define HID_NKRO_KEY_SLASH                     {7 ,0x01}
#define HID_NKRO_KEY_CAPS_LOCK                 {7 ,0x02}
#define HID_NKRO_KEY_F1                        {7 ,0x04}
#define HID_NKRO_KEY_F2                        {7 ,0x08}
#define HID_NKRO_KEY_F3                        {7 ,0x10}
#define HID_NKRO_KEY_F4                        {7 ,0x20}
#define HID_NKRO_KEY_F5                        {7 ,0x40}
#define HID_NKRO_KEY_F6                        {7 ,0x80}
#define HID_NKRO_KEY_F7                        {8 ,0x01}
#define HID_NKRO_KEY_F8                        {8 ,0x02}
#define HID_NKRO_KEY_F9                        {8 ,0x04}
#define HID_NKRO_KEY_F10                       {8 ,0x08}
#define HID_NKRO_KEY_F11                       {8 ,0x10}
#define HID_NKRO_KEY_F12                       {8 ,0x20}
#define HID_NKRO_KEY_PRINT_SCREEN              {8 ,0x40}
#define HID_NKRO_KEY_SCROLL_LOCK               {8 ,0x80}
#define HID_NKRO_KEY_PAUSE                     {9 ,0x01}
#define HID_NKRO_KEY_INSERT                    {9 ,0x02}
#define HID_NKRO_KEY_HOME                      {9 ,0x04}
#define HID_NKRO_KEY_PAGE_UP                   {9 ,0x08}
#define HID_NKRO_KEY_DELETE                    {9 ,0x10}
#define HID_NKRO_KEY_END                       {9 ,0x20}
#define HID_NKRO_KEY_PAGE_DOWN                 {9 ,0x40}
#define HID_NKRO_KEY_ARROW_RIGHT               {9 ,0x80}
#define HID_NKRO_KEY_ARROW_LEFT                {10 ,0x01}
#define HID_NKRO_KEY_ARROW_DOWN                {10 ,0x02}
#define HID_NKRO_KEY_ARROW_UP                  {10 ,0x04}
#define HID_NKRO_KEY_NUM_LOCK                  {10 ,0x08}
#define HID_NKRO_KEY_KEYPAD_DIVIDE             {10 ,0x10}
#define HID_NKRO_KEY_KEYPAD_MULTIPLY           {10 ,0x20}
#define HID_NKRO_KEY_KEYPAD_SUBTRACT           {10 ,0x40}
#define HID_NKRO_KEY_KEYPAD_ADD                {10 ,0x80}
#define HID_NKRO_KEY_KEYPAD_ENTER              {11 ,0x01}
#define HID_NKRO_KEY_KEYPAD_1                  {11 ,0x02}
#define HID_NKRO_KEY_KEYPAD_2                  {11 ,0x04}
#define HID_NKRO_KEY_KEYPAD_3                  {11 ,0x08}
#define HID_NKRO_KEY_KEYPAD_4                  {11 ,0x10}
#define HID_NKRO_KEY_KEYPAD_5                  {11 ,0x20}
#define HID_NKRO_KEY_KEYPAD_6                  {11 ,0x40}
#define HID_NKRO_KEY_KEYPAD_7                  {11 ,0x80}
#define HID_NKRO_KEY_KEYPAD_8                  {12 ,0x01}
#define HID_NKRO_KEY_KEYPAD_9                  {12 ,0x02}
#define HID_NKRO_KEY_KEYPAD_0                  {12 ,0x04}
#define HID_NKRO_KEY_KEYPAD_DECIMAL            {12 ,0x08}
#define HID_NKRO_KEY_EUROPE_2                  {12 ,0x10}
#define HID_NKRO_KEY_APPLICATION               {12 ,0x20}
#define HID_NKRO_KEY_POWER                     {12 ,0x40}
#define HID_NKRO_KEY_KEYPAD_EQUAL              {12 ,0x80}
#define HID_NKRO_KEY_LEFT_CONTROL              {13 ,0x01}
#define HID_NKRO_KEY_LEFT_SHIFT                {13 ,0x02}
#define HID_NKRO_KEY_LEFT_ALT                  {13 ,0x04}
#define HID_NKRO_KEY_LEFT_GUI                  {13 ,0x08}
#define HID_NKRO_KEY_RIGHT_CONTROL             {13 ,0x10}
#define HID_NKRO_KEY_RIGHT_SHIFT               {13 ,0x20}
#define HID_NKRO_KEY_RIGHT_ALT                 {13 ,0x40}
#define HID_NKRO_KEY_RIGHT_GUI                 {13 ,0x80}

#endif