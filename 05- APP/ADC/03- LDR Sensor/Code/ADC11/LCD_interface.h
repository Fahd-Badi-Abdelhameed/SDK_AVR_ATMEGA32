/*********************************************************************************/
/* Title        	: 	LCD Driver									   			 */
/* File Name    	: 	LCD_interface.h                                  	     */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	16/10/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


void LCD_voidSendCommand(uint8 Copy_u8Command);
void LCD_voidWriteData(uint8 Copy_u8Data);
void LCD_voidInit(void);
void LCD_voidClearScreen(void);
void LCD_voidWriteString(uint8 *Copy_u8Ptr);
void LCD_voidSetPosition(uint8 Copy_u8Row, uint8 Copy_u8Col);
void LCD_voidDisplayLoop(uint8 Copy_u8Row, uint8 Copy_u8Speed, uint8 *Copy_u8Ptr);
void LCD_voidSetCGRAMAdres(void);
void LCD_voidWriteNumber(uint8 Copy_u8Value);
void LCD_voidReverceNumber(uint8 Copy_u8Value);
void LCD_voidDetachNumber(uint8 Copy_u8Value);



#endif 
