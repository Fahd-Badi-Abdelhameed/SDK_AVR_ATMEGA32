/*****************************************************************************/
/* Title        	: 	EEPROM_24C08 Driver			 			             */
/* File Name    	: 	EEPROM24C08_program.c   		                     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	08/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
*********************************** Includes **********************************
******************************************************************************/
#include "I2C_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "EEPROM24C08_interface.h"
#include "EEPROM24C08_private.h"
#include "EEPROM24C08_config.h"


/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/

/******************************************************************************
* Description 	: Function to initliaiation for external EEPROM 24C08.	      *
******************************************************************************/

void EEPROM24C08_voidInit(void){

	I2C_voidMasterInit();
	
}


/******************************************************************************
* Description 	: Function to write data byte for external EEPROM 24C08.	  *
******************************************************************************/

void EEPROM24C08_voidWriteDataByte(uint16 Copy_u16ByteAddress, uint8 Copy_u8Data){
	
	/* Start condition */
	I2C_voidStartCondition();
							
	/* Send slave address with write operation */
	I2C_voidSendSlaveAddressWithWrite(((EEPROM_FIXED_ADDRESS) | (EEPROM_A2_PIN_VALUE << 2) | ((Copy_u16ByteAddress >> 8) & 3)));
	
	/* Send the rest of the byte address */
	I2C_voidMasterSendDataByte( (uint8)Copy_u16ByteAddress );
	
	/* Send the data byte */
	I2C_voidMasterSendDataByte(Copy_u8Data);
	
	/* Stop condition */
	I2C_voidStopCondition();
}


/******************************************************************************
* Description 	: Function to read data byte for external EEPROM.			  *
******************************************************************************/

uint8 EEPROM24C08_u8ReadDataByte(uint16 Copy_u16ByteAddress){

	uint8 Local_u8Data = 0;
	
	/* Start condition */
	I2C_voidStartCondition();
	
	/* Send slave address with write operation */
	I2C_voidSendSlaveAddressWithWrite(((EEPROM_FIXED_ADDRESS) | (EEPROM_A2_PIN_VALUE << 2) | ((Copy_u16ByteAddress >> 8) & 3)));
	
	/* Send the rest of the byte address */
	I2C_voidMasterSendDataByte( (uint8)Copy_u16ByteAddress );
	
	/* Repeated start condition */
	I2C_voidRepeatedStartCondition();
	
	/* Send slave address with read operation */
	I2C_voidSendSlaveAddressWithRead(((EEPROM_FIXED_ADDRESS) | (EEPROM_A2_PIN_VALUE << 2) | ((Copy_u16ByteAddress >> 8) & 3)));
	
	/* Read data */
	Local_u8Data = I2C_u8MasterReadDataByte();
	
	/* Stop condition */
	I2C_voidStopCondition();
	
	/* Return data */
	return Local_u8Data;
}


/******************************************************************************
* Description 	: Function to write block data for external EEPROM.	          *
******************************************************************************/

void EEPROM24C08_voidWriteBlockData(uint16 Copy_u16ByteAddress, uint8 *Copy_u8Data, uint16 Copy_u16Size){
	
	/* Start condition */
	I2C_voidStartCondition();
							
	/* Send slave address with write operation */
	I2C_voidSendSlaveAddressWithWrite(((EEPROM_FIXED_ADDRESS) | (EEPROM_A2_PIN_VALUE << 2) | ((Copy_u16ByteAddress >> 8) & 3)));
	
	/* Send the rest of the byte address */
	I2C_voidMasterSendDataByte( (uint8)Copy_u16ByteAddress );
	
	for(uint8 Counter=0; Counter<Copy_u16Size; Counter++){
	
		/* Send the data byte */
		I2C_voidMasterSendDataByte(Copy_u8Data[Counter]);
		
	}
	
	/* Stop condition */
	I2C_voidStopCondition();
}


/******************************************************************************
* Description 	: Function to read block data for external EEPROM.	          *
******************************************************************************/

void EEPROM24C08_voidReadBlockData(uint16 Copy_u16ByteAddress, uint16 Copy_u16Size, uint8 *Copy_u8BufferData){

	uint8 Local_u8Data = 0;
	
	/* Start condition */
	I2C_voidStartCondition();
	
	/* Send slave address with write operation */
	I2C_voidSendSlaveAddressWithWrite(((EEPROM_FIXED_ADDRESS) | (EEPROM_A2_PIN_VALUE << 2) | ((Copy_u16ByteAddress >> 8) & 3)));
	
	/* Send the rest of the byte address */
	I2C_voidMasterSendDataByte( (uint8)Copy_u16ByteAddress );
	
	/* Repeated start condition */
	I2C_voidRepeatedStartCondition();
	
	/* Send slave address with read operation */
	I2C_voidSendSlaveAddressWithRead(((EEPROM_FIXED_ADDRESS) | (EEPROM_A2_PIN_VALUE << 2) | ((Copy_u16ByteAddress >> 8) & 3)));
	
	for(uint8 Counter=0; Counter<Copy_u16Size; Counter++){
	
		/* Read data */
		Copy_u8BufferData[Counter] = I2C_u8MasterReadDataByte();
		
	}
	
	/* Stop condition */
	I2C_voidStopCondition();
	
}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
