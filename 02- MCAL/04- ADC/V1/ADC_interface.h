/*****************************************************************************/
/* Title        	: 	ADC Driver						                     */
/* File Name    	: 	ADC_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	06/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


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
* Return type 	: uint16.                                                     *
*******************************************************************************
* Pre_condition : This function must be used after ADC Initialization         *
*				  Function.                                                   *
******************************************************************************/

uint16 ADC_u16ReadValue(uint8 Copy_u8ChannelNumber);


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


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function ADC) -                          *
*		          [ Layer Architecture Problem Solved ].                      *
* Parameters  	: Pointer to function that points to the first line           *
*				  of the function (ISR).                                      *
* Return type 	: void.                                                    	  *
*******************************************************************************
* Pre_condition : This function must be used after ADC Interrupt  Enable      *
*				  Function.                                                   *
******************************************************************************/

void ADC_voidSetCallBack(void(*Local_ptr)(void));



#endif 
/*** !comment : End of gaurd [ADC_INTERFACE_H] *******************************/
