/********************************************************************************/
/* Title        	: 	LED Driver											    */
/* File Name    	: 	LED_interface.h   		                                */
/* Author       	: 	Fahd Badi                                               */
/* Version      	: 	1.0.0                                                   */
/* Origin Date  	: 	09/10/2020                                              */
/* Notes        	: 	None                                                    */
/********************************************************************************/

/*********************************************************************************
* Description 	: Guard to protect this File from include more 			      	 *
*                 than one time.                               	 	 			 *
*********************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


/*********************************************************************************
* !comment : LED state option definition.  						      	 		 *
*********************************************************************************/

#define LED_OFF		0
#define LED_ON		1
#define LED_TOG		2

/*********************************************************************************
****************************** Functions Prototypes ******************************
*********************************************************************************/

/*********************************************************************************
* Description : Configuring an LED as output.						        	 *
* Parameters  : none   		                                    	 			 *
* Return type : void                                                  	 	 	 *
*********************************************************************************/

void LED_voidInit(uint8 Copy_u8PortID, uint8 Copy_u8PinNumber);

/*********************************************************************************
* Description 	: Control the state of an LED.							         *
* Parameters  	: PORT number(PORT_A -> PORT_D), PIN number(PIN0 -> PIN7),       *
*				  LED Value (LED_ON, LED_OFF, LED_TOG).     				     *
* Return type 	: void.                                                    	 	 *
**********************************************************************************
* Pre_condition : This function must be used after LED initialized.              *
* 									 											 *
*********************************************************************************/

void LED_voidLedValue(uint8 Copy_u8PortID, uint8 Copy_u8PinNumber, uint8 Copy_u8State);


#endif 
/*** !comment : End of gaurd [LED_INTERFACE_H] **********************************/