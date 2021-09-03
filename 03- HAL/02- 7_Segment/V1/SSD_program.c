/*****************************************************************************/
/* Title        	: 	7-Segment Driver									 */
/* File Name    	: 	SSD_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	10/10/2020                                           */
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
****************************** Component DIRECTIVES ***************************
******************************************************************************/

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

/******************************************************************************
******************************** Delay DIRECTIVES *****************************
******************************************************************************/

#include <avr/delay.h>

/******************************************************************************
******************************** Global Variables *****************************  			         	          *
******************************************************************************/

uint8 SSD_Data[10] = 
{
	0x3F, 0x06,
	0x5B, 0x4F, 
	0x66, 0x6D, 
	0x7D, 0x07, 
	0x7F, 0x6F
};


/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/


/******************************************************************************
* Description 	: 7-Segment Initialization Function.				          *
******************************************************************************/

void SSD_voidInit(void){

	/* PORT direction --> Output */
	DIO_voidSetPortDirection(SSD_PORT, 0xFF);

}


/******************************************************************************
* Description : 7-Segment Display Number Function.						      *
******************************************************************************/

void SSD_voidDisplayNumber(uint8 Copy_u8Number){

	#if SSD_COMMON  ==   SSD_CATHODE

		DIO_voidSetPortValue(SSD_PORT, SSD_Data[Copy_u8Number]);

	#elif SSD_COMMON  ==   SSD_ANODE

		DIO_voidSetPortValue(SSD_PORT, ~(SSD_Data[Copy_u8Number]));

	#endif

}


/******************************************************************************
* Description : 7-Segment Display Counter Function.						      *
******************************************************************************/

void SSD_voidDisplayCounter(uint8 Copy_u8Position, uint8 Copy_u8Delay){

	if(Copy_u8Position == SSD_COUNT_UP){

		#if SSD_COMMON  ==   SSD_CATHODE

			for(uint8 i=0 ; i<10; i++){

				DIO_voidSetPortValue(SSD_PORT, SSD_Data[i]);
				_delay_ms(Copy_u8Delay);

			}

		#elif SSD_COMMON  ==   SSD_ANODE

			for(uint8 i=0; i<10; i++){

				DIO_voidSetPortValue(SSD_PORT, ~(SSD_Data[i]));
				_delay_ms(Copy_u8Delay);

			}

		#endif

	}
	else if(Copy_u8Position == SSD_COUNT_DOWN){

		#if SSD_COMMON  ==   SSD_CATHODE

			for(uint8 i=0; i<10; i++){

				DIO_voidSetPortValue(SSD_PORT, SSD_Data[10-i]);
				_delay_ms(Copy_u8Delay);

			}

		#elif SSD_COMMON  ==   SSD_ANODE

			for(uint8 i=0; i<10; i++){

				DIO_voidSetPortValue(SSD_PORT, ~(SSD_Data[10-i]));
				_delay_ms(Copy_u8Delay);

			}

		#endif
	}
}


/******************************************************************************
* Description : 7-Segment Display Char Function.						      *
******************************************************************************/

void SSD_voidDisplayExtraChar(uint8 Copy_u8Char){

	#if SSD_COMMON  ==   SSD_CATHODE

		DIO_voidSetPortValue(SSD_PORT, Copy_u8Char);

	#elif SSD_COMMON  ==   SSD_ANODE

		DIO_voidSetPortValue(SSD_PORT, ~(Copy_u8Char));

	#endif

}



/*********************************************************************************
********************************* END OF PROGRAM *********************************
*********************************************************************************/
