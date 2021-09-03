/*****************************************************************************/
/* Title        	: 	ULTRASONIC Driver									 */
/* File Name    	: 	ULTRASONIC_interface.h   		                     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	30/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef ULTRASONIC_INTERFACE_H
#define ULTRASONIC_INTERFACE_H


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void ULTRASONIC_voidInit(void);
void ULTRASONIC_voidStart(uint8 Copy_u8TriggerPort, uint8 Copy_u8TriggerPin);
uint8 ULTRASONIC_voidGetDistance(uint8 Copy_u8TriggerPort, uint8 Copy_u8TriggerPin);
uint8 ULTRASONIC_voidGetDistanceNoBlock(uint8 *ReturnDistance);




#endif 
/*** !comment : End of gaurd [ULTRASONIC_INTERFACE_H] ************************/
