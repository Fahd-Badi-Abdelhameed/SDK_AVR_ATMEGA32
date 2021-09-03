/*****************************************************************************/
/* Title        	: 	Temperature Sensor Driver							 */
/* File Name    	: 	TEMP_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	05/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef TEMP_INTERFACE_H
#define TEMP_INTERFACE_H


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void TEMP_voidInit(void);
uint16 TEMP_u16GetValue(uint8 Copy_u8ChannelNumber);


#endif 
/*** !comment : End of gaurd [TEMP_INTERFACE_H] ******************************/
