/*********************************************************************************/
/* Title        	: 	EXIT Driver									             */
/* File Name    	: 	EXIT_program.c   		                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	30/10/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

/******************************************************************************
* Includes
*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXIT_interface.h"
#include "EXIT_private.h"
#include "EXIT_config.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

static void (*EXTI0_CallBack)(void) = NULL;
static void (*EXTI1_CallBack)(void) = NULL;
static void (*EXTI2_CallBack)(void) = NULL;

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

void EXIT0_voidInit(void){

	/* Set PIE EXTI0 */
	SET_BIT(GICR, INT0);
	
	#if   EXTI0_SENSE_MODE == RISING_EDGE
    
		/* Enable EXTI0 rising edge */
		SET_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
	
	#elif EXTI0_SENSE_MODE == FALLING_EDGE
	
		/* Enable EXTI0 falling edge */
		CLR_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
		
	#elif EXTI0_SENSE_MODE == ON_CHANGE 
	
		/* Enable EXTI0 any change -> rising or falling */
		SET_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);

	#elif EXTI0_SENSE_MODE == LOW_LEVEL
	
	    /* Enable EXTI0 low level */
		CLR_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);
	
	#else
		#error("You Chosed Wrong EXTI0 Sense Mode!")
	#endif
	
}


void EXIT1_voidInit(void){

	/* Set PIE EXTI1 */
	SET_BIT(GICR, INT1);
	
	#if   EXTI1_SENSE_MODE == RISING_EDGE
    
		/* Enable EXTI1 rising edge */
		SET_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
	
	#elif EXTI1_SENSE_MODE == FALLING_EDGE
	
		/* Enable EXTI1 falling edge */
		CLR_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
		
	#elif EXTI1_SENSE_MODE == ON_CHANGE 
	
		/* Enable EXTI1 any change -> rising or falling */
		SET_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);

	#elif EXTI1_SENSE_MODE == LOW_LEVEL
	
	    /* Enable EXTI1 low level */
		CLR_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);
	
	#else
		#error("You Chosed Wrong EXTI1 Sense Mode!")
	#endif
	
}


void EXIT2_voidInit(void){

	/* Set PIE EXTI2 */
	SET_BIT(GICR, INT2);
	
	#if   EXTI2_SENSE_MODE == RISING_EDGE
    
		/* Enable EXTI2 rising edge */
		SET_BIT(MCUCSR, ISC2);
		
	#elif EXTI2_SENSE_MODE == FALLING_EDGE
	
		/* Enable EXTI2 falling edge */
		CLR_BIT(MCUCSR, ISC2);
		
	#else
		#error("You Chosed Wrong EXTI2 Sense Mode!")
	#endif
	
}


/* CallBack function EXTI0 */
void EXTI0_voidSetCallBack(void(*ptr)(void)){

	EXTI0_CallBack = ptr;

}


/* CallBack function EXTI1 */
void EXTI1_voidSetCallBack(void(*ptr)(void)){

	EXTI1_CallBack = ptr;

}


/* CallBack function EXTI2 */
void EXTI2_voidSetCallBack(void(*ptr)(void)){

	EXTI2_CallBack = ptr;

}


/* ISR Function EXTI0 */
ISR( INT_VECTOR0 ){

	if(EXTI0_CallBack != NULL){

		EXTI0_CallBack();
	}

	else{ /* Return error */}
}


/* ISR Function EXTI1 */
ISR( INT_VECTOR1 ){

	if(EXTI1_CallBack != NULL){

		EXTI1_CallBack();
	}

	else{ /* Return error */}

}


/* ISR Function EXTI2 */
ISR( INT_VECTOR2 ){

	if(EXTI2_CallBack != NULL){

		EXTI2_CallBack();
	}

	else{ /* Return error */}
}



/*************** END OF FUNCTIONS ***********************************************/

