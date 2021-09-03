/*****************************************************************************/
/* Title        	: 	GIE Driver		        				             */
/* File Name    	: 	GIE_private.h      	                                 */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	30/10/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef GIE_PRIVATE_H
#define GIE_PRIVATE_H


/******************************************************************************
* !comment : Global Interrupt Register Definition.  			         	  *
******************************************************************************/

#define SREG      *((volatile uint8 *) 0x5F)


/******************************************************************************
* !comment : SREG Register Pin Definition.  			         	          *
******************************************************************************/
#define GIE    7


#endif 
/*** !comment : End of gaurd [GIE_PRIVATE_H] *********************************/