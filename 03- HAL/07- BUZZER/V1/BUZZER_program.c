/*****************************************************************************/
/* Title        	: 	BUZZER Driver									     */
/* File Name    	: 	BUZZER_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	13/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
********************************* DIO DIRECTIVES ******************************
******************************************************************************/
#include "DIO_interface.h"

/******************************************************************************
********************************* TIMER0 DIRECTIVES ***************************
******************************************************************************/
#include "TIMER0_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "BUZZER_interface.h"
#include "BUZZER_private.h"
#include "BUZZER_config.h"


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/

void BUZZER_voidInit(void){

	/* Set PIN3 (OC0) PORT B as output */
	DIO_voidSetPinDirection(PORT_B, PIN3, OUTPUT);

	/* Set timer0 --> fast PWM mode and prescaler div 8 */
	TIMER0_voidInit(TIMER0_FAST_PWM_MODE, TIMER0_SCALER_8);
	
	/* Set timer0 output compare mode --> non inverting mode */
	TIMER0_voidOutputCompareInit(TIMER0_OC0_NON_INVERTING_MODE);

}


void BUZZER_voidSoundMode(Buzzer_State_t State){
	
	switch(State){
		  
		case BUZZER_ON :
			/* Sound mode ---> on */		
			TIMER0_voidDutyCycle(BUZZER_MAX_SOUND);
		break;
		
		case BUZZER_OFF:  
			/* Sound mode ---> off */
			TIMER0_voidDutyCycle(BUZZER_SOUND_OFF);
		break;
		
		default:	break;
	}
	
}


void BUZZER_voidVariableSound(uint8 Copy_u8SoundValue){

	/* Set sound value from 1 to 100 */
	TIMER0_voidDutyCycle(Copy_u8SoundValue);
	
}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/

