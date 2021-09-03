/*********************************************************************************/
/* Title        	: 	TWI Driver									             */
/* File Name    	: 	TWI_program.c   		                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	07/05/2021                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

#define READ_MODE           0x01     
#define WRITE_MODE          0x00

#define START_COND_CODE     0x08
#define SLA_WR_ACK_CODE     0x18
#define DATA_WR_ACK_CODE    0x28
#define REP_START_CODE      0x10
#define SLA_RD_ACK_CODE     0x40
#define DATA_RD_NACK_CODE   0x58


void TWI_voidInit(void){
	
	TWAR = 0x88;
	
	/* Setting SCL Freq = 100khz when F_CPU = 1MHZ */
	TWBR = 42;
	TWSR = 0;
	
	/* Enable I2C */
	TWCR = (1<<TWEN);
	
}


uint8 TWI_u8WriteByte(uint8 Copy_u8SlaveAddress, uint8 Copy_u8InternalRegister, uint8 Copy_u8Data){
	
	/* Start Condation */
	TWI_voidStartCondition();
	
	if(TWI_u8GetStatus() != START_COND_CODE){
	
		/* error */
	}
	
	TWI_voidWriteData((Copy_u8SlaveAddress<<1)|(WRITE_MODE));
	
	if(TWI_u8GetStatus() != SLA_WR_ACK_CODE){
	
		/* error */
	}
	
	TWI_voidWriteData(Copy_u8InternalRegister);
	
	if(TWI_u8GetStatus() != DATA_WR_ACK_CODE){
	
		/* error */
	}
	
	TWI_voidWriteData(Copy_u8Data);
	
	if(TWI_u8GetStatus() != DATA_WR_ACK_CODE){
	
		/* error */
	}
	
	TWI_voidStopCondition();
	
}



uint8 TWI_u8ReadByte(uint8 Copy_u8SlaveAddress, uint8 Copy_u8InternalRegister){

	uint8 DataRx = 0;
	TWI_voidStartCondition();
	
	if(TWI_u8GetStatus() != START_COND_CODE){
	
		/* error */
	}
	
	TWI_voidWriteData((Copy_u8SlaveAddress<<1)|(WRITE_MODE));
	
	if(TWI_u8GetStatus() != SLA_WR_ACK_CODE){
	
		/* error */
	}
	
	TWI_voidWriteData(Copy_u8InternalRegister);
	
	if(TWI_u8GetStatus() != DATA_WR_ACK_CODE){
	
		/* error */
	}
	
	TWI_voidStartCondition();
	
	if(TWI_u8GetStatus() != REP_START_CODE){
	
		/* error */
	}
	
	TWI_voidWriteData((Copy_u8SlaveAddress<<1)|(READ_MODE));
	
	if(TWI_u8GetStatus() != SLA_RD_ACK_CODE){
	
		/* error */
	}
	
	DataRx = TWI_u8ReadDataWithACK();
	
	if(TWI_u8GetStatus() != DATA_RD_NACK_CODE){
	
		/* error */
	}
	
	TWI_voidStopCondition();
	
	return DataRx;

}


static void TWI_voidStartCondition(void){

	TWCR &= 0x07;
	
	TWCR |= (1<<TWSTA)|(1<<TWINT);
	
	while((TWCR & (1<<TWINT)) == 0);

}



static void TWI_voidStopCondition(void){

	TWCR &= 0x07;
	
	TWCR |= (1<<TWSTO)|(1<<TWINT);
	
	while((TWCR & (1<<TWINT)) == 0);

}


static void TWI_voidWriteData(uint8 Copy_u8Data){
 
 	TWCR &= 0x07;
	
	TWDR = Copy_u8Data;

	TWCR |= (1<<TWINT);
	
	while((TWCR & (1<<TWINT)) == 0);
	
}


static uint8 TWI_u8ReadDataWithACK(void){
 
 	TWCR &= 0x07;
	
	TWCR |= (1<<TWINT)|(1<<TWEA);
	
	while((TWCR & (1<<TWINT)) == 0);
	
	return TWDR;
	
}


static uint8 TWI_u8ReadDataWithNACK(void){
 
	TWCR &= 0x07;
	
	TWCR |= (1<<TWINT);
	
	while((TWCR & (1<<TWINT)) == 0);
	
	return TWDR;
	
}


static uint8 TWI_u8GetStatus(void){

	return (TWSR & 0xF8);

}
