/*****************************************************************************/
/* Title        	: 	I2C Driver							     		     */
/* File Name    	: 	I2C_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	06/01/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
******************************* STD LIB DIRECTIVES ****************************
******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

/******************************************************************************
* !comment  :  Pointer to function for callback.  							  *
******************************************************************************/

static void (*I2C_CallBack)(void) = NULL;

/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/


/******************************************************************************
* Description 	: I2C(TWI) master initialization Function.				      *
******************************************************************************/

void I2C_voidMasterInit(void){


	/* Check prescaler value  */
	#if   PRESCALER == PRESCALER_VALUE_1

		/* prescaler value 1 */
		CLR_BIT(TWSR, TWPS0);
		CLR_BIT(TWSR, TWPS1);

	#elif PRESCALER == PRESCALER_VALUE_4

		/* prescaler value 1 */
		SET_BIT(TWSR, TWPS0);
		CLR_BIT(TWSR, TWPS1);

	#elif PRESCALER == PRESCALER_VALUE_16

		/* prescaler value 1 */
		CLR_BIT(TWSR, TWPS0);
		SET_BIT(TWSR, TWPS1);

	#elif PRESCALER == PRESCALER_VALUE_64

		/* prescaler value 1 */
		SET_BIT(TWSR, TWPS0);
		SET_BIT(TWSR, TWPS1);

	#else
		#error("You Chose Wrong I2C Prescaler Value Option!")
	#endif

	
	/* Bit rate @ CLK 400kHZ */
	TWBR = BIT_RATE;
	

	/* Check on state Acknowledge */
	#if   ACK_STATE == ACK_ENABLE

		/* Enable ACK */
		SET_BIT(TWCR, TWEA);

	#elif ACK_STATE == ACK_DISABLE

		/* Disable ACK */
		CLR_BIT(TWCR, TWEA);

	#else
		#error("You Chose Wrong I2C Acknowledge option!")
	#endif

	
	/* Disable stop condition */
	CLR_BIT(TWCR, TWSTO);
	
	/* Enable I2C Peripheral */
	SET_BIT(TWCR, TWEN);
	
}


/******************************************************************************
* Description 	: I2C(TWI) slave initialization Function.				      *
******************************************************************************/

void I2C_voidSlaveInit(uint8 Copy_u8MyAddress){

	/* set my device address */
	TWAR = (Copy_u8MyAddress << 1);
	

	/* Check on state Acknowledge */
	#if   ACK_STATE == ACK_ENABLE

		/* Enable ACK */
		SET_BIT(TWCR, TWEA);

	#elif ACK_STATE == ACK_DISABLE

		/* Disable ACK */
		CLR_BIT(TWCR, TWEA);

	#else
		#error("You Chose Wrong I2C Acknowledge option!")
	#endif
	

	/* Check on general call recognition */
	#if GENERAL_CALL_STATE == GENERAL_CALL_ENABLE

		/* Enable general call recognition */
		SET_BIT(TWAR, TWGCE);

	#elif GENERAL_CALL_STATE == GENERAL_CALL_DISABLE

		/* Disable general call recognition */
		CLR_BIT(TWAR, TWGCE);
	
	#else
		#error("You Chose Wrong I2C general call recognition option!")
	#endif


	/* Disable stop condition */
	CLR_BIT(TWCR, TWSTO);
	
	/* Enable I2C Peripheral */
	SET_BIT(TWCR, TWEN);

}


/******************************************************************************
* Description 	: I2C(TWI) start condition Function.				          *
******************************************************************************/

void I2C_voidStartCondition(void){

	/* Enable start condition */
	SET_BIT(TWCR, TWSTA);
	
	/* Clear flag */
	SET_BIT(TWCR, TWINT);
	
	/* Wait on the flag */
	while(0 == GET_BIT(TWCR, TWINT));
	
	/* 
	Check on status codes 
	if(0x08 != I2C_u8GetStatus()){

		asm("NOP"); 
	}
	
	else{ /* return error  }
	*/

}


/******************************************************************************
* Description 	: I2C(TWI) repeated start condition Function.			      *
******************************************************************************/

void I2C_voidRepeatedStartCondition(void){

	/* Enable start condition */
	SET_BIT(TWCR, TWSTA);
	
	/* Clear flag */
	SET_BIT(TWCR, TWINT);
	
	/* Wait on the flag */
	while(0 == GET_BIT(TWCR, TWINT));
	
	/* 
	Check on status codes 
	if(0x08 != (TWSR & 0xF8)){

		asm("NOP"); 
	}
	
	else{ /* return error  }
	*/

}


/******************************************************************************
* Description 	: I2C(TWI) stop condition Function.				              *
******************************************************************************/

void I2C_voidStopCondition(void){

	/* Enable stop condition */
	SET_BIT(TWCR, TWSTO);
	
	/* Clear flag */
	SET_BIT(TWCR, TWINT);
	
}


/******************************************************************************
* Description 	: I2C(TWI) send slave address with write Function.		      *
******************************************************************************/

void I2C_voidSendSlaveAddressWithWrite(uint8 Copy_u8SlaveAddress){
	
	TWDR = (Copy_u8SlaveAddress << 1);
	
	/* Write operation */
	CLR_BIT(TWDR, TWD0);
	
	/* Disable start condition */
	CLR_BIT(TWCR, TWSTA);
	
	/* Clear flag */
	SET_BIT(TWCR, TWINT);
	
	/* Wait on the flag */
	while(0 == GET_BIT(TWCR, TWINT));
	
	/* 
	Check on status codes 
	if(0x18 != I2C_u8GetStatus()){

		asm("NOP"); 
	}
	
	else{ /* return error  }
	*/
	
}


/******************************************************************************
* Description 	: I2C(TWI) send slave address with read Function.		      *
******************************************************************************/

void I2C_voidSendSlaveAddressWithRead(uint8 Copy_u8SlaveAddress){
	
	TWDR = (Copy_u8SlaveAddress << 1);
	
	/* Read operation */
	SET_BIT(TWDR, TWD0);
	
	/* Disable start condition */
	CLR_BIT(TWCR, TWSTA);
	
	/* Clear flag */
	SET_BIT(TWCR, TWINT);
	
	/* Wait on the flag */
	while(0 == GET_BIT(TWCR, TWINT));
	
	/* 
	Check on status codes 
	if(0x40 != I2C_u8GetStatus()){

		asm("NOP"); 
	}
	
	else{ // return error  }
	*/
	
}


/******************************************************************************
* Description 	: I2C(TWI) master send data byte Function.				      *
******************************************************************************/

void I2C_voidMasterSendDataByte(uint8 Copy_u8Data){
	
	TWDR = Copy_u8Data;
	
	/* Clear flag */
	SET_BIT(TWCR, TWINT);
	
	/* Wait on the flag */
	while(0 == GET_BIT(TWCR, TWINT));
	
	/* 
	Check on status codes 
	if(0x28 != I2C_u8GetStatus()){
		
		asm("NOP"); 
	}
	
	else{ // return error   }
	*/
	
}


/******************************************************************************
* Description 	: I2C(TWI) master read data byte Function.				      *
******************************************************************************/

uint8 I2C_u8MasterReadDataByte(void){
	
	uint8 Local_u8ReadData = 0;
		
	/* Clear flag */
	SET_BIT(TWCR, TWINT);
	
	/* Wait on the flag */
	while(0 == GET_BIT(TWCR, TWINT));
	
	/* 
	Check on status codes 
	if(0x50 != I2C_u8GetStatus()){ 
	
		asm("NOP"); 
	}
	
	else{  
	
		Local_u8ReadData = TWDR;
	}
	*/
	
	Local_u8ReadData = TWDR;
	
	return Local_u8ReadData;
	
}


/******************************************************************************
* Description 	: I2C(TWI) get status Function.				                  *
******************************************************************************/

uint8 I2C_u8GetStatus(void){

	uint8 Local_u8Status = 0;
  
    /* Check on status codes */
	Local_u8Status = (TWSR & 0xF8);
	
	return Local_u8Status;
}


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function I2C(TWI)) -                     *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void I2C_voidSetCallBack(void(*Local_ptr)(void)){

	I2C_CallBack = Local_ptr;

}

/******************************************************************************
* Description 	: I2C(TWI) Interrupt Enable Function.			              *
******************************************************************************/

void I2C_voidInterruptEnable(void){

	/* Enable I2C interrupt */
	SET_BIT(TWCR, TWIE);

}

/******************************************************************************
* Description 	: I2C(TWI) Interrupt Disable Function.			              *
******************************************************************************/

void I2C_voidInterruptDisable(void){

	/* Disable I2C interrupt */
	CLR_BIT(TWCR, TWIE);

}

/******************************************************************************
* !comment  :  ISR Function I2C(TWI) interrupt.  						      *
******************************************************************************/

ISR( I2C_VEC ){

	if(I2C_CallBack != NULL){

		I2C_CallBack();
	}

	else{ /* Return error */ }
}



/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
