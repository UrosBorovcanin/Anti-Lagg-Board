

#ifndef KBD_MODULE
#define KBD_MODULE

#include "pico/stdlib.h"
#include "bsp/board.h"

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
#define ROW_PIN_0   (uint8_t)21
#define ROW_PIN_1   (uint8_t)20
#define ROW_PIN_2   (uint8_t)11
#define ROW_PIN_3   (uint8_t)10
#define ROW_PIN_4   (uint8_t)9

//Array of row pins initialization
#define ROW_PINS    {ROW_PIN_0, ROW_PIN_1, ROW_PIN_2, ROW_PIN_3, ROW_PIN_4}

//Total number of pins connected to columns
#define NUMBER_OF_COL_PINS  4

//Microcontroller pins connected to row pins
#define COL_PIN_0   (uint8_t)12
#define COL_PIN_1   (uint8_t)6
#define COL_PIN_2   (uint8_t)1
#define COL_PIN_3   (uint8_t)0

//Array of column pins initialization
#define COL_PINS    {COL_PIN_0, COL_PIN_1, COL_PIN_2, COL_PIN_3}

//The total number of physical keys on the keyboard
#define TOTAL_NUMBER_OF_KEYS 17

//Key matrix for the 60 percent board
//!!Numbers mark the INTERNAL key code, where -1 is NOT CONNECTED!!
#define KEY_MATRIX {\
{0, 4, 7, 11, -1}, /*Keys in column 0 */\
{1, 5, 8, 12, 14}, /*Keys in column 1 */\
{2, 6, 9, 13, 15}, /*Keys in column 2 */\
{3, -1, 10, -1, 16}, /*Keys in column 3 */\
}


//Keybinds for the first layer
#define KEYBINDS_LAYER_0 {\
KC_NUM_LOCK, \
KC_KEYPAD_DIVIDE,\
KC_KEYPAD_MULTIPLY,\
KC_KEYPAD_SUBTRACT,\
KC_KEYPAD_7,\
KC_KEYPAD_8,\
KC_KEYPAD_9,\
KC_KEYPAD_4,\
KC_KEYPAD_5,\
KC_KEYPAD_6,\
KC_KEYPAD_ADD,\
KC_KEYPAD_1,\
KC_KEYPAD_2,\
KC_KEYPAD_3,\
KC_KEYPAD_0,\
KC_KEYPAD_DECIMAL,\
KC_KEYPAD_ENTER\
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