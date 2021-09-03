/*****************************************************************************/
/* Title        	: 	EXIT Driver					     				     */
/* File Name    	: 	EXIT_private.h      	                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	30/10/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include mor 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef EXIT_PRIVATE_H
#define EXIT_PRIVATE_H


/******************************************************************************
* !comment : External interrupt Registers Addesses Definition.      	      *
******************************************************************************/

#define MCUCR     *((volatile uint8 *) 0x55)
#define MCUCSR    *((volatile uint8 *) 0x54)
#define GICR      *((volatile uint8 *) 0x5B)
#define GIFR      *((volatile uint8 *) 0x5A)
 
 
/******************************************************************************
* !comment : MCUCR Register Pin Definition.      	      					  *
******************************************************************************/

#define ISC00     0
#define ISC01     1
#define ISC10     2
#define ISC11     3


/******************************************************************************
* !comment : MCUCSR Register Pin Definition.      	      					  *
******************************************************************************/

#define ISC2      6


/******************************************************************************
* !comment : GICR Register Pin Definition.      	      					  *
******************************************************************************/

#define INT2      5
#define INT0      6
#define INT1      7


/******************************************************************************
* !comment : GIFR Register Pin Definition.      	      					  *
******************************************************************************/

#define INTF2     5
#define INTF0     6
#define INTF1     7


/******************************************************************************
* !comment : ISR function prototype.       	      					  		  *
******************************************************************************/

#define ISR(vector)\
void vector (void) __attribute__((signal));\
void vector (void)


/******************************************************************************
* !comment : EXIT Interrupt Vectors Numbers.      	      					  *
******************************************************************************/

#define INT0_VECTOR     __vector_1
#define INT1_VECTOR     __vector_2
#define INT2_VECTOR     __vector_3


#endif 
/*** !comment : End of gaurd [ETIT_PRIVATE_H] ********************************/