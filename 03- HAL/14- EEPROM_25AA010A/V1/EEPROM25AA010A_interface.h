/*****************************************************************************/
/* Title        	: 	EEPROM25AA010A Driver								 */
/* File Name    	: 	EEPROM25AA010A_interface.h   		                 */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	07/05/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef EEPROM25AA010A_INTERFACE_H
#define EEPROM25AA010A_INTERFACE_H


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void EEPROM25AA010A_voidInit(void);
void EEPROM25AA010A_voidWriteByte(uint8 Copy_u8Data, uint16 Copy_u16Address);
uint8 EEPROM25AA010A_u8ReadByte(uint16 Copy_u16Address);



#endif 
/*** !comment : End of gaurd [EEPROM25AA010A_INTERFACE_H] ********************/
