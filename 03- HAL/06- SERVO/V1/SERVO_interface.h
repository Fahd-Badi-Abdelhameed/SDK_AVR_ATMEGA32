/*****************************************************************************/
/* Title        	: 	SERVO Driver									     */
/* File Name    	: 	SERVO_interface.h   		                         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	30/01/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef SERVO_INTERFACE_H
#define SERVO_INTERFACE_H

/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void SERVO_voidInit(void);
void SERVO_voidSetAngle(uint8 Copy_u8Angle);


#endif 
/*** !comment : End of gaurd [SERVO_INTERFACE_H] *****************************/