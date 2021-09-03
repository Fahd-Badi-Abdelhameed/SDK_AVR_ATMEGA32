/*****************************************************************************/
/* Title        	: 	STD TYPES File									     */
/* File Name    	: 	STD_TYPES.h  		                                 */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	08/08/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char          uint8  ;
typedef signed char            sint8  ;
typedef unsigned short         uint16 ;
typedef signed short           sint16 ;
typedef unsigned long    	   uint32 ;
typedef signed long            sint32 ;
typedef unsigned long long     uint64 ;
typedef signed long long       sint64 ;
typedef float     		       float32;
typedef double       	       float64;

#define NULL	(void *)0

#define OK			0
#define NOK			1
#define NULL_PTR	2
#define BUSY_FUNC   3


#endif
/*** !comment : End of gaurd [STD_TYPES_H] ***********************************/
