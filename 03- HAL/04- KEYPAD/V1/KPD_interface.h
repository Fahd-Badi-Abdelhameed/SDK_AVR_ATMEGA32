/*****************************************************************************/
/* Title        	: 	Keypad Driver			    						 */
/* File Name    	: 	KPD_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	23/10/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H


/******************************************************************************
* !comment : Push Button State Definition.     		                          *
******************************************************************************/

#define KPD_NOT_PRESSED      0
#define KPD_PRESSED    	     1


/******************************************************************************
* Description 	: KPD Initialization Function.				                  *
* Parameters  	: none.   		                                    	 	  *
* Return type 	: void.                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void  KPD_voidInit(void);

/******************************************************************************
* Description 	: KPD Get Pressed Key Function.						          *
* Parameters  	: Row Final, ColumnFinal ( ex: KPD 3x3 ).                     *
* Return type 	: uint8.                                                      *
*******************************************************************************
* Pre_condition : This function must be used after KPD Initialization         *
*				  Function.                                                   *
******************************************************************************/

uint8 KPD_u8GetPressedKey(uint8 Copy_u8RowFinal, uint8 Copy_u8ColumnFinal);


#endif 
/*** !comment : End of gaurd [KPD_INTERFACE_H] *******************************/
