/*********************************************************************************/
/* Title        	: 	ADC Driver					         				     */
/* File Name    	: 	ADC_private.h      	                                     */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	06/11/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


/* ADC registers defination */
#define ADMUX       *((volatile uint8  *) 0x27)
#define ADCSRA      *((volatile uint8  *) 0x26)
#define ADCH        *((volatile uint8  *) 0x25)
#define ADCL        *((volatile uint8  *) 0x24)
#define ADC         *((volatile uint16 *) 0x24)
#define SFIOR       *((volatile uint8  *) 0x50)



/* ADMUX register pins defination */
#define MUX0      0
#define MUX1      1
#define MUX2      2
#define MUX3      3
#define MUX4      4
#define ADLAR     5
#define REFS0     6
#define REFS1     7


/* ADCSRA register pins defination */
#define ADPS0     0
#define ADPS1     1
#define ADPS2     2
#define ADIE      3
#define ADIF      4
#define ADATE     5
#define ADSC      6
#define ADEN      7


/* SFIOR register pins defination */
#define ADTS0     5
#define ADTS1     6
#define ADTS2     7


/* Voltage Reference Selections for ADC */
#define AREF        0
#define AVCC        1
#define INTERNAL    2



/*  ADC Adjust Result */
#define LEFT_ADJUST      0
#define RIGHT_ADJUST     1


/* ADC Prescaler Selections */
#define DIV_FACTOR_2        1
#define DIV_FACTOR_4   	    2
#define DIV_FACTOR_8        3
#define DIV_FACTOR_16       4
#define DIV_FACTOR_32       5
#define DIV_FACTOR_64       6
#define DIV_FACTOR_128      7


/* ADC Auto Trigger Enable */
#define AUTO_TRIGGER_ENABLE      0
#define AUTO_TRIGGER_DISABLE     1


/* ADC Auto Trigger Source Selections */
#define FREE_RUNNING 					0
#define ANALOG_COMPARATOR				1
#define EXTERNAL_INTERRUPT_REQUEST0		2
#define TIMER0_COMPARE_MATCH			3
#define TIMER0_OVERFLOW					4
#define TIMER_COMPARE_MATCH_B			5
#define TIMER1_OVERFLOW					6
#define TIMER1_CAPTURE_EVENT			7


/* ISR function prototype */
#define ISR(vector)\
void vector (void) __attribute__((signal));\
void vector (void)


/* ADC Interrupt Vectors */
#define ADC_VECTOR     __vector_16



#endif 
