/*****************************************************************************/
/* Title        	: 	DIO Driver											 */
/* File Name    	: 	DIO_interface.h                                      */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	10/10/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/


/******************************************************************************
* Description 	: Guard to protect this File from include mor 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/******************************************************************************
* !comment : DIO Ports options Definitions.  			         	          *
******************************************************************************/
#define  PORT_A     (uint8)0
#define  PORT_B     (uint8)1
#define  PORT_C     (uint8)2
#define  PORT_D     (uint8)3


/******************************************************************************
* !comment : DIO Mode options Definitions.  			         	          *
******************************************************************************/
#define  INPUT      (uint8)0
#define  OUTPUT     (uint8)1


/******************************************************************************
* !comment : Value options Definition.  			         	          	  *
******************************************************************************/
#define  LOW        (uint8)0
#define  HIGH       (uint8)1


/******************************************************************************
* !comment : DIO Pins options Definition.  			         	          	  *
******************************************************************************/
#define  PIN0       (uint8)0
#define  PIN1       (uint8)1
#define  PIN2       (uint8)2
#define  PIN3       (uint8)3
#define  PIN4       (uint8)4
#define  PIN5       (uint8)5
#define  PIN6       (uint8)6
#define  PIN7       (uint8)7


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/


/******************************************************************************
* Description : DIO set PIN direction function.						          *
* Parameters  : PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7),   	  *
*				Mode(OUTPUT, INPUT).     				                      *
* Return type : void                                                  	 	  *
******************************************************************************/
void DIO_voidSetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Mode);


/******************************************************************************
* Description : DIO set PIN value function.						              *
* Parameters  : PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7),   	  *
*				Value(HIGH, LOW).     				                          *
* Return type : void                                                  	 	  *
*******************************************************************************
* Pre_condition : This function must be used after set PIN direction          *
* 				  function.				 									  *
******************************************************************************/
void DIO_voidSetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value);


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
void DIO_voidTogglePin(uint8 Copy_u8Port, uint8 Copy_u8Pin);


/******************************************************************************
* Description : DIO Get Pin Value function.						              *
* Parameters  : PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7).   	  *
* Return type : uint8                                                  	 	  *
*******************************************************************************
* Pre_condition : This function must be used after set PIN direction          *
* 				  function.				 									  *
******************************************************************************/
uint8 DIO_u8GetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin);



#endif 
/*** End of File **************************************************************/
