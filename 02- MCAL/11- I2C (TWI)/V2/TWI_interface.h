/*********************************************************************************/
/* Title        	: 	TWI Driver									             */
/* File Name    	: 	TWI_interface.h   		                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	07/05/2021                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

void TWI_voidInit(void);
uint8 TWI_u8SendByte();
uint8 TWI_u8ReadByte();

#endif 
