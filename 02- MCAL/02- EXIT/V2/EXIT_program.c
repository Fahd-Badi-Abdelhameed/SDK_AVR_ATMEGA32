/*****************************************************************************/
/* Title        	: 	EXIT Driver									         */
/* File Name    	: 	EXIT_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	30/10/2020                                           */
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

#include "EXIT_interface.h"
#include "EXIT_private.h"
#include "EXIT_config.h"

/******************************************************************************
* !comment  :  Pointer to function for callback.  							  *
******************************************************************************/

static void (*EXTI0_CallBack)(void) = NULL;
static void (*EXTI1_CallBack)(void) = NULL;
static void (*EXTI2_CallBack)(void) = NULL;

/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/


/******************************************************************************
* Description 	: External Interrupt Request 0 Enable Function.				  *
******************************************************************************/

void EXIT0_voidEnable(void){

	/* External Interrupt Request 0 Enable */
	SET_BIT(GICR, INT0);
}


/******************************************************************************
* Description 	: External Interrupt Request 0 Disable Function.		      *
******************************************************************************/

void EXIT0_voidDisable(void){

	/* External Interrupt Request 0 Disable */
	CLR_BIT(GICR, INT0);
}


/******************************************************************************
* Description 	: External Interrupt Request 1 Enable Function.				  *
******************************************************************************/

void EXIT1_voidEnable(void){

	/* External Interrupt Request 1 Enable */
	SET_BIT(GICR, INT1);
}


/******************************************************************************
* Description 	: External Interrupt Request 1 Disable Function.		      *
******************************************************************************/

void EXIT1_voidDisable(void){

	/* External Interrupt Request 1 Disable */
	CLR_BIT(GICR, INT1);
}


/******************************************************************************
* Description 	: External Interrupt Request 2 Enable Function.				  *
******************************************************************************/

void EXIT2_voidEnable(void){

	/* External Interrupt Request 2 Enable */
	SET_BIT(GICR, INT2);
}


/******************************************************************************
* Description 	: External Interrupt Request 2 Disable Function.		      *
******************************************************************************/

void EXIT2_voidDisable(void){

	/* External Interrupt Request 2 Disable */
	CLR_BIT(GICR, INT2);
}


/******************************************************************************
* Description 	: Control the trigger edge of an EXIT0 Function.  		      *
******************************************************************************/

void EXIT0_voidTriggerEdge(EXIT_TriggerEdge_t Edge){

	switch(Edge){
		
		case LOW_LEVEL :

			/* Enable EXTI0 Sense Control low level */
			CLR_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			
		break;	
		
		case ANY_CHANGE :
		
			/* Enable EXTI0 Sense Control any change -> rising or falling */
			SET_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
		
		break;		
		
		case FALLING_EDGE :
		
			/* Enable EXTI0 Sense Control falling edge */
			CLR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			
		break;	
		
		case RISING_EDGE :
		
			/* Enable EXTI0 Sense Control rising edge */
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			
		break;	
		
		default:    break;	
	}	
}


/******************************************************************************
* Description 	: Control the trigger edge of an EXIT1 Function.  		      *
******************************************************************************/

void EXIT1_voidTriggerEdge(EXIT_TriggerEdge_t Edge){

	switch(Edge){
		
		case LOW_LEVEL :

			/* Enable EXTI1 Sense Control low level */
			CLR_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
			
		break;	
		
		case ANY_CHANGE :
		
			/* Enable EXTI1 Sense Control any change -> rising or falling */
			SET_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
		
		break;		
		
		case FALLING_EDGE :
		
			/* Enable EXTI1 Sense Control falling edge */
			CLR_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			
		break;	
		
		case RISING_EDGE :
		
			/* Enable EXTI1 Sense Control rising edge */
			SET_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			
		break;	
		
		default:    break;	
	}
}


/******************************************************************************
* Description 	: Control the trigger edge of an EXIT2 Function.  		      *
******************************************************************************/

void EXIT2_voidTriggerEdge(EXIT_TriggerEdge_t Edge){
	
	switch(Edge){
		
		/* Enable EXTI2 Sense Control falling edge */
		case FALLING_EDGE :	   CLR_BIT(MCUCSR, ISC2);    break;
		/* Enable EXTI2 Sense Control rising edge */
		case RISING_EDGE  :	   SET_BIT(MCUCSR, ISC2);    break;
		default:     break;
	}	
}


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function EXTI0) -                        *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void EXTI0_voidSetCallBack(void(*Local_ptr)(void)){

	EXTI0_CallBack = Local_ptr;

}


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function EXTI1) -                        *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void EXTI1_voidSetCallBack(void(*Local_ptr)(void)){

	EXTI1_CallBack = Local_ptr;

}


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer( The Callback function EXTI2) -                       *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void EXTI2_voidSetCallBack(void(*Local_ptr)(void)){

	EXTI2_CallBack = Local_ptr;

}


/******************************************************************************
* !comment  :  ISR Function EXTI0.  							 			  *
******************************************************************************/

ISR( INT0_VECTOR ){

	if(EXTI0_CallBack != NULL){

		EXTI0_CallBack();
	}

	else{ /* Return error */ }
}


/******************************************************************************
* !comment  :  ISR Function EXTI1.  							 			  *
******************************************************************************/

ISR( INT1_VECTOR ){
  
	if(EXTI1_CallBack != NULL){

		EXTI1_CallBack();
	}

	else{ /* Return error */ }

}


/******************************************************************************
* !comment  :  ISR Function EXTI2.  							 			  *   
******************************************************************************/

ISR( INT2_VECTOR ){

	if(EXTI2_CallBack != NULL){

		EXTI2_CallBack();
	}

	else{ /* Return error */ }
}



/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/        
