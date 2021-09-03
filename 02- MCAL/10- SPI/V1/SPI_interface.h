/*****************************************************************************/
/* Title        	: 	SPI Driver									         */
/* File Name    	: 	SPI_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	05/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void SPI_voidInitMaster(void);
void SPI_voidInitSlave(void);
void SPI_voidSendChar(uint8 Copy_u8Data);
uint8 SPI_u8ReceiveChar(void);
uint8 SPI_u8ExchangeData(uint8 Copy_u8Data); 
void SPI_voidSendStringBlocking(uint8 *Copy_u8Data);
void SPI_voidEnableInterrupt(void);
void SPI_voidDisableInterrupt(void);
void SPI_voidSetCallBack(void(*Local_ptr)(void));


#endif 
/*** !comment : End of guard [SPI_INTERFACE_H] *******************************/
