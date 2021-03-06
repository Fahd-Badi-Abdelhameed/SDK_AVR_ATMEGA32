/*****************************************************************************/
/* Title        	: 	WDT Driver					         				 */
/* File Name    	: 	WDT_private.h      	                         	     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	20/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H


/******************************************************************************
* !comment : Watchdog Timer Registers Addresses Definition.  			      *
******************************************************************************/

#define WDTCR     *((volatile uint8 *) 0x41)

/******************************************************************************
* !comment :  WDTCR Register PINS Definition.  			                      *
******************************************************************************/

#define WDP0      0
#define WDP1      1
#define WDP2      2
#define WDE       3
#define WDTOE     4


/******************************************************************************
* !comment :  Watchdog Timer Turn off.				  			              *
******************************************************************************/

#define	WDT_TURN_OFF	0x00

/******************************************************************************
* !comment :  Watchdog Prescaler Mask.				  			              *
******************************************************************************/

#define WDT_PRESCALER_MASK		0xF8



#endif 
/*** !comment : End of gaurd [WDT_PRIVATE_H] *********************************/