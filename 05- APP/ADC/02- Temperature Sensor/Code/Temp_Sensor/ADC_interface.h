/*********************************************************************************/
/* Title        	: 	ADC Driver									             */
/* File Name    	: 	ADC_interface.h   		                                 */
/* Author       	: 	Fahd Badi                                                */
/* Version      	: 	1.0.0                                                    */
/* Origin Date  	: 	06/11/2020                                               */
/* Notes        	: 	None                                                     */
/*********************************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


/* functions prototype */
void ADC_voidInit(void);
uint16 ADC_u16ReadValue(uint8 Copy_u8ChannelNumber);
void ADC_u16GetValue(uint8 Copy_u8ChannelNumber);
void ADC_voidEnableInterrupt(void);
void ADC_voidDisableInterrupt(void);

/* ADC Channels */
#define CHANNEL_A0     0
#define CHANNEL_A1     1
#define CHANNEL_A2     2
#define CHANNEL_A3     3
#define CHANNEL_A4     4
#define CHANNEL_A5     5
#define CHANNEL_A6     6
#define CHANNEL_A7     7







#endif 
