/*****************************************************************************/
/* Title        	: 	BUZZER Driver									     */
/* File Name    	: 	BUZZER_interface.h   		                         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	13/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef BUZZER_INTERFACE_H
#define BUZZER_INTERFACE_H


/******************************************************************************
************************************* Typedef *********************************
******************************************************************************/

typedef enum{

	BUZZER_OFF = 0,
	BUZZER_ON, 

}Buzzer_State_t;


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void BUZZER_voidInit(void);
void BUZZER_voidSoundMode(Buzzer_State_t State);
void BUZZER_voidVariableSound(uint8 Copy_u8SoundValue);


#endif 
/*** !comment : End of gaurd [BUZZER_INTERFACE_H] ****************************/
