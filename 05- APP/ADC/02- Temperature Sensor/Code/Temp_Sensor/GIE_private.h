/*********************************************************************************/
/* Title        	: 	GIE Driver					         				     */
/* File Name    	: 	GIE_private.h      	                                     */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	30/10/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef GIE_PRIVATE_H
#define GIE_PRIVATE_H

/******************************************************************************
* Includes												
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/* Global interrupt register defination */
#define SREG      *((volatile uint8 *) 0x5F)

/* SREG register pin defination */
#define GIE    7

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

#endif 
/*** End of File **************************************************************/