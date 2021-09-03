/*****************************************************************************/
/* Title        	: 	TIMER0 Driver									     */
/* File Name    	: 	TIMER0_program.c   		                             */
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
****************************** Component DIRECTIVES ***************************
******************************************************************************/

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

/******************************************************************************
* !comment  :  Pointer to function for callback.  							  *
******************************************************************************/

static void(*TIMER0_OverflowCallBack)(void)     = NULL;
static void(*TIMER0_CompareMatchCallBack)(void) = NULL;

/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/


/******************************************************************************
* Description 	: TIMER0 Initialization Function to select timer mode         *
*			      & Prescaler vale.                                           *
******************************************************************************/

void TIMER0_voidInit(Timer0Mode_t Mode, Timer0Scaler_t Prescaler){

	switch(Mode){
	
		case TIMER0_NORMAL_MODE :
			/* Select Normal mode or overflow mode */
			CLR_BIT(TCCR0, WGM01);	CLR_BIT(TCCR0, WGM00);
		break;	
		
		case TIMER0_PHASE_CORRECT_MODE :
			/* Select mode */
			SET_BIT(TCCR0, WGM00);	CLR_BIT(TCCR0, WGM01);
		break;	
		
		case TIMER0_CTC_MODE :
			/* Select CTC mode  */
			CLR_BIT(TCCR0, WGM00);	SET_BIT(TCCR0, WGM01);
		break;
		
		case TIMER0_FAST_PWM_MODE :
			/* Select PWM, Fast mode */
			SET_BIT(TCCR0, WGM00);	SET_BIT(TCCR0, WGM01);
		break;	
		
		default:   break;
	}
	
	/* Prescaler mask */
	TCCR0 &= PRESCALER_MASK;
	
	/* Set prescaler value */
	TCCR0 |= Prescaler;

}


/******************************************************************************
* Description 	: TIMER0 Output Compare initialization Function to            *
*                 Select Output Compare Mode.                                 *
******************************************************************************/

void TIMER0_voidOutputCompareInit(Timer0_OutputCompareMode_t OC0Mode){

	switch(OC0Mode){

		case TIMER0_OC0_DISCONNECTED_MODE :
			// OC0 disconnected
			CLR_BIT(TCCR0, COM00);	CLR_BIT(TCCR0, COM01);
		break;

		case TIMER0_OC0_TOGGLE_MODE :
			// Toggle OC0 on compare match
			SET_BIT(TCCR0, COM00);	CLR_BIT(TCCR0, COM01);
		break;

		case TIMER0_OC0_NON_INVERTING_MODE :
			// Non inverting OC0
			CLR_BIT(TCCR0, COM00);	SET_BIT(TCCR0, COM01);
		break;

		case TIMER0_OC0_INVERTING_MODE :
			// inverting OC0
			SET_BIT(TCCR0, COM00);	SET_BIT(TCCR0, COM01);
		break;

		default:   break;
	}
}


/******************************************************************************
* Description 	: TIMER0 Set Timer Counter Value Function.				      *
******************************************************************************/

void TIMER0_voidSetTimerCounterValue(uint8 Copy_u8TimerValue){

	TCNT0 = Copy_u8TimerValue;
}


/******************************************************************************
* Description 	: TIMER0 Get Timer Counter Value Function.				      *
******************************************************************************/

uint8 TIMER0_u8GetTimerCounterValue(void){

	return TCNT0;
}


/******************************************************************************
* Description 	: TIMER0 Set Output Compare Register Value.				      *
******************************************************************************/

void TIMER0_voidSetOutputCompareValue(uint8 Copy_u8CompareValue){

	OCR0 = Copy_u8CompareValue;
}


/******************************************************************************
* Description 	: TIMER0 Update Duty Cycle Value Function                     *
* 			      and put it in the OCR0 register.                            *
******************************************************************************/

void TIMER0_voidUpdateDutyCycle(uint8 Copy_u8DutyCycle){

	if(Copy_u8DutyCycle <= 100){

		uint8 Local_u8TimeON = ((uint16)Copy_u8DutyCycle * (TIMER0_MAX_COUNT)) / 100;

		if(Local_u8TimeON > 1){

			OCR0 = Local_u8TimeON-1;
		}
		else{  OCR0 = 0;  }
	}
	else{ /* return error */}

}


/******************************************************************************
* Description 	: TIMER0 Overflow Interrupt Enable Function.		          *
******************************************************************************/

void TIMER0_voidOverflowInterruptEnable(void){
	
	/* Enable overflow mode interrupt */
	SET_BIT(TIMSK, TOIE0);
}


/******************************************************************************
* Description 	: TIMER0 Overflow Interrupt Disable Function.				  *
******************************************************************************/

void TIMER0_voidOverflowInterruptDisable(void){
	
	/* Disable overflow mode interrupt */
	CLR_BIT(TIMSK, TOIE0);
}


/******************************************************************************
* Description 	: TIMER0 Output Compare Interrupt Enable Function.			  *
******************************************************************************/

void TIMER0_voidCompareMatchnterruptEnable(void){
	
	/* Output Compare Match interrupt Enable */
	SET_BIT(TIMSK, OCIE0);
}


/******************************************************************************
* Description 	: TIMER0 Output Compare Interrupt Disable Function.			  *
******************************************************************************/

void TIMER0_voidCompareMatchInterruptDisable(void){
	
	/* Output Compare Match interrupt Disable */
	CLR_BIT(TIMSK, OCIE0);
}



/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function TIMER0 OVF) -                   *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void TIMER0_voidOverflowSetCallBack(void(*Local_Fptr)(void)){

	TIMER0_OverflowCallBack = Local_Fptr;

}


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function TIMER0 OC0) -                   *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void TIMER0_voidCompareMatchSetCallBack(void(*Local_Fptr)(void)){

	TIMER0_CompareMatchCallBack = Local_Fptr;

}


/******************************************************************************
* !comment  :  ISR Function output compare interrupt.  						  *
******************************************************************************/

ISR( TIMER0_OC0 ){

	if(NULL != TIMER0_CompareMatchCallBack){

		TIMER0_CompareMatchCallBack();
	}
	else{ /* Return error */ }
}


/******************************************************************************
* !comment  :  ISR Function overflow interrupt.  						      *
******************************************************************************/

ISR( TIMER0_OVF ){

	if(NULL != TIMER0_OverflowCallBack){

		TIMER0_OverflowCallBack();
	}
	else{ /* Return error */ }
}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
