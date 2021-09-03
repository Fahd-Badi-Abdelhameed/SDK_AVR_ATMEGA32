/*****************************************************************************/
/* Title        	: 	ADC Driver						                     */
/* File Name    	: 	ADC_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	2.0.0                                                */
/* Origin Date  	: 	09/12/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


/******************************************************************************
* !comment : typedef Definition.  			         	         			  *
******************************************************************************/

typedef struct{
	
	uint16 *Result;
	uint8 *Channel;
	uint8 Size;
	void(*NotificationFunc)(void);
	
}Chain_t;

/******************************************************************************
* !comment : ADC Channels options Definition.  			         	          *
******************************************************************************/

#define CH_A0     0
#define CH_A1     1
#define CH_A2     2
#define CH_A3     3
#define CH_A4     4
#define CH_A5     5
#define CH_A6     6
#define CH_A7     7


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/


/******************************************************************************
* Description 	: ADC Initialization Function.				          	      *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
******************************************************************************/

void ADC_voidInit(void);


/******************************************************************************
* Description 	: ADC Read Value (Pooling) Function .						  *
* Parameters  	: Channel Number( CH_A0 ---> CH_A7 ).         				  *
* Return type 	: uint8 ErrorState, uint16 ADC_ReadValue.                     *
*******************************************************************************
* Pre_condition : This function must be used after ADC Initialization         *
*				  Function.                                                   *
******************************************************************************/

uint8 ADC_u8StartConversionSynch(uint8 Copy_u8ChannelNumber, uint16 *Copy_pu16Reading);

/******************************************************************************
* Description 	: ADC Get Value (With Interrupt) Function .				      *
* Parameters  	: Channel Number( CH_A0 ---> CH_A7 ).         				  *
* Return type 	: uint16.                                                     *
*******************************************************************************
* Pre_condition : This function must be used after ADC Initialization         *
*				  Function & ADC Enable Interrupt Function.                   *
******************************************************************************/

uint8 ADC_u8StartConversionAsynch(uint8 Copy_u8ChannelNumber, uint16 *Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void));


uint8 ADC_StartConversionChaineAsynch(Chain_t *Copy_Chain);

/******************************************************************************
* Description 	: ADC Interrupt Enable Function.				          	  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after Enable global interrupt.   *
******************************************************************************/

void ADC_voidInterruptEnable(void);


/******************************************************************************
* Description 	: ADC Interrupt Disable Function.				          	  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after Enable global interrupt.   *
******************************************************************************/

void ADC_voidInterruptDisable(void);


#endif 
/*** !comment : End of gaurd [ADC_INTERFACE_H] *******************************/
