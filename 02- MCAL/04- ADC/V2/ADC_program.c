/*****************************************************************************/
/* Title        	: 	ADC Driver					                         */
/* File Name    	: 	ADC_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	09/12/2020                                           */
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

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

/******************************************************************************
* !comment  :  Gobal variable Deceleration.  						          *
******************************************************************************/

static uint8 ADC_u8ISRSource;		/* Gobal variable to carry ISR source */
static uint8 ADC_u8ChainSize;		/* Gobal variable to carry number of channel */

/******************************************************************************
* !comment  :  Gobal variable Initialization.  					              *
******************************************************************************/

static uint16 *ADC_pu16Reading        = NULL;	/* Gobal variable to carry ADC read value */
static uint8 *ADC_pu8ChainChannalArr  = NULL;   /* Gobal variable to carry chain array */
static uint16 *ADC_pu16ChainResultArr = NULL;   /* Gobal variable to carry chain result */
static uint8 ADC_u8ChainConversionIndex = 0 ;	/* Gobal variable to carry the current conversion index */
uint8 ADC_u8BusyState = ADC_IDLE;				/* Gobal variable to carry busy state */

/******************************************************************************
* !comment  :  Pointer to function for callback.  							  *
******************************************************************************/

static void(*ADC_pvCallBackNotificationFunc)(void) = NULL;

/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/


/******************************************************************************
* Description 	: ADC Initialization Function.				          	      *
******************************************************************************/

void ADC_voidInit(void){

	#if VOLTAGE_REF == AREF

		/* Select Verf = AREF */
		CLR_BIT(ADMUX, REFS0);	CLR_BIT(ADMUX, REFS1);

	#elif VOLTAGE_REF == AVCC

		/* Select Verf = AVCC */
		SET_BIT(ADMUX, REFS0);	CLR_BIT(ADMUX, REFS1);

	#elif VOLTAGE_REF == INTERNAL

		/* Select Verf = INTERNAL */
		SET_BIT(ADMUX, REFS0);	SET_BIT(ADMUX, REFS1);

	#else
		#error("You Chose Wrong Voltage Reference Selections for ADC!")
	#endif

	#if ADJUST_RESULT == RIGHT_ADJUST

		/* select right adjust result */
		CLR_BIT(ADMUX, ADLAR);

	#elif ADJUST_RESULT == LEFT_ADJUST

		/* select left adjust result */
		SET_BIT(ADMUX, ADLAR);

	#else
		#error("You Chose Wrong ADC Adjust Result!")
	#endif
	
	#if AUTO_TRIGGER == AUTO_TRIGGER_ENABLE

		/* Enable of trigger */
		SET_BIT(ADCSRA, ADATE);

		#if AUTO_TRIGGER_SOURCE == FREE_RUNNING

			CLR_BIT(SFIOR, ADTS0);	CLR_BIT(SFIOR, ADTS1);	CLR_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
			
			SET_BIT(SFIOR, ADTS0);	CLR_BIT(SFIOR, ADTS1);	CLR_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRUPT_REQUEST0

			CLR_BIT(SFIOR, ADTS0);	SET_BIT(SFIOR, ADTS1);	CLR_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == TIMER0_COMPARE_MATCH

			SET_BIT(SFIOR, ADTS0);	SET_BIT(SFIOR, ADTS1);	CLR_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == TIMER0_OVERFLOW

			CLR_BIT(SFIOR, ADTS0);	CLR_BIT(SFIOR, ADTS1);	SET_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == TIMER_COMPARE_MATCH_B

			SET_BIT(SFIOR, ADTS0);	CLR_BIT(SFIOR, ADTS1);	SET_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == TIMER1_OVERFLOW

			CLR_BIT(SFIOR, ADTS0);	SET_BIT(SFIOR, ADTS1);	SET_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == TIMER1_CAPTURE_EVENT

			SET_BIT(SFIOR, ADTS0);	SET_BIT(SFIOR, ADTS1);	SET_BIT(SFIOR, ADTS2);

		#else
			#error("You Chose Wrong ADC Auto Trigger Source!")
		#endif

	#elif AUTO_TRIGGER == AUTO_TRIGGER_DISABLE

		/* disable of trigger & Select single conversion */
		CLR_BIT(ADCSRA, ADATE);

	#else
		#error("You Chose Wrong ADC Auto Trigger!")
	#endif

	/* ADC interrupt disable */
	ADC_voidInterruptDisable();	
	
	/* ADC Prescaler */
	ADCSRA &= ADC_PRESCALER_MASK;
	ADCSRA |= ADC_PRESCALER;

	/* Enable ADC */
	SET_BIT(ADCSRA, ADEN);

}



/******************************************************************************
* Description 	: ADC Start Conversion Synch.						          *
******************************************************************************/

uint8 ADC_u8StartConversionSynch(uint8 Copy_u8ChannelNumber, uint16 *Copy_pu16Reading){
	
	uint32 Local_u32Counter  = 0 ;
	uint8 Local_u8ErrorState = OK;
	
	if(ADC_u8BusyState == ADC_IDLE){
	
		/* Make ADC busy in order not work until being idle */
		ADC_u8BusyState = ADC_Busy;
			
		/* channel number must be from A0 --> A7 */
		Copy_u8ChannelNumber &= ADC_CHANNEL_MASK;
	
		/* Clear the MUX bits in ADMUX register */
		ADMUX &= ADC_MUX_MASK;
	
		/* Set the required channel into the MUX bits */
		ADMUX |= Copy_u8ChannelNumber;
	
		/* Start conversion */
		SET_BIT(ADCSRA, ADSC);
	
		/* Polling (Pusy Wait) until the conversion complete flag is set 
		   or counter reaching timeout value */
		while((0 == GET_BIT(ADCSRA, ADIF))&&(Local_u32Counter != ADC_TIMEOUT)){
		
			Local_u32Counter++;
		}
	
		if(Local_u32Counter == ADC_TIMEOUT){
		
			/* Loop is broken because the timeuot is reaching */
			Local_u8ErrorState = NOK;
		}
		else{
		
			/* Loop is broken because flag is raised */
			/* Clear the conversion complete flag */
			SET_BIT(ADCSRA, ADIF);

			/* return data */
			*Copy_pu16Reading = ADC;

			/* Make ADC stste be idle because it finished */
			ADC_u8BusyState = ADC_IDLE;			
		}	
	}
	else{
		
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}


/******************************************************************************
* Description 	: ADC Start Conversion Asynch.				                  *
******************************************************************************/

uint8 ADC_u8StartConversionAsynch(uint8 Copy_u8ChannelNumber, uint16 *Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void)){
	
	uint8 Local_u8ErrorState = OK;
	
	if(ADC_u8BusyState == ADC_IDLE){
	
		if((Copy_pu16Reading == NULL)||(Copy_pvNotificationFunc == NULL)){
		
			Local_u8ErrorState = NULL_PTR;
		}
		else{
		
			/* Make ADC busy in order not work until being idle */
			ADC_u8BusyState = ADC_Busy;
			
			/* Make ISR source: single channel asynchronous */
			ADC_u8ISRSource = SINGLE_CHANNEL_ASYNC;
		
			/* Initialize the reading variable globally */
			ADC_pu16Reading = Copy_pu16Reading;
		
			/* Initialize the callback notification function globally */
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;
			
			/* channel number must be from A0 --> A7 */
			Copy_u8ChannelNumber &= ADC_CHANNEL_MASK;
			
			/* Clear the MUX bits in ADMUX register */
			ADMUX &= ADC_MUX_MASK;
			
			/* Set the required channel into the MUX bits */
			ADMUX |= Copy_u8ChannelNumber;
			
			/* Start conversion */
			SET_BIT(ADCSRA, ADSC);
			
			/* ADC interrupt enable */
			ADC_voidInterruptEnable();
		
		}
	}
	else{
	
		Local_u8ErrorState = BUSY_FUNC;
	}	
	
	return Local_u8ErrorState;
}


/******************************************************************************
* Description 	: ADC Start Conversion Chaine Asynch Function.	         	  *
******************************************************************************/

uint8 ADC_StartConversionChaineAsynch(Chain_t *Copy_Chain){
	
	uint8 Local_u8ErrorState = OK;
	
	/* Check NULL pointer */
	if(Copy_Chain == NULL){
		
		Local_u8ErrorState = NULL_PTR;
	}
	else{
		
		if(ADC_u8BusyState == ADC_IDLE){
			
			/* Make ADC busy in order not work until being idle */
			ADC_u8BusyState = ADC_Busy;
			
			/* Make ISR source: chain channels asynchronous */
			ADC_u8ISRSource = CHAIN_CHANNELS_ASYNC;
			
			/* Initialize chain channel array */
			ADC_pu8ChainChannalArr = Copy_Chain->Channel;
			
			/* Initialize chain result array */
			ADC_pu16ChainResultArr = Copy_Chain->Result;
			
			/* Initialize chain size array */
			ADC_u8ChainSize = Copy_Chain->Size;
			
			/* Initialize chain notification function */
			ADC_pvCallBackNotificationFunc = Copy_Chain->NotificationFunc;

			/* Initialize current conversion index */
			ADC_u8ChainConversionIndex = 0;
			
			/* Set required channel(first channel)  */
			/* Clear the MUX bits in ADMUX register */
			ADMUX &= ADC_MUX_MASK;
			
			/* Set the required channel into the MUX bits */
			ADMUX |= ADC_pu8ChainChannalArr[ADC_u8ChainConversionIndex];
			
			/* Start conversion */
			SET_BIT(ADCSRA, ADSC);
			
			/* ADC interrupt enable */
			ADC_voidInterruptEnable();
			
		}
		else{
			
			Local_u8ErrorState = BUSY_FUNC;
		}
	}
	
	return Local_u8ErrorState;
}


/******************************************************************************
* Description 	: ADC Interrupt Enable Function.				          	  *
******************************************************************************/

void ADC_voidInterruptEnable(void){

	/* ADC interrupt Enable */
	SET_BIT(ADCSRA, ADIE);
}


/******************************************************************************
* Description 	: ADC Interrupt Disable Function.				          	  *
******************************************************************************/

void ADC_voidInterruptDisable(void){

	/* ADC interrupt Disable */
	CLR_BIT(ADCSRA, ADIE);
}


/******************************************************************************
* !comment  : ADC ISR Function.  							 			      *   
******************************************************************************/

ISR(ADC_VECTOR){

	if(ADC_u8ISRSource == SINGLE_CHANNEL_ASYNC){
		
		/* Read ADC result */
		*ADC_pu16Reading = ADC;
		
		/* Make ADC stste be idle because it finished */
		ADC_u8BusyState = ADC_IDLE;
	
		/* Invoke the callback notification function */
		ADC_pvCallBackNotificationFunc();
		
		/* Disable ADC conversion complete interrupt */
		ADC_voidInterruptDisable();	
		
	}
	else if(ADC_u8ISRSource == CHAIN_CHANNELS_ASYNC){
		
		/* Read the current conversion */
		ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex] = ADC;
		
		/* Increment chain index */
		ADC_u8ChainConversionIndex++;
		
		/* Check chain is finished or not */
		if(ADC_u8ChainConversionIndex == ADC_u8ChainSize){
			
			/* Chain is finished */
			/* ADC is now IDLE   */
			ADC_u8BusyState = ADC_IDLE;
			
			/* Invoke the callback notification function */
			ADC_pvCallBackNotificationFunc();
			
			/* Disable ADC conversion complete interrupt */
			ADC_voidInterruptDisable();	
			
		}
		else{
			
			/* Chain is not finished */ 
			/* Set new required channel */
			/* Clear the MUX bits in ADMUX register */
			ADMUX &= ADC_MUX_MASK;
			
			/* Set the required channel into the MUX bits */
			ADMUX |= ADC_pu8ChainChannalArr[ADC_u8ChainConversionIndex];
		
			/* Start new conversion */
			SET_BIT(ADCSRA, ADSC);
			
		}	
	}	
}



/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/  
