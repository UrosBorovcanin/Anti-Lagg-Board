

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

//Function used to 
void initialize_kbd_gpio();

//Function used to 
void set_kbd_input_pins();

//Function used to 
void set_kbd_output_pins();

//Function used to scan the GPIO pins for keypresses
bool detect_keypresses(KEY_VALUE *keyList);

//decreases the necesary debounce countdown variables of keys by the time passed since last call
void advance_debounce_countdown(KEY_VALUE *keyList);

//Function used to translate the key matrix into a specific keypress bitmap
bool translate_keypresses_to_bitmap(KEY_VALUE *keyList, uint8_t *bitMap);

//Total amount of debounce time in microseconds
#define DEBOUNCE_TIME       10000

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
#define COL_PIN_0   (uint8_t)26
#define COL_PIN_1   (uint8_t)27
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
{0, 14, 28, 41, 53}, /*Keys in column 0 */\
{1, 15, 29, -1, 54}, /*Keys in column 1 */\
{2, 16, 30, 42, 55}, /*Keys in column 2 */\
{3, 17, 31, 43, -1}, /*Keys in column 3 */\
{4, 18, 32, 44, -1}, /*Keys in column 4 */\
{5, 19, 33, 45, -1}, /*Keys in column 5 */\
{6, 20, 34, 46, 56}, /*Keys in column 6 */\
{7, 21, 35, 47, -1}, /*Keys in column 7 */\
{8, 22, 36, 48, -1}, /*Keys in column 8 */\
{9, 23, 37, 49, -1}, /*Keys in column 9 */\
{10, 24, 38, 50, 57}, /*Keys in column 10 */\
{11, 25, 39, 51, 58}, /*Keys in column 11 */\
{12, 26, -1, 52, 59}, /*Keys in column 12 */\
{13, 27, 40, -1, 60} /*Keys in column 13 */\
}


//Keybinds for the first layer
#define KEYBINDS_LAYER_0 {\
KC_GRAVE, \
KC_1, \
KC_2, \
KC_3, \
KC_4, \
KC_5, \
KC_6, \
KC_7, \
KC_8, \
KC_9, \
KC_0, \
KC_MINUS, \
KC_EQUAL, \
KC_BACKSPACE, \
KC_TAB, \
KC_Q, \
KC_W, \
KC_E, \
KC_R, \
KC_T, \
KC_Y, \
KC_U, \
KC_I, \
KC_O, \
KC_P, \
KC_BRACKET_LEFT, \
KC_BRACKET_RIGHT, \
KC_BACKSLASH, \
KC_CAPS_LOCK, \
KC_A, \
KC_S, \
KC_D, \
KC_F, \
KC_G, \
KC_H, \
KC_J, \
KC_K, \
KC_L, \
KC_SEMICOLON, \
KC_APOSTROPHE, \
KC_ENTER, \
KC_RIGHT_SHIFT, \
KC_Z, \
KC_X, \
KC_C, \
KC_V, \
KC_B, \
KC_N, \
KC_M, \
KC_COMMA, \
KC_PERIOD, \
KC_SLASH, \
KC_LEFT_SHIFT, \
KC_LEFT_CONTROL, \
KC_LEFT_GUI, \
KC_LEFT_ALT, \
KC_SPACE, \
KC_RIGHT_ALT, \
KC_RIGHT_GUI, \
KC_APPLICATION, \
KC_RIGHT_CONTROL, \
}

//Key masks for writing proper USB report packets
#define KC_LEFT_CONTROL              {0 ,0x01}
#define KC_LEFT_SHIFT                {0 ,0x02}
#define KC_LEFT_ALT                  {0 ,0x04}
#define KC_LEFT_GUI                  {0 ,0x08}
#define KC_RIGHT_CONTROL             {0 ,0x10}
#define KC_RIGHT_SHIFT               {0 ,0x20}
#define KC_RIGHT_ALT                 {0 ,0x40}
#define KC_RIGHT_GUI                 {0 ,0x80}
#define KC_A                         {1 ,0x10}
#define KC_B                         {1 ,0x20}
#define KC_C                         {1 ,0x40}
#define KC_D                         {1 ,0x80}
#define KC_E                         {2 ,0x01}
#define KC_F                         {2 ,0x02}
#define KC_G                         {2 ,0x04}
#define KC_H                         {2 ,0x08}
#define KC_I                         {2 ,0x10}
#define KC_J                         {2 ,0x20}
#define KC_K                         {2 ,0x40}
#define KC_L                         {2 ,0x80}
#define KC_M                         {3 ,0x01}
#define KC_N                         {3 ,0x02}
#define KC_O                         {3 ,0x04}
#define KC_P                         {3 ,0x08}
#define KC_Q                         {3 ,0x10}
#define KC_R                         {3 ,0x20}
#define KC_S                         {3 ,0x40}
#define KC_T                         {3 ,0x80}
#define KC_U                         {4 ,0x01}
#define KC_V                         {4 ,0x02}
#define KC_W                         {4 ,0x04}
#define KC_X                         {4 ,0x08}
#define KC_Y                         {4 ,0x10}
#define KC_Z                         {4 ,0x20}
#define KC_1                         {4 ,0x40}
#define KC_2                         {4 ,0x80}
#define KC_3                         {5 ,0x01}
#define KC_4                         {5 ,0x02}
#define KC_5                         {5 ,0x04}
#define KC_6                         {5 ,0x08}
#define KC_7                         {5 ,0x10}
#define KC_8                         {5 ,0x20}
#define KC_9                         {5 ,0x40}
#define KC_0                         {5 ,0x80}
#define KC_ENTER                     {6 ,0x01}
#define KC_ESCAPE                    {6 ,0x02}
#define KC_BACKSPACE                 {6 ,0x04}
#define KC_TAB                       {6 ,0x08}
#define KC_SPACE                     {6 ,0x10}
#define KC_MINUS                     {6 ,0x20}
#define KC_EQUAL                     {6 ,0x40}
#define KC_BRACKET_LEFT              {6 ,0x80}
#define KC_BRACKET_RIGHT             {7 ,0x01}
#define KC_BACKSLASH                 {7 ,0x02}
#define KC_EUROPE_1                  {7 ,0x04}
#define KC_SEMICOLON                 {7 ,0x08}
#define KC_APOSTROPHE                {7 ,0x10}
#define KC_GRAVE                     {7 ,0x20}
#define KC_COMMA                     {7 ,0x40}
#define KC_PERIOD                    {7 ,0x80}
#define KC_SLASH                     {8 ,0x01}
#define KC_CAPS_LOCK                 {8 ,0x02}
#define KC_F1                        {8 ,0x04}
#define KC_F2                        {8 ,0x08}
#define KC_F3                        {8 ,0x10}
#define KC_F4                        {8 ,0x20}
#define KC_F5                        {8 ,0x40}
#define KC_F6                        {8 ,0x80}
#define KC_F7                        {9 ,0x01}
#define KC_F8                        {9 ,0x02}
#define KC_F9                        {9 ,0x04}
#define KC_F10                       {9 ,0x08}
#define KC_F11                       {9 ,0x10}
#define KC_F12                       {9 ,0x20}
#define KC_PRINT_SCREEN              {9 ,0x40}
#define KC_SCROLL_LOCK               {9 ,0x80}
#define KC_PAUSE                     {10 ,0x01}
#define KC_INSERT                    {10 ,0x02}
#define KC_HOME                      {10 ,0x04}
#define KC_PAGE_UP                   {10 ,0x08}
#define KC_DELETE                    {10 ,0x10}
#define KC_END                       {10 ,0x20}
#define KC_PAGE_DOWN                 {10 ,0x40}
#define KC_ARROW_RIGHT               {10 ,0x80}
#define KC_ARROW_LEFT                {11 ,0x01}
#define KC_ARROW_DOWN                {11 ,0x02}
#define KC_ARROW_UP                  {11 ,0x04}
#define KC_NUM_LOCK                  {11 ,0x08}
#define KC_KEYPAD_DIVIDE             {11 ,0x10}
#define KC_KEYPAD_MULTIPLY           {11 ,0x20}
#define KC_KEYPAD_SUBTRACT           {11 ,0x40}
#define KC_KEYPAD_ADD                {11 ,0x80}
#define KC_KEYPAD_ENTER              {12 ,0x01}
#define KC_KEYPAD_1                  {12 ,0x02}
#define KC_KEYPAD_2                  {12 ,0x04}
#define KC_KEYPAD_3                  {12 ,0x08}
#define KC_KEYPAD_4                  {12 ,0x10}
#define KC_KEYPAD_5                  {12 ,0x20}
#define KC_KEYPAD_6                  {12 ,0x40}
#define KC_KEYPAD_7                  {12 ,0x80}
#define KC_KEYPAD_8                  {13 ,0x01}
#define KC_KEYPAD_9                  {13 ,0x02}
#define KC_KEYPAD_0                  {13 ,0x04}
#define KC_KEYPAD_DECIMAL            {13 ,0x08}
#define KC_EUROPE_2                  {13 ,0x10}
#define KC_APPLICATION               {13 ,0x20}
#define KC_POWER                     {13 ,0x40}
#define KC_KEYPAD_EQUAL              {13 ,0x80}

#define KEY_VALUE_INITIALIZER_61    {\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
{false, 0},\
}

#endif