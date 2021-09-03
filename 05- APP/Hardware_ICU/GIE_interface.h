/*****************************************************************************/
/* Title        	: 	GIE Driver					             			 */
/* File Name    	: 	GIE_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	30/10/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include mor 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef GIE_INTERFACE_H
#define GIE_INTERFACE_H

/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/


/******************************************************************************
* Description : Global Interrupt Enable (GIE) Function.		                  *
* Parameters  : none   	   													  *
* Return type : void                                                  	 	  *
******************************************************************************/

void GIE_voidEnable(void);


/******************************************************************************
* Description : Global Interrupt Disable (GIE) Function.		              *
* Parameters  : none   	   													  *
* Return type : void                                                  	 	  *
******************************************************************************/

void GIE_voidDisable(void);



#endif 
/*** !comment : End of gaurd [GIE_INTERFACE_H] *******************************/
