/*****************************************************************************/
/* Title        	: 	LDR Sensor Driver									 */
/* File Name    	: 	LDR_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	05/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H

/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void LDR_voidInit(void);
uint32 LDR_u16GetValue(uint8 Copy_u8ChannelNumber);


#endif 
/*** !comment : End of gaurd [LDR_INTERFACE_H] *******************************/
