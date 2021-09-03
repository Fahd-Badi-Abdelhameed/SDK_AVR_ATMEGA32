/*****************************************************************************/
/* Title        	: 	MCP2515(CAN External) Driver		        		 */
/* File Name    	: 	MCP2515_program.h      		                         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	26/04/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
********************************** MCAL DIRECTIVES ****************************
******************************************************************************/
#include "DIO_interface.h"
#include "SPI_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "MCP2515_interface.h"
#include "MCP2515_private.h"
#include "MCP2515_config.h"
	
/******************************************************************************
**************************** Globle Varible **************************
******************************************************************************/
uint8 readBuffer[14] = {0};
	

/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/

static uint8 MCP2515_u8ReadRegister(uint8 Copy_u8AddressByte){

	uint8 Local_u8ReadValue = 0;
	
	SPI_voidChipSelectControl(0);
	
	SPI_u8ExchangeDataBlocking(MCP2515_INST_READ );
	SPI_u8ExchangeDataBlocking(Copy_u8AddressByte);
	Local_u8ReadValue = SPI_u8ExchangeDataBlocking(0);

	SPI_voidChipSelectControl(1);
	
	return Local_u8ReadValue;
	
}



static void MCP2515_voidWriteRegister(uint8 Copy_u8AddressByte, uint8 Copy_u8DataByte){

	SPI_voidChipSelectControl(0);
	
	SPI_u8ExchangeDataBlocking(MCP2515_INST_WRITE);
	SPI_u8ExchangeDataBlocking(Copy_u8AddressByte);
	SPI_u8ExchangeDataBlocking(Copy_u8DataByte   );
	
	SPI_voidChipSelectControl(1);
	
}



static void MCP2515_voidReset(void){

	SPI_voidChipSelectControl(0);
	SPI_u8ExchangeDataBlocking(MCP2515_INST_RESET);
	SPI_voidChipSelectControl(1);
	
}



static void MCP2515_voidBitModify(uint8 Copy_u8AddressByte, uint8 Copy_u8MaskByte, uint8 Copy_u8DataByte){

	SPI_voidChipSelectControl(0);
	
	SPI_u8ExchangeDataBlocking(MCP2515_INST_MODIFY);
	SPI_u8ExchangeDataBlocking(Copy_u8AddressByte );
	SPI_u8ExchangeDataBlocking(Copy_u8MaskByte    );
	SPI_u8ExchangeDataBlocking(Copy_u8DataByte    );
	
	SPI_voidChipSelectControl(1);

}



static void MCP2515_voidRequestToSend(uint8 Copy_u8BufferNumber){

	SPI_voidChipSelectControl(0);
	SPI_u8ExchangeDataBlocking(Copy_u8BufferNumber);
	SPI_voidChipSelectControl(1);
	
} 



static void MCP2515_voidSetBitTiming(uint8 Copy_u8CNF1VAL, uint8 Copy_u8CNF2VAL, uint8 Copy_u8CNF3VAL){

	MCP2515_voidWriteRegister(CNF1, Copy_u8CNF1VAL);
	MCP2515_voidWriteRegister(CNF2, Copy_u8CNF2VAL);
	MCP2515_voidWriteRegister(CNF3, Copy_u8CNF3VAL);

}



static void MCP2515_voidSetMode(uint8 Copy_u8Mode){

	MCP2515_voidBitModify(CANCTRL, 0xE0, (Copy_u8Mode << 5));    
	while((MCP2515_u8ReadRegister(CANSTAT)>>5) != Copy_u8Mode);

}



void MCP2515_voidSendMessage(uint8 Copy_u8BufIdx, uint32 Copy_u32MsgID, uint8 Copy_u8DLC, uint8 *Copy_u8Data){

	SPI_voidChipSelectControl(0);

	/* Send Header and Address */
	SPI_u8ExchangeDataBlocking(MCP2515_INST_WRITE);
	SPI_u8ExchangeDataBlocking(TXB0CTRL);
	
	/* Setup priority [mandatory] */
	SPI_u8ExchangeDataBlocking(Copy_u8DLC >> 6);
	
	/* 
	// Setup Extended Identifier 
	SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MsgID >> 3 ));
	SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MsgID << 5 )|(1<<3)|(uint8)(Copy_u32MsgID >> 27));
	SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MsgID >> 19));
	SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MsgID << 11));
	*/
	
	
	/* Setup Standard Identifier */
	SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MsgID >> 3));
	SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MsgID << 5));
	SPI_u8ExchangeDataBlocking(0);
	SPI_u8ExchangeDataBlocking(0);
	
	/* Setup Message Length and RTR Bit */
	SPI_u8ExchangeDataBlocking(Copy_u8DLC & 0x0F);
	
	/* Store the Message Into the Buffer */
	for(uint8 Iteration=0; Iteration<(Copy_u8DLC & 0x0F); Iteration++){
	
		SPI_u8ExchangeDataBlocking(Copy_u8Data[Iteration]);
	
	}
	
	/* Release the Bus */
	SPI_voidChipSelectControl(1);
	
	/* Send Request to Send */
	MCP2515_voidRequestToSend(MCP2515_INST_RTS_TXB0);
	
}


void MCP2515_voidTransmitInit(void){

	/* Configure SPI During RunTime */
	SPI0.EnableControl = SPI_ENABLE;
	SPI0.Mode = SPI_MASTER;
	SPI0.ClockMode = SPI_CLK_MODE0;
	SPI0.DataOrder = SPI_MSB;
	SPI0.Freq = SPI_FCPU_BY_4;
	SPI0.InterruptState = SPI_INTERRUPT_DISABLE;

	/* SPI Initialization */
	SPI_voidInit();

	MCP2515_voidReset();

	/* Enter Config Mode and Enable Clock */

	/*
	 * MCP2515_voidSetMode(MCP2515_MODE_CONFIG);
	 * MCP2515_voidWriteRegister(CANCTRL, 0x04);
	 */
	MCP2515_voidWriteRegister(CANCTRL, 0x84);

	while((MCP2515_u8ReadRegister(CANSTAT)>>5) != MCP2515_MODE_CONFIG);

	//MCP2515_voidSetBitTiming(CNF1_VALUE, CNF2_VALUE, CNF3_VALUE);
	MCP2515_voidSetBitTiming((2<<6), (1<<7)|(6<<3)|(1), (5));

	MCP2515_voidSetMode(MCP2515_MODE_NORMAL);

}



static void MCP2515_voidSetRollover(void){

	MCP2515_voidBitModify(RXB0CTRL, (1<<BUKT), (1<<BUKT));

}


static void MCP2515_voidSetMask(uint8 Copy_u8MaskAddress, uint32 Copy_u32MaskValue, uint8 Copy_u8Extended){

	SPI_voidChipSelectControl(0);
	
	SPI_u8ExchangeDataBlocking(MCP2515_INST_WRITE);
	SPI_u8ExchangeDataBlocking(Copy_u8MaskAddress);
	
	if(Copy_u8Extended){
	
		/* Extended Identifier */
		SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MaskValue >> 3 ));
		SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MaskValue << 5 )|(1<<3)|(uint8)(Copy_u32MaskValue >> 27));
		SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MaskValue >> 19));
		SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MaskValue << 11));
	
	}
	else{
	
		/* Standard Identifier */
		SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MaskValue >> 3));
		SPI_u8ExchangeDataBlocking((uint8)(Copy_u32MaskValue << 5));
	
	}
	
	SPI_voidChipSelectControl(1);

}



void MCP2515_voidReceiveInit(void){

	/* Configure SPI During RunTime */
	SPI0.EnableControl = SPI_ENABLE;
	SPI0.Mode = SPI_MASTER;
	SPI0.ClockMode = SPI_CLK_MODE0;
	SPI0.DataOrder = SPI_MSB;
	SPI0.Freq = SPI_FCPU_BY_4;
	SPI0.InterruptState = SPI_INTERRUPT_DISABLE;

	/* SPI Initialization */
	SPI_voidInit();
	
	MCP2515_voidReset();
	
	/* Enter Config Mode and Enable Clock */
	
	/* 
	 * MCP2515_voidSetMode(MCP2515_MODE_CONFIG); 
	 * MCP2515_voidWriteRegister(CANCTRL, 0x04); 
	 */
	MCP2515_voidWriteRegister(CANCTRL, 0x84);	

	while((MCP2515_u8ReadRegister(CANSTAT)>>5) != MCP2515_MODE_CONFIG);
	
    /* to run at 250KHz bitrate using 8MHz osc  */
	MCP2515_voidSetBitTiming((2<<6), (1<<7)|(6<<3)|(1), (5));
	
	/* Accept all messages */
	MCP2515_voidSetMask(RXM0SIDH, 0x00000000, 1);
	
	/* Accept all messages */
	MCP2515_voidSetMask(RXM1SIDH, 0x00000000, 1);
	
	/* Enable interrupt */
	MCP2515_voidWriteRegister(CANINTE, (1<<RX0IE));
	
	MCP2515_voidSetMode(MCP2515_MODE_NORMAL);
	
}



void MCP2515_voidReceiveMessage(void){
	
	SPI_voidChipSelectControl(0);
	
	SPI_u8ExchangeDataBlocking(MCP2515_INST_READ);
	
	SPI_u8ExchangeDataBlocking(RXB0CTRL);
	
	for(uint8 Iteration=0; Iteration<14; Iteration++){
	
		readBuffer[Iteration] = SPI_u8ExchangeDataBlocking(0);
	}
	
	SPI_voidChipSelectControl(1);
	
	MCP2515_voidWriteRegister(CANINTF, 0);
	
}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
