/*****************************************************************************/
/* Title        	: 	ULTRASONIC Driver									 */
/* File Name    	: 	ULTRASONIC_private.h      	                 	     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	30/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef ULTRASONIC_PRIVATE_H
#define ULTRASONIC_PRIVATE_H


/******************************************************************************
************************** Prototypes Private Functions ***********************
******************************************************************************/

static void OVF_InterruptAction(void);
static void ICU_InterruptAction(void);

#endif 
/*** !comment : End of gaurd [ULTRASONIC_PRIVATE_H] ************************/
