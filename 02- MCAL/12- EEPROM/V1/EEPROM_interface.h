/*****************************************************************************/
/* Title        	: 	EEPROM Driver										 */
/* File Name    	: 	EEPROM_interface.h   		                         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	10/05/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/


uint8 EEPROM_u8ReadByte(uint16 Copy_u16Address);
void EEPROM_voidReadeBlock(uint16 Copy_u16Address, uint8 *Ptr_u8Return, uint16 Copy_u16Size);
void EEPROM_voidWriteByte(uint16 Copy_u16Address, uint8 Copy_u8Data);
void EEPROM_voidWriteBlock(uint16 Copy_u16Address, uint8 *Copy_u8Data, uint16 Copy_u16Size);
void EEPROM_voidReadyInterruptEnable(void);
void EEPROM_voidReadyInterruptDisable(void);
void EEPROM_voidSetCallBack(void(*Local_ptr)(void));


#endif 
/*** !comment : End of gaurd [EEPROM_INTERFACE_H] ****************************/