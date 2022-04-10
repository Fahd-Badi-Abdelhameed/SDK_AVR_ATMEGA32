/*****************************************************************************/
/* Title        	: 	LCD Driver								         	 */
/* File Name    	: 	LCD_private.h                                        */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	16/10/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

/******************************************************************************
* !comment : LCD Mode Options.  			         	                      *
******************************************************************************/

#define MODE_4_BIT    4
#define MODE_8_BIT    8

/******************************************************************************
* !comment : LCD Command.  			         	                              *
******************************************************************************/

#define  LCD_SET_DDRAM_ROW0       128
#define  LCD_SET_DDRAM_ROW1       128 + 64

#define  DDRAM_TO_CGRAM           64
#define  CGRAM_TO_DDRAM           128

#define  DISPLAY_CLEAR            0x01
#define  ENTRY_MODE               0x06
#define  FUNCTION_SET_8BIT		  0x38
#define  DISPLAY_ON_OFF           0x0E
#define  CURSOR_OFF               0x0C
#define  CURSOR_ON                0x0E

/*
#define lcd_Clear             0x01        // replace all characters with ASCII 'space'
#define lcd_Home              0x02        // return cursor to first position on first line
#define lcd_EntryMode         0x06        // shift cursor from left to right on read/write
#define lcd_DisplayOff        0x08        // turn display off
#define lcd_DisplayOn         0x0C        // display on, cursor off, don't blink character
#define lcd_FunctionReset     0x30        // reset the LCD
#define lcd_FunctionSet8bit   0x38        // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor         0x80        // set cursor position
*/

/******************************************************************************
************************** Private Functions Prototypes ***********************
******************************************************************************/

/******************************************************************************
* Description 	: Get Power Private Function.					              *
* Parameters  	: Copy_u8Number1, Copy_u8Number2.                             *
* Return type 	: uint16.                                                     *
******************************************************************************/
static uint16 Private_u16GetPower(uint8 Copy_u8Number1, uint8 Copy_u8Number2);

/******************************************************************************
* Description 	: LCD Send Command Function.				                  *
* Parameters  	: Copy_u8Command.   		                            	  *
* Return type 	: void.                                                  	  *
******************************************************************************/
static void LCD_voidSendCommand(uint8 Copy_u8Command);

/******************************************************************************
* Description 	: LCD Send Command Function.				                  *
* Parameters  	: none.   		                            	              *
* Return type 	: void.                                                  	  *
******************************************************************************/
static void LCD_voidLatchEnable(void);


#endif 
/*** !comment : End of gaurd [LCD_PRIVATE_H] *********************************/
