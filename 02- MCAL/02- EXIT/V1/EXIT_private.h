/*********************************************************************************/
/* Title        	: 	EXIT Driver					         				     */
/* File Name    	: 	EXIT_private.h      	                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	30/10/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef EXIT_PRIVATE_H
#define EXIT_PRIVATE_H

/******************************************************************************
* Includes												
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/* External interrupt register defination */
#define MCUCR     *((volatile uint8 *) 0x55)
#define MCUCSR    *((volatile uint8 *) 0x54)
#define GICR      *((volatile uint8 *) 0x5B)
#define GIFR      *((volatile uint8 *) 0x5A)
 
 
/* MCUCR register pin defination */
#define ISC00     0
#define ISC01     1
#define ISC10     2
#define ISC11     3


/* MCUCSR register pin defination */
#define ISC2     6


/* GICR register pin defination */
#define INT2     5
#define INT0     6
#define INT1     7


/* GIFR register pin defination */
#define INTF2     5
#define INTF0     6
#define INTF1     7

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/* External interrupt sense mode opetions:  */
#define LOW_LEVEL       0
#define ON_CHANGE       1
#define FALLING_EDGE	2
#define RISING_EDGE     3

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/* ISR function prototype */
#define ISR(vector)\
void vector (void) __attribute__((signal));\
void vector (void)


/* EXIT Interrupt Vectors */
#define INT0     __vector_1
#define INT1     __vector_2
#define INT2     __vector_3


#endif 
/*** End of File **************************************************************/
