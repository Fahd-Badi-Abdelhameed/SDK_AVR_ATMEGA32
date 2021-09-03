/*****************************************************************************/
/* Title        	: 	DIO Driver											 */
/* File Name    	: 	DIO_interface.h                                      */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	15/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/******************************************************************************
* !comment : DIO Ports options Definitions.  			         	          *
******************************************************************************/
#define  DIO_PORTA     0
#define  DIO_PORTB     1
#define  DIO_PORTC     2
#define  DIO_PORTD     3


/******************************************************************************
* !comment : DIO Pin Mode options Definitions.  			         	      *
******************************************************************************/
#define  DIO_INPUT      0
#define  DIO_OUTPUT     1

/******************************************************************************
* !comment : DIO Port Mode options Definitions.  			         	      *
******************************************************************************/
#define  DIO_PORT_INPUT      0x00
#define  DIO_PORT_OUTPUT     0xff

/******************************************************************************
* !comment : DIO Pin Value options Definition.  			         	      *
******************************************************************************/
#define  DIO_LOW        0
#define  DIO_HIGH       1

/******************************************************************************
* !comment : DIO Port Value options Definition.  			         	      *
******************************************************************************/
#define  DIO_PORT_LOW        0x00
#define  DIO_PORT_HIGH       0xff

/******************************************************************************
* !comment : DIO Pins options Definition.  			         	          	  *
******************************************************************************/
#define  DIO_PINA0       0
#define  DIO_PINA1       1
#define  DIO_PINA2       2
#define  DIO_PINA3       3
#define  DIO_PINA4       4
#define  DIO_PINA5       5
#define  DIO_PINA6       6
#define  DIO_PINA7       7
#define  DIO_PINB0       8
#define  DIO_PINB1       9
#define  DIO_PINB2       10
#define  DIO_PINB3       11
#define  DIO_PINB4       12
#define  DIO_PINB5       13
#define  DIO_PINB6       14
#define  DIO_PINB7       15
#define  DIO_PINC0       16
#define  DIO_PINC1       17
#define  DIO_PINC2       18
#define  DIO_PINC3       19
#define  DIO_PINC4       20
#define  DIO_PINC5       21
#define  DIO_PINC6       22
#define  DIO_PINC7       23
#define  DIO_PIND0       24
#define  DIO_PIND1       25
#define  DIO_PIND2       26
#define  DIO_PIND3       27
#define  DIO_PIND4       28
#define  DIO_PIND5       29
#define  DIO_PIND6       30
#define  DIO_PIND7       31

/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/


/******************************************************************************
* Description : DIO set PIN direction function.						          *
* Parameters  : PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7),   	  *
*				Mode(OUTPUT, INPUT).     				                      *
* Return type : void                                                  	 	  *
******************************************************************************/
void DIO_voidSetPinDirection(uint8 Copy_u8Pin, uint8 Copy_u8Mode);

/******************************************************************************
* Description : DIO set PIN value function.						              *
* Parameters  : PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7),   	  *
*				Value(HIGH, LOW).     				                          *
* Return type : void                                                  	 	  *
*******************************************************************************
* Pre_condition : This function must be used after set PIN direction          *
* 				  function.				 									  *
******************************************************************************/
void DIO_voidSetPinValue(uint8 Copy_u8Pin, uint8 Copy_u8Value);

/******************************************************************************
* Description : DIO set PORT direction function.						      *
* Parameters  : PORT number(PORT_A -> PORT_D), Mode(OUTPUT, INPUT).   	      *
* Return type : void                                                  	 	  *
******************************************************************************/
void DIO_voidSetPortDirection(uint8 Copy_u8Port, uint8 Copy_u8Mode);


/******************************************************************************
* Description : DIO set PORT Value function.						          *
* Parameters  : PORT number(PORT_A -> PORT_D), Value(HIGH, LOW).   	          *
* Return type : void                                                  	 	  *
*******************************************************************************
* Pre_condition : This function must be used after set PORT direction         *
* 				  function.				 									  *
******************************************************************************/
void DIO_voidSetPortValue(uint8 Copy_u8Port, uint8 Copy_u8Value);


/******************************************************************************
* Description : DIO Toggle PIN function.						              *
* Parameters  : PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7).   	  *
* Return type : void                                                  	 	  *
*******************************************************************************
* Pre_condition : This function must be used after set PIN direction          *
* 				  function.				 									  *
******************************************************************************/
void DIO_voidTogglePin(uint8 Copy_u8Pin);


/******************************************************************************
* Description : DIO Get Pin Value function.						              *
* Parameters  : PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7).   	  *
* Return type : uint8                                                  	 	  *
*******************************************************************************
* Pre_condition : This function must be used after set PIN direction          *
* 				  function.				 									  *
******************************************************************************/
uint8 DIO_u8GetPinValue(uint8 Copy_u8Pin);

uint8 DIO_u8GetPortValue(uint8 Copy_u8Port);

#endif 
/*** !comment : End of gaurd [DIO_INTERFACE_H] *******************************/
