/*****************************************************************************/
/* Title        	: 	TIMER1 Driver									     */
/* File Name    	: 	TIMER1_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	15/11/2020                                           */
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

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"

/******************************************************************************
* !comment  :  Module Global Variable.  							          *
******************************************************************************/

static volatile uint16 Global_u16Time1;
static volatile uint16 Global_u16Time2;
static volatile uint16 Global_u16Time3;
static volatile uint16 Global_u16Flag = 0;

/******************************************************************************
* !comment  :  Pointer to function for callback.  							  *
******************************************************************************/

static void( *TIMER1_OVF_CallBack )(void) = NULL;
static void( *TIMER1_OCB_CallBack )(void) = NULL;
static void( *TIMER1_OCA_CallBack )(void) = NULL;
static void( *TIMER1_ICU_CallBack )(void) = NULL;

/******************************************************************************
**************************** Function Implementation **************************
******************************************************************************/

/******************************************************************************
* Description 	: TIMER1 Initialization Function to select timer mode         *
*			      & Prescaler vale.                                           *
******************************************************************************/

void TIMER1_voidInit(Timer1_Mode_t Mode, Timer1_Scaler_t Prescaler){

	switch(Mode){

		case TIMER1_NORMAL_MODE:
			/* Timer1 Mode Normal or Overflow */
			CLR_BIT(TCCR1A, WGM10);
			CLR_BIT(TCCR1A, WGM11);
			CLR_BIT(TCCR1B, WGM12);
			CLR_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_PHASE_CORRECT_8BIT_MODE:
			/* Timer1 Mode PWM, Phase Correct, 8-bit */
			SET_BIT(TCCR1A, WGM10);
			CLR_BIT(TCCR1A, WGM11);
			CLR_BIT(TCCR1B, WGM12);
			CLR_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_PHASE_CORRECT_9BIT_MODE:
			/* Timer1 Mode PWM, Phase Correct, 9-bit */
			CLR_BIT(TCCR1A, WGM10);
			SET_BIT(TCCR1A, WGM11);
			CLR_BIT(TCCR1B, WGM12);
			CLR_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_PHASE_CORRECT_10BIT_MODE:
			/* Timer1 Mode PWM, Phase Correct, 10-bit */
			SET_BIT(TCCR1A, WGM10);
			SET_BIT(TCCR1A, WGM11);
			CLR_BIT(TCCR1B, WGM12);
			CLR_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_CTC_OCR1A_MODE:
			/* Timer1 Mode CTC Top OCR1A */
			CLR_BIT(TCCR1A, WGM10);
			CLR_BIT(TCCR1A, WGM11);
			SET_BIT(TCCR1B, WGM12);
			CLR_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_FAST_PWM_8BIT_MODE:
			/* Timer1 Mode Fast PWM, 8-bit */
			SET_BIT(TCCR1A, WGM10);
			CLR_BIT(TCCR1A, WGM11);
			SET_BIT(TCCR1B, WGM12);
			CLR_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_FAST_PWM_9BIT_MODE:
			/* Timer1 Mode Fast PWM, 9-bit */
			CLR_BIT(TCCR1A, WGM10);
			SET_BIT(TCCR1A, WGM11);
			SET_BIT(TCCR1B, WGM12);
			CLR_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_FAST_PWM_10BIT_MODE:
			/* Timer1 Mode Fast PWM, 10-bit */
			SET_BIT(TCCR1A, WGM10);
			SET_BIT(TCCR1A, WGM11);
			SET_BIT(TCCR1B, WGM12);
			CLR_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_MODE:
			/* Timer1 Mode PWM, Phase and Frequency Correct Top ICR1 */
			CLR_BIT(TCCR1A, WGM10);
			CLR_BIT(TCCR1A, WGM11);
			CLR_BIT(TCCR1B, WGM12);
			SET_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_MODE:
			/* Timer1 Mode PWM, Phase and Frequency Correct Top OCR1A */
			SET_BIT(TCCR1A, WGM10);
			CLR_BIT(TCCR1A, WGM11);
			CLR_BIT(TCCR1B, WGM12);
			SET_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_PWM_PHASE_CORRECT_ICR1_MODE:
			/* Timer1 Mode PWM, Phase Correct Top ICR1 */
			CLR_BIT(TCCR1A, WGM10);
			SET_BIT(TCCR1A, WGM11);
			CLR_BIT(TCCR1B, WGM12);
			SET_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE:
			/* Timer1 Mode PWM, Phase Correct Top OCR1A */
			SET_BIT(TCCR1A, WGM10);
			SET_BIT(TCCR1A, WGM11);
			CLR_BIT(TCCR1B, WGM12);
			SET_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_CTC_ICR1_MODE:
			/* Timer1 Mode CTC Top ICR1 */
			CLR_BIT(TCCR1A, WGM10);
			CLR_BIT(TCCR1A, WGM11);
			SET_BIT(TCCR1B, WGM12);
			SET_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_FAST_PWM_ICR1_MODE:
			/* Timer1 Mode Fast PWM Top ICR1 */
			CLR_BIT(TCCR1A, WGM10);
			SET_BIT(TCCR1A, WGM11);
			SET_BIT(TCCR1B, WGM12);
			SET_BIT(TCCR1B, WGM13);
		break;

		case TIMER1_FAST_PWM_OCR1A_MODE:
			/* Timer1 Mode Fast PWM Top OCR1A */
			SET_BIT(TCCR1A, WGM10);
			SET_BIT(TCCR1A, WGM11);
			SET_BIT(TCCR1B, WGM12);
			SET_BIT(TCCR1B, WGM13);
		break;
		default:    break;
	}

	/* Prescaler mask */
	TCCR1B &= PRESCALER_MASK;
	/* Set prescaler value */
	TCCR1B |= Prescaler;
	
}

/******************************************************************************
* Description 	: TIMER1 Output Compare initialization Function to            *
*                 Select Output Compare Mode & Channel.                       *
******************************************************************************/

void TIMER1_voidOutputCompareInit(Timer1_OutputCompareMode_t OC1_Mode, Timer1_Channel_t OC1_Channel){

	switch(OC1_Mode){

		case TIMER1_OC1_DISCONNECTED_MODE:

			switch(OC1_Channel){

				case TIMER1_OCR1A:
					/* Select channel A normal */
					CLR_BIT(TCCR1A, COM1A0);
					CLR_BIT(TCCR1A, COM1A1);
				break;

				case TIMER1_OCR1B:
					/* Select channel B normal */
					CLR_BIT(TCCR1A, COM1B0);
					CLR_BIT(TCCR1A, COM1B1);
				break;
				default:  break;
			}
		break;

		case TIMER1_OC1_TOGGLE_MODE:

			switch(OC1_Channel){

				case TIMER1_OCR1A:
					/* Select Channel A Toggle */
					SET_BIT(TCCR1A, COM1A0);
					CLR_BIT(TCCR1A, COM1A1);
				break;

				case TIMER1_OCR1B:
					/* Select Channel B Toggle */
					SET_BIT(TCCR1A, COM1B0);
					CLR_BIT(TCCR1A, COM1B1);
				break;
				default:  break;
			}
		break;

		case TIMER1_OC1_NON_INVERTING_MODE:

			switch(OC1_Channel){

				case TIMER1_OCR1A:
					/* Select Channel A Non-inverting */
					CLR_BIT(TCCR1A, COM1A0);
					SET_BIT(TCCR1A, COM1A1);
				break;

				case TIMER1_OCR1B:
					/* Select Channel B Non-inverting */
					CLR_BIT(TCCR1A, COM1B0);
					SET_BIT(TCCR1A, COM1B1);
				break;
				default:  break;
			}
		break;

		case TIMER1_OC1_INVERTING_MODE:

			switch(OC1_Channel){

				case TIMER1_OCR1A:
					/* Select Channel A Inverting */
					SET_BIT(TCCR1A, COM1A0);
					SET_BIT(TCCR1A, COM1A1);
				break;

				case TIMER1_OCR1B:
					/* Select Channel B Inverting */
					SET_BIT(TCCR1A, COM1B0);
					SET_BIT(TCCR1A, COM1B1);
				break;
				default:  break;
			}
		break;
		default:  break;
	}
}

/******************************************************************************
* Description 	: TIMER1 Get Input Capture Register1 Value Function.		  *
******************************************************************************/

uint16 TIMER1_u16GetICR1(void){

	return ICR1;
}

/******************************************************************************
* Description 	: TIMER1 Set Output Compare Register1 A Value.	              *
******************************************************************************/

void TIMER1_voidSetOCR1A(uint16 Copy_u16Value){

	OCR1A = Copy_u16Value;

}

/******************************************************************************
* Description 	: TIMER1 Set Output Compare Register1 B Value.	              *
******************************************************************************/

void TIMER1_voidSetOCR1B(uint16 Copy_u16Value){

	OCR1B = Copy_u16Value;

}

/******************************************************************************
* Description 	: TIMER1 Set Input Capture Register1 Value.	                  *
******************************************************************************/

void TIMER1_voidSetICR1(uint16 Copy_u16Value){

	 ICR1 = Copy_u16Value;
}

/******************************************************************************
* Description 	: TIMER1 Set TCNT1 Value.	                                  *
******************************************************************************/

void TIMER1_voidSetTCNT1(uint16 Copy_u16Value){

	TCNT1 = Copy_u16Value;

}

/******************************************************************************
* Description 	: TIMER1 PWM initialization Function.		                  *
******************************************************************************/

void PWM1_voidInit(void){

	TIMER1_voidInit(TIMER1_FAST_PWM_ICR1_MODE, TIMER1_SCALER_8);

	TIMER1_voidOutputCompareInit(TIMER1_OC1_NON_INVERTING_MODE, TIMER1_OCR1A);

}

/******************************************************************************
* Description 	: TIMER1 Generate PWM @ Frequency (KHZ) Function.		      *
******************************************************************************/

void PWM1_voidFreqKHZ(uint16 Copy_u16Freq){

	if(0 == Copy_u16Freq){

		/* return error */
	}
	else{

		uint16 Local_u16TimeTotal = 1000 / Copy_u16Freq;

		if(Local_u16TimeTotal >= 1){

			ICR1 = Local_u16TimeTotal - 1;
		}
		else{ ICR1 = 0; }
	}
}

/******************************************************************************
* Description 	: TIMER1 Generate PWM @ Frequency (HZ) Function.		      *
******************************************************************************/

void PWM1_voidFreqHZ(uint16 Copy_u16Freq){

	if(0 == Copy_u16Freq){

		/* return error */
	}
	else{

		uint16 Local_u16TimeTotal = (uint32)1000000 / Copy_u16Freq;

		if(Local_u16TimeTotal >= 1){

			ICR1 = Local_u16TimeTotal - 1;
		}
		else{ ICR1 = 0; }
	}
}

/******************************************************************************
* Description 	: TIMER1 PWM Duty Cycle Function.		                      *
******************************************************************************/

void PWM1_voidDutyCycle(uint16 Copy_u16Duty){

	if(Copy_u16Duty <= 100){

		uint16 Local_u16TimeON = ((uint32)Copy_u16Duty * (ICR1 + 1)) / 100;

		if(Local_u16TimeON > 1){

			OCR1A = Local_u16TimeON - 1;
		}
		else{ OCR1A = 0; }
	}
	
	else{ /* return error */}
	
}

/******************************************************************************
* Description 	: TIMER1 Input Capture Edge Function.		                  *
******************************************************************************/

void TIMER1_voidInputCaptureEdge(ICU_Edge_t Edge){

	switch(Edge){

		case ICU_RISING_EDGE:
			/* Input capture rising edge */
			SET_BIT(TCCR1B, ICES1);
		break;

		case ICU_FALLING_EDGE:
			/* Input capture falling edge */
			CLR_BIT(TCCR1B, ICES1);
		break;
		default:  break;
	}
}

/******************************************************************************
* Description 	: TIMER1 PWM1 Read Function.		                          *
******************************************************************************/

void PWM1_voidRead(uint32 *ReturnFreq, uint8 *ReturnDuty){

	uint16 Local_u16TimeON, Local_u16TimeOFF;

	TCNT1 = 0;

	TIMER1_voidICU_SetCallBack(Timer1ICU_InterruptAction);
	TIMER1_voidInputCaptureEdge(ICU_RISING_EDGE);
	TIMER1_voidICU_InterruptEnable();

	Global_u16Flag = 0;

	while(Global_u16Flag < 3);

	Local_u16TimeON = Global_u16Time2 - Global_u16Time1;

	Local_u16TimeOFF = Global_u16Time3 - Global_u16Time2;

	*ReturnDuty = ((uint32) Local_u16TimeON * 100)/((uint32)Local_u16TimeON + Local_u16TimeOFF);

	*ReturnFreq = ((uint32)1000000) / ((uint32)Local_u16TimeON + Local_u16TimeOFF);

}

/******************************************************************************
* Description 	: TIMER1 ICU Interrupt Action Private Function.				  *
******************************************************************************/

static void Timer1ICU_InterruptAction(void){

	if(Global_u16Flag == 0){

		Global_u16Time1 = ICR1;
		TIMER1_voidInputCaptureEdge(ICU_FALLING_EDGE);
		Global_u16Flag = 1;

	}
	else if(Global_u16Flag == 1){

		Global_u16Time2 = ICR1;
		TIMER1_voidInputCaptureEdge(ICU_RISING_EDGE);
		Global_u16Flag = 2;

	}
	else if(Global_u16Flag == 2){

		Global_u16Time3 = ICR1;
		TIMER1_voidICU_InterruptDisable();
		Global_u16Flag = 3;

	}
	
}

/******************************************************************************
* Description 	: TIMER1 Set Interrupt Time (ms) Function.		              *
******************************************************************************/

void TIMER1_voidSetTime_ms(uint16 Copy_u16Time, void(*Local_Fptr)(void)){

	TIMER1_voidInit(TIMER1_CTC_OCR1A_MODE, TIMER1_SCALER_8);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_DISCONNECTED_MODE, TIMER1_OCR1A);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_DISCONNECTED_MODE, TIMER1_OCR1B);

	OCR1A = ((Copy_u16Time * 1000) - 1);

	TIMER1_voidOCA_SetCallBack(Local_Fptr);

	TIMER1_voidOCA_InterruptEnable();

}

/******************************************************************************
* Description 	: TIMER1 Set Interrupt Time (us) Function.		              *
******************************************************************************/

void TIMER1_voidSetTime_us(uint16 Copy_u16Time, void(*Local_Fptr)(void)){

	TIMER1_voidInit(TIMER1_CTC_OCR1A_MODE, TIMER1_SCALER_8);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_DISCONNECTED_MODE, TIMER1_OCR1A);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_DISCONNECTED_MODE, TIMER1_OCR1B);

	OCR1A = (Copy_u16Time - 1);

	TIMER1_voidOCA_SetCallBack(Local_Fptr);

	TIMER1_voidOCA_InterruptEnable();

}

/******************************************************************************
* Description 	: TIMER1 Input Capture Unit Interrupt Enable Function.		  *
******************************************************************************/

void TIMER1_voidICU_InterruptEnable(void){

	/* Enable Input Capture Unit mode interrupt */
	SET_BIT(TIMSK, TICIE1);
}

/******************************************************************************
* Description 	: TIMER1 Input Capture Unit Interrupt Disable Function.		  *
******************************************************************************/

void TIMER1_voidICU_InterruptDisable(void){

	/* Disable Input Capture Unit mode interrupt */
	CLR_BIT(TIMSK, TICIE1);
}

/******************************************************************************
* Description 	: TIMER1 Overflow Interrupt Enable Function.		          *
******************************************************************************/

void TIMER1_voidOVF_InterruptEnable(void){

	/* Enable overflow mode interrupt */
	SET_BIT(TIMSK, TOIE1);
}

/******************************************************************************
* Description 	: TIMER1 Overflow Interrupt Disable Function.		          *
******************************************************************************/

void TIMER1_voidOVF_InterruptDisable(void){

	/* Disable overflow mode interrupt */
	CLR_BIT(TIMSK, TOIE1);
}

/******************************************************************************
* Description 	: TIMER1 Output Compare A Interrupt Enable Function.		  *
******************************************************************************/

void TIMER1_voidOCA_InterruptEnable(void){

	/* Enable Output Compare A mode interrupt */
	SET_BIT(TIMSK, OCIE1A);
}

/******************************************************************************
* Description 	: TIMER1 Output Compare A Interrupt Disable Function.		  *
******************************************************************************/

void TIMER1_voidOCA_InterruptDisable(void){

	/* Disable overflow mode interrupt */
	CLR_BIT(TIMSK, OCIE1A);
}

/******************************************************************************
* Description 	: TIMER1 Output Compare B Interrupt Enable Function.		  *
******************************************************************************/

void TIMER1_voidOCB_InterruptEnable(void){

	/* Enable Output Compare B mode interrupt */
	SET_BIT(TIMSK, OCIE1B);
}

/******************************************************************************
* Description 	: TIMER1 Output Compare B Interrupt Disable Function.		  *
******************************************************************************/

void TIMER1_voidOCB_InterruptDisable(void){

	/* Disable Output Compare B mode interrupt */
	CLR_BIT(TIMSK, OCIE1B);
}

/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function TIMER1 OCB) -                   *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void TIMER1_voidOCB_SetCallBack(void(*Local_Fptr)(void)){

	/* Output Compare B CallBack function TIMER1 */
	TIMER1_OCB_CallBack = Local_Fptr;

}

/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function TIMER1 OCA) -                   *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void TIMER1_voidOCA_SetCallBack(void(*Local_Fptr)(void)){

	/* Output Compare A CallBack function TIMER1 */
	TIMER1_OCA_CallBack = Local_Fptr;

}

/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function TIMER1 ICU) -                   *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void TIMER1_voidICU_SetCallBack(void(*Local_Fptr)(void)){

	/* Input Capture Unit CallBack function TIMER1 */
	TIMER1_ICU_CallBack = Local_Fptr;

}

/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function TIMER1 OVF) -                   *
*		          [ Layer Architecture Problem Solved ].                      *
******************************************************************************/

void TIMER1_voidOVF_SetCallBack(void(*Local_Fptr)(void)){

	/* Overflow CallBack function TIMER1 */
	TIMER1_OVF_CallBack = Local_Fptr;

}

/******************************************************************************
* !comment  :  ISR Function Overflow interrupt.  						      *
******************************************************************************/

ISR(TIMER1_OVF_VECT){

	if(NULL != TIMER1_OVF_CallBack){

		TIMER1_OVF_CallBack();
	}
	else{ /* return error */ }

}

/******************************************************************************
* !comment  :  ISR Function Output Compare A interrupt.  					  *
******************************************************************************/

ISR(TIMER1_OCA_VECT){

	if(NULL != TIMER1_OCA_CallBack){

		TIMER1_OCA_CallBack();
	}
	else{ /* return error */ }

}

/******************************************************************************
* !comment  :  ISR Function Output Compare B interrupt.  					  *
******************************************************************************/

ISR(TIMER1_OCB_VECT){

	if(NULL != TIMER1_OCB_CallBack){

		TIMER1_OCB_CallBack();
	}
	else{ /* return error */ }

}

/******************************************************************************
* !comment  :  ISR Function Input Capture Unit interrupt.  					  *
******************************************************************************/

ISR(TIMER1_ICU_VECT){

	if(NULL != TIMER1_ICU_CallBack){

		TIMER1_ICU_CallBack();
	}
	else{ /* return error */ }

}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/