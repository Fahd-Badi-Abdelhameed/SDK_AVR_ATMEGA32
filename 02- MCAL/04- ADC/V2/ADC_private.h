/*****************************************************************************/
/* Title        	: 	ADC Driver					     				     */
/* File Name    	: 	ADC_private.h      	                                 */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	09/12/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


/******************************************************************************
* !comment : ADC Registers Addesses Definition.  			         	      *
******************************************************************************/

#define ADMUX       *((volatile uint8  *) 0x27)
#define ADCSRA      *((volatile uint8  *) 0x26)
#define ADCH        *((volatile uint8  *) 0x25)
#define ADCL        *((volatile uint8  *) 0x24)
#define ADC         *((volatile uint16 *) 0x24)
#define SFIOR       *((volatile uint8  *) 0x50)


/******************************************************************************
* !comment : ADMUX Register PINS Definition.  			         	          *
******************************************************************************/

#define MUX0      0
#define MUX1      1
#define MUX2      2
#define MUX3      3
#define MUX4      4
#define ADLAR     5
#define REFS0     6
#define REFS1     7


/******************************************************************************
* !comment : ADCSRA Register PINS Definition.  			         	 		  *
******************************************************************************/

#define ADPS0     0
#define ADPS1     1
#define ADPS2     2
#define ADIE      3
#define ADIF      4
#define ADATE     5
#define ADSC      6
#define ADEN      7


/******************************************************************************
* !comment : SFIOR Register PINS Definition.  			         	 		  *
******************************************************************************/

#define ADTS0     5
#define ADTS1     6
#define ADTS2     7


/******************************************************************************
* !comment : Voltage Reference Selections for ADC Definition.  			      *
******************************************************************************/

#define AREF        0
#define AVCC        1
#define INTERNAL    2


/******************************************************************************
* !comment : ADC Adjust Result Definition.  			         	          *
******************************************************************************/

#define LEFT_ADJUST      	0
#define RIGHT_ADJUST     	1


/******************************************************************************
* !comment : ADC Prescaler Selections Definition.  			         	      *
******************************************************************************/

#define DIV_FACTOR_2        1
#define DIV_FACTOR_4   	    2
#define DIV_FACTOR_8        3
#define DIV_FACTOR_16       4
#define DIV_FACTOR_32       5
#define DIV_FACTOR_64       6
#define DIV_FACTOR_128      7


/******************************************************************************
* !comment : ADC Auto Trigger Enable/ Desable Definition.  			     	  *
******************************************************************************/

#define AUTO_TRIGGER_ENABLE      	0
#define AUTO_TRIGGER_DISABLE     	1


/******************************************************************************
* !comment : ADC Auto Trigger Source Selections Definition.  			      *
******************************************************************************/

#define FREE_RUNNING 					0
#define ANALOG_COMPARATOR				1
#define EXTERNAL_INTERRUPT_REQUEST0		2
#define TIMER0_COMPARE_MATCH			3
#define TIMER0_OVERFLOW					4
#define TIMER_COMPARE_MATCH_B			5
#define TIMER1_OVERFLOW					6
#define TIMER1_CAPTURE_EVENT			7


/******************************************************************************
* !comment : TIMER0 Prescaler mask.  			                              *
******************************************************************************/

#define ADC_PRESCALER_MASK		0xF8
#define ADC_CHANNEL_MASK		0x07
#define ADC_MUX_MASK		    0xE0


#define ADC_IDLE 	0
#define ADC_Busy 	1

#define SINGLE_CHANNEL_ASYNC      0
#define CHAIN_CHANNELS_ASYNC      1

#define ADC_TIMEOUT		50000

/******************************************************************************
* !comment : ADC ISR attribute.  					         	              *
******************************************************************************/

#define ISR(vector)\
void vector (void) __attribute__((signal));\
void vector (void)


/******************************************************************************
* !comment : ADC Interrupt Vectors Number Definition.  			              *
******************************************************************************/

#define ADC_VECTOR     __vector_16



#endif 
/*** !comment : End of gaurd [ADC_PRIVATE_H] *********************************/
