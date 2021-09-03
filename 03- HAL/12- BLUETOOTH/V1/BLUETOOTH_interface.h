/*****************************************************************************/
/* Title        	: 	BLUETOOTH Driver									 */
/* File Name    	: 	BLUETOOTH_interface.h   		                     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	03/02/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef BLUETOOTH_INTERFACE_H
#define BLUETOOTH_INTERFACE_H


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void BLUETOOTH_voidInit(void);
uint8 BLUETOOTH_u8Receive(void);
void BLUETOOTH_voidSendChar(uint8 Copy_u8Data);
void BLUETOOTH_voidSendString(uint8 *Copy_u8Data);
void BLUETOOTH_voidWriteNumber(uint32 Copy_u32Number);



#endif 
/*** !comment : End of gaurd [BLUETOOTH_INTERFACE_H] *************************/
