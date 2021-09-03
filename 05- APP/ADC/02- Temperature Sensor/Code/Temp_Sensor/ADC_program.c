/*********************************************************************************/
/* Title        	: 	ADC Driver									             */
/* File Name    	: 	ADC_program.c   		                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	06/11/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void (*ADC_CallBack)(void) = NULL;

void ADC_voidInit(void){

	#if VOLTAGE_REF == AREF

		/* Select Verf = AREF */
		CLR_BIT(ADMUX, REFS0);
		CLR_BIT(ADMUX, REFS1);

	#elif VOLTAGE_REF == AVCC

		/* Select Verf = AVCC */
		SET_BIT(ADMUX, REFS0);
		CLR_BIT(ADMUX, REFS1);

	#elif VOLTAGE_REF == INTERNAL

		/* Select Verf = INTERNAL */
		SET_BIT(ADMUX, REFS0);
		SET_BIT(ADMUX, REFS1);

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



	#if PRESCALER == DIV_FACTOR_2

		/* Prescaler Select DIV 2 */
		SET_BIT(ADCSRA, ADPS0);
		CLR_BIT(ADCSRA, ADPS1);
		CLR_BIT(ADCSRA, ADPS2);

	#elif PRESCALER == DIV_FACTOR_4

		/* Prescaler Select DIV 4 */
		CLR_BIT(ADCSRA, ADPS0);
		SET_BIT(ADCSRA, ADPS1);
		CLR_BIT(ADCSRA, ADPS2);

	#elif PRESCALER == DIV_FACTOR_8

		/* Prescaler Select DIV 8 */
		SET_BIT(ADCSRA, ADPS0);
		SET_BIT(ADCSRA, ADPS1);
		CLR_BIT(ADCSRA, ADPS2);

	#elif PRESCALER == DIV_FACTOR_16

		/* Prescaler Select DIV 16 */
		CLR_BIT(ADCSRA, ADPS0);
		CLR_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS2);

	#elif PRESCALER == DIV_FACTOR_32

		/* Prescaler Select DIV 32 */
		SET_BIT(ADCSRA, ADPS0);
		CLR_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS2);

	#elif PRESCALER == DIV_FACTOR_64

		/* Prescaler Select DIV 64 */
		CLR_BIT(ADCSRA, ADPS0);
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS2);

	#elif PRESCALER == DIV_FACTOR_128

		/* Prescaler Select DIV 128 */
		SET_BIT(ADCSRA, ADPS0);
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS2);

	#else
		#error("You Chose Wrong ADC Prescaler Value!")
	#endif
	

	#if AUTO_TRIGGER == AUTO_TRIGGER_ENABLE

		/* Enable of trigger */
		SET_BIT(ADCSRA, ADATE);

		#if AUTO_TRIGGER_SOURCE == FREE_RUNNING

			CLR_BIT(SFIOR, ADTS0);
			CLR_BIT(SFIOR, ADTS1);
			CLR_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR

			SET_BIT(SFIOR, ADTS0);
			CLR_BIT(SFIOR, ADTS1);
			CLR_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRUPT_REQUEST0

			CLR_BIT(SFIOR, ADTS0);
			SET_BIT(SFIOR, ADTS1);
			CLR_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == TIMER0_COMPARE_MATCH

			SET_BIT(SFIOR, ADTS0);
			SET_BIT(SFIOR, ADTS1);
			CLR_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == TIMER0_OVERFLOW

			CLR_BIT(SFIOR, ADTS0);
			CLR_BIT(SFIOR, ADTS1);
			SET_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == TIMER_COMPARE_MATCH_B

			SET_BIT(SFIOR, ADTS0);
			CLR_BIT(SFIOR, ADTS1);
			SET_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == TIMER1_OVERFLOW

			CLR_BIT(SFIOR, ADTS0);
			SET_BIT(SFIOR, ADTS1);
			SET_BIT(SFIOR, ADTS2);

		#elif AUTO_TRIGGER_SOURCE == TIMER1_CAPTURE_EVENT

			SET_BIT(SFIOR, ADTS0);
			SET_BIT(SFIOR, ADTS1);
			SET_BIT(SFIOR, ADTS2);

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
	CLR_BIT(ADCSRA, ADIE);

	/* Enable ADC */
	SET_BIT(ADCSRA, ADEN);

}



uint16 ADC_u16ReadValue(uint8 Copy_u8ChannelNumber){
	
	/* channel number must be from A0 --> A7 */
	Copy_u8ChannelNumber &= 0x07;

	/* clear first 5 bits in the ADMUX (channel number MUX4:0 bits)
	   before set the required channel */
	ADMUX &= 0xE0;

	/* choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX |= Copy_u8ChannelNumber;

	/* Start conversion */
	SET_BIT(ADCSRA, ADSC);
	
	/* Wait until end conversion */
	while(0 == GET_BIT(ADCSRA, ADIF));
	
	/* Clear ADC interrupt flag */
	SET_BIT(ADCSRA, ADIF);

	/* return data */
	return ADC;

}



void ADC_u16GetValue(uint8 Copy_u8ChannelNumber){

	/* channel number must be from A0 --> A7 */
	Copy_u8ChannelNumber &= 0x07;

	/* clear first 5 bits in the ADMUX (channel number MUX4:0 bits)
	   before set the required channel */
	ADMUX &= 0xE0;

	/* choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX |= Copy_u8ChannelNumber;

	/* Start conversion */
	SET_BIT(ADCSRA, ADSC);

}



void ADC_voidEnableInterrupt(void){

	/* ADC interrupt Enable */
	SET_BIT(ADCSRA, ADIE);
}



void ADC_voidDisableInterrupt(void){

	/* ADC interrupt Disable */
	CLR_BIT(ADCSRA, ADIE);
}



/* CallBack function ADC  */
void ADC_voidSetCallBack(void(*Local_ptr)(void)){

	ADC_CallBack = Local_ptr;

}




/* ISR Function ADC */
ISR( ADC_VECTOR ){

	ADC_CallBack();

}
