/*****************************************************************************/
/* Title        	: 	TIMER0 Driver					        	         */
/* File Name    	: 	TIMER0_private.h      	                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	13/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include mor 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H


/******************************************************************************
* !comment : TIMER0 Registers Addresses Definition.  			         	  *
******************************************************************************/

#define TCCR0    *((volatile uint8 *) 0X53)
#define TCNT0    *((volatile uint8 *) 0x52)
#define OCR0     *((volatile uint8 *) 0x5C)
#define TIMSK    *((volatile uint8 *) 0x59)
#define TIFR     *((volatile uint8 *) 0x58)


/******************************************************************************
* !comment : TCCR0 Register PINS Definition.  			         	          *
******************************************************************************/

#define CS00      (uint8)0
#define CS01      (uint8)1
#define CS02      (uint8)2
#define WGM01     (uint8)3
#define COM00     (uint8)4
#define COM01     (uint8)5
#define WGM00     (uint8)6
#define FOC0      (uint8)7


/******************************************************************************
* !comment : TIMSK Register PINS Definition.  			         	          *
******************************************************************************/

#define TOIE0     (uint8)0
#define OCIE0     (uint8)1


/******************************************************************************
* !comment : TIFR Register PINS Definition.  			         	          *
******************************************************************************/

#define TOV0      (uint8)0
#define OCF0      (uint8)1


/******************************************************************************
* !comment : TIMER0 ISR function prototype.  			         	          *
******************************************************************************/

#define ISR(vector, ...)\
void vector (void) __attribute__((signal));\
void vector (void)


/******************************************************************************
* !comment : TIMER0 Interrupt Vectors Numbers Definition.  			          *
******************************************************************************/

#define TIMER0_OC0      __vector_10
#define TIMER0_OVF      __vector_11


/******************************************************************************
* !comment : TIMER0 maximum count they could reach.  			              *
******************************************************************************/

#define TIMER0_MAX_COUNT    (uint8)255


/******************************************************************************
* !comment : TIMER0 Prescaler mask.  			                              *
******************************************************************************/

#define PRESCALER_MASK		(uint8)0xF8



#endif 
/*** !comment : End of gaurd [TIMER0_PRIVATE_H] ******************************/