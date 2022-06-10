

#ifndef KBD_MODULE
#define KBD_MODULE

#include <stdio.h>
#include <stdbool.h>


//Keyboard row pin definitions
#define NUMBER_OF_ROW_PINS  5

#define ROW_PIN_0   (uint8_t)7
#define ROW_PIN_1   (uint8_t)8
#define ROW_PIN_2   (uint8_t)9
#define ROW_PIN_3   (uint8_t)10
#define ROW_PIN_4   (uint8_t)11

//Keyboard column pin definitions
#define NUMBER_OF_COL_PINS  14

#define COL_PIN(n)  COL_PIN_##n
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

//Function used to calculate the keyboard matrix GPIO mask
uint32_t kbd_mask();

//Function used to scan the GPIO pins for keypresses
void detect_keypresses(bool *keyMatrix);

//Function used to translate the key matrix into a specific keypress bitmap
void translate_keypresses_to_bitmap(bool *keyMatrix, bool *bitMap);

//Key matrix for the 60 percent board
//!!Numbers mark the INTERNAL key code, where 0 is NOT CONNECTED!!
#define KEY_MATRIX \
{1, 2, 3, 4, 5}, /*Keys in column 0 */\
{6, 7, 8, 0, 9}, /*Keys in column 1 */\
{10, 11, 12, 13, 14}, /*Keys in column 2 */\
{15, 16, 17, 18, 0}, /*Keys in column 3 */\
{19, 20, 21, 22, 0}, /*Keys in column 4 */\
{23, 24, 25, 26, 0}, /*Keys in column 5 */\
{27, 28, 29, 30, 31}, /*Keys in column 6 */\
{32, 33, 34, 35, 0}, /*Keys in column 7 */\
{36, 37, 38, 39, 0}, /*Keys in column 8 */\
{40, 41, 42, 43, 0}, /*Keys in column 9 */\
{44, 45, 46, 47, 48}, /*Keys in column 10 */\
{49, 50, 51, 52, 53}, /*Keys in column 11 */\
{54, 55, 0, 56, 57}, /*Keys in column 12 */\
{58, 59, 60, 0, 61} /*Keys in column 13 */

#define DEFAULT_KEYBINDS_LAYER_0 \
{1, }, \
{2, }, \
{3, }, \
{4, }, \
{5, }, \
{6, }, \
{7, }, \
{8, }, \
{9, }, \
{10, }, \
{11, }, \
{12, }, \
{13, }, \
{14, }, \
{15, }, \
{16, }, \
{17, }, \
{18, }, \
{19, }, \
{20, }, \
{21, }, \
{22, }, \
{23, }, \
{24, }, \
{25, }, \
{26, }, \
{27, }, \
{28, }, \
{29, }, \
{30, }, \
{31, }, \
{32, }, \
{33, }, \
{34, }, \
{35, }, \
{36, }, \
{37, }, \
{38, }, \
{39, }, \
{40, }, \
{41, }, \
{42, }, \
{43, }, \
{44, }, \
{45, }, \
{46, }, \
{47, }, \
{48, }, \
{49, }, \
{50, }, \
{51, }, \
{52, }, \
{53, }, \
{54, }, \
{55, }, \
{56, }, \
{57, }, \
{58, }, \
{59, }, \
{60, }, \
{61, }

#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4
#define HID_NKRO_KEY_A  4



#endif