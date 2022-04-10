/*****************************************************************************/
/* Title        	: 	LCD Driver									   	                       */
/* File Name    	: 	LCD_interface.h                                  	     */
/* Author       	: 	Fahd Badi                                              */
/* Version      	: 	1.0.0                                                  */
/* Origin Date  	: 	16/10/2020                                             */
/* Notes        	: 	None                                                   */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			          *
*                 than one time.                               	 	 		        *
******************************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/******************************************************************************
******************************** Global Variables *****************************
******************************************************************************/


/******************************************************************************
* Description 	: LCD Display Char Function.				                          *
* Parameters  	: Data char.   		                                    	      *
* Return type 	: void.                                                  	    *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
void LCD_voidWriteData(uint8 Copy_u8Data);

/******************************************************************************
* Description 	: LCD Initialization Function.				                        *
* Parameters  	: none.   		                                    	 	        *
* Return type 	: void.                                                  	    *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
void LCD_voidInit(void);

/******************************************************************************
* Description 	: LCD Clear Screen Function.				                          *
* Parameters  	: none.   		                                    	 	        *
* Return type 	: void.                                                    	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
void LCD_voidClearScreen(void);

/******************************************************************************
* Description 	: LCD Cursor OFF Function.				                            *
* Parameters  	: none.   		                                    	 	        *
* Return type 	: void.                                                  	    *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
void LCD_voidCursorOff(void);

/******************************************************************************
* Description 	: LCD Cursor ON Function.				                              *
* Parameters  	: none.   		                                    	 	        *
* Return type 	: void.                                                  	    *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
void LCD_voidCursorOn(void);

/******************************************************************************
* Description 	: LCD Write String on LCD Function.				                    *
* Parameters  	: String Data.   		                                          *
* Return type 	: void.                                                  	    *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
void LCD_voidWriteString(char *Copy_cPtrData);

/******************************************************************************
* Description 	: LCD Set Cursor Function.				                            *
* Parameters  	: Row [0, 1] - Col [0 - 15].   		                            *
* Return type 	: void.                                                  	    *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
void LCD_voidSetPosition(uint8 Copy_u8Row, uint8 Copy_u8Col);

/******************************************************************************
* Description 	: LCD Display Loop on LCD Function.				                    *
* Parameters  	: Row [0, 1] - Speed - String Data.   	                      *
* Return type 	: void.                                                  	    *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
void LCD_voidDisplayLoop(uint8 Copy_u8Row, uint8 Copy_u8Speed, char *Copy_cPtr);

/******************************************************************************
* Description 	: LCD Display Number on LCD Function.				                  *
* Parameters  	: Number Data.   	                                            *
* Return type 	: void.                                                  	    *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
void LCD_voidWriteNumber(uint16 Copy_u16Number);

/******************************************************************************
* Description 	: LCD Write Extra Char (CGRAM) Function.				              *
* Parameters  	: Row [0, 1] , Col [0 - 15] , String or Char.                 *
* Return type 	: void.                                                  	    *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
void LCD_voidWriteExtraChar(uint8 Copy_u8Row, uint8 Copy_u8Col, char *Copy_PtrData);


#endif 
/*** !comment : End of gaurd [LCD_INTERFACE_H] *******************************/
