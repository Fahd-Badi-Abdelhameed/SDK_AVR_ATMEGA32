/*****************************************************************************/
/* Title        	: 	STEPPER Driver									     */
/* File Name    	: 	STEPPER_interface.h   		                         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	02/02/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H

/******************************************************************************
************************************ Typedef **********************************
******************************************************************************/

typedef enum{

	STEPPER_FULL_STEP_MODE = 0,
	STEPPER_HALF_STEP_MODE,

}Stepper_Mode_t;


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void STEPPER_voidInit(void);
void STEPPER_voidRotateCW(Stepper_Mode_t Mode, uint8 Copy_u8Speed);
void STEPPER_voidRotateACW(Stepper_Mode_t Mode, uint8 Copy_u8Speed);



#endif 
/*** !comment : End of gaurd [STEPPER_INTERFACE_H] ***************************/
