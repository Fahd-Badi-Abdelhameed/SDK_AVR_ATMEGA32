/*****************************************************************************/
/* Title        	: 	EEPROM25AA010A Driver								 */
/* File Name    	: 	EEPROM25AA010A_program.c   		                     */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	07/05/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
********************************* DIO DIRECTIVES ******************************
******************************************************************************/
#include "DIO_interface.h"

/******************************************************************************
********************************* Delay DIRECTIVES ****************************
******************************************************************************/
#include <util/delay.h>

/******************************************************************************
********************************* SPI DIRECTIVES ******************************
******************************************************************************/
#include "SPI_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "EEPROM25AA010A_interface.h"
#include "EEPROM25AA010A_private.h"
#include "EEPROM25AA010A_config.h"


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/

void EEPROM25AA010A_voidInit(void){
	
	/* Configure SPI During RunTime */
	SPI0.EnableControl = SPI_ENABLE;
	SPI0.Mode = SPI_MASTER;
	SPI0.ClockMode = SPI_CLK_MODE3;
	SPI0.DataOrder = SPI_MSB;
	SPI0.Freq = SPI_FCPU_BY_4;
	SPI0.InterruptState = SPI_INTERRUPT_DISABLE;

	/* Init SPI */
	SPI_voidInit();
	
}



void EEPROM25AA010A_voidWriteByte(uint8 Copy_u8Data, uint16 Copy_u16Address){
	
	/* Select EEPROM By Applying 0 to Cs */
	//DIO_voidSetPinValue(PORT_B, PIN0, LOW);
	SPI_voidChipSelectControl(0);
	
	/* Write Latch Enable */
	SPI_u8ExchangeDataBlocking(WREN_OPCODE);

	/* Apply High to Cs to Make Write Latch Enable Instruction Excuted */
	//DIO_voidSetPinValue(PORT_B, PIN0, HIGH);
	SPI_voidChipSelectControl(1);
	_delay_ms(5);
	
	/* Select EEPROM By Applying 0 to Cs */
	//DIO_voidSetPinValue(PORT_B, PIN0, LOW);
	SPI_voidChipSelectControl(0);
	
	/* Send Write Instruction */
	SPI_u8ExchangeDataBlocking(WRITE_OPCODE);
	
	/* Send Address the Memory Location */
	SPI_u8ExchangeDataBlocking(Copy_u16Address);

	/* Send Data */
	SPI_u8ExchangeDataBlocking(Copy_u8Data);

	/* Apply High to Cs to Make Write Latch Enable Instruction Excuted */
	//DIO_voidSetPinValue(PORT_B, PIN0, HIGH); 
	SPI_voidChipSelectControl(1);
	_delay_ms(5);
	
}



uint8 EEPROM25AA010A_u8ReadByte(uint16 Copy_u16Address){
	
	uint8 Local_u8ReadData = 0;
	
	/* Select EEPROM By Applying 0 to Cs */
	SPI_voidChipSelectControl(0);
	
	/* Read Latch Enable */
	SPI_u8ExchangeDataBlocking(READ_OPCODE);

	/* Send Address the Memory Location */
	SPI_u8ExchangeDataBlocking(Copy_u16Address);

	Local_u8ReadData = SPI_u8ExchangeDataBlocking(DUMMY_DATA);

	SPI_voidChipSelectControl(1);
	
	return Local_u8ReadData;
}

/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
