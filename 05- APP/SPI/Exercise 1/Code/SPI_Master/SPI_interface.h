/*********************************************************************************/
/* Title        	: 	SPI Driver									             */
/* File Name    	: 	SPI_interface.h   		                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	05/01/2021                                                */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


void  SPI_voidInitMaster(void);
void  SPI_voidInitSlave(void);

void  SPI_voidSendChar(uint8 Copy_u8Data);
uint8 SPI_u8ReceiveChar(void);

void  SPI_voidTransmitString(uint8 *Copy_u8Data);
uint8 SPI_u8ReceiveString(void);

void SPI_voidEnableInterrupt(void);
void SPI_voidDisableInterrupt(void);

uint8 SPI_u8SendReceiveSynch(uint8 Copy_u8DataTransmit);
void SPI_voidSendReceiveSynch(uint8 Copy_u8DataTransmit, uint8 *Copy_u8DataReceive);
void SPI_voidSendReceiveASynch(uint8 Copy_u8DataTransmit, void(*CallBack)(uint8));



#endif 
