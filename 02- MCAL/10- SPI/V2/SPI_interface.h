/*****************************************************************************/
/* Title        	: 	SPI Driver									         */
/* File Name    	: 	SPI_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	08/05/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


/******************************************************************************
* !comment : SPI PINS Definition.  			         	                      *
******************************************************************************/
#define  SPI_SS_PIN       12
#define  SPI_MOSI_PIN     13
#define  SPI_MISO_PIN     14
#define  SPI_SCK_PIN      15


/******************************************************************************
************************************ Typedef **********************************
******************************************************************************/


typedef enum{

	SPI_DISABLE,
	SPI_ENABLE,

}SPI_Control;

typedef enum{

	SPI_INTERRUPT_DISABLE,
	SPI_INTERRUPT_ENABLE,
	
}SPI_InterruptState;


typedef enum{

	SPI_MSB,
	SPI_LSB,
	
}SPI_DataOrder;


typedef enum{

	SPI_SLAVE,
	SPI_MASTER,
	
}SPI_Mode;


typedef enum{

	SPI_CLK_MODE0,
	SPI_CLK_MODE1,
	SPI_CLK_MODE2,
	SPI_CLK_MODE3,
	
}SPI_ClockMode;


typedef enum{

	SPI_FCPU_BY_2,
	SPI_FCPU_BY_4,
	SPI_FCPU_BY_8,
	SPI_FCPU_BY_16,
	SPI_FCPU_BY_32,
	SPI_FCPU_BY_64,
	SPI_FCPU_BY_128,
	
}SPI_Freq;


typedef enum{

	SPI_NO_ERROR,
	SPI_WRITE_COLLISON,
	
}SPI_Errors;




typedef struct{
	
	SPI_Control           EnableControl;
	SPI_Mode              Mode;
	SPI_ClockMode         ClockMode;
	SPI_DataOrder         DataOrder;
	SPI_InterruptState    InterruptState;
	
	void(*SPI_CallBack)(void);
	
	/* For Slave Mode --> Freq Shouldnot be Selected */
	SPI_Freq              Freq;
	
	/* This Bit dose not Clear it Self Check it Before Using Data 
	   and Erase the Error your Self by Assigning it to SPI_NO_ERROR */
	SPI_Errors            Error; 
	
}SPI_ConfigStruct;


/******************************************************************************
******************************** Global Variables ***************************** 
******************************************************************************/

extern SPI_ConfigStruct SPI0;

/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/


void SPI_voidInit(void);
void SPI_voidSendChar(uint8 Copy_u8Data);
uint8 SPI_u8ReceiveChar(void);
uint8 SPI_u8ExchangeDataBlocking(uint8 Copy_u8Data);
uint8 SPI_u8ExchangeDataNonBlocking(uint8 Copy_u8Data);
void SPI_voidChipSelectControl(uint8 Copy_u8State);
void SPI_voidSendStringBlocking(uint8 *Copy_u8Data);

#endif 
/*** !comment : End of guard [SPI_INTERFACE_H] *******************************/
