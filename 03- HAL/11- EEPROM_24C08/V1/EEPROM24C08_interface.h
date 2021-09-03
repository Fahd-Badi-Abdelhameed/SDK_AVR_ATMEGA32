/*****************************************************************************/
/* Title        	: 	EEPROM_24C08 Driver									 */
/* File Name    	: 	EEPROM24C08_interface.h   		                     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	08/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef EEPROM24C08_INTERFACE_H
#define EEPROM24C08_INTERFACE_H

/******************************************************************************
* Description 	: Function to initliaiation for external EEPROM.	          *
* Parameters  	: none. 		                                              *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void EEPROM_voidInit(void);

/******************************************************************************
* Description 	: Function to write data byte for external EEPROM.			  *
* Parameters  	: Byte Address - Data. 		                                  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after init EEPROM.               *
******************************************************************************/

void EEPROM_voidWriteDataByte(uint16 Copy_u16ByteAddress, uint8 Copy_u18Data);

/******************************************************************************
* Description 	: Function to read data byte for external EEPROM.			  *
* Parameters  	: Byte Address. 		                                  	  *
* Return type 	: uint8                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after init EEPROM.               *
******************************************************************************/

uint8 EEPROM_u8ReadDataByte(uint16 Copy_u16ByteAddress);

/******************************************************************************
* Description 	: Function to write block data for external EEPROM.	          *
* Parameters  	: Byte Address - Data - Size. 		                          *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after init EEPROM.               *
******************************************************************************/

void EEPROM_voidWriteBlockData(uint16 Copy_u16ByteAddress, uint8 *Copy_u8Data, uint16 Copy_u16Size);

/******************************************************************************
* Description 	: Function to read block data for external EEPROM.	          *
* Parameters  	: Byte Address - Data - Size. 		                          *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after init EEPROM.               *
******************************************************************************/

void EEPROM_voidReadBlockData(uint16 Copy_u16ByteAddress, uint16 Copy_u16Size, uint8 *Copy_u8BufferData);


#endif 
/*** !comment : End of gaurd [EEPROM24C08_INTERFACE_H] ***********************/