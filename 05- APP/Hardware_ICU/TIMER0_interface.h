/*****************************************************************************/
/* Title        	: 	TIMER0 Driver					         			 */
/* File Name    	: 	TIMER0_interface.h   		                         */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	13/11/2020                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include mor 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H


/******************************************************************************
*********************************** Typedef ***********************************
******************************************************************************/

/******************************************************************************
* !comment  :  TIMER0 Mode Options.  							 			  *   
******************************************************************************/

typedef enum{

	TIMER0_NORMAL_MODE = 0,
	TIMER0_PHASE_CORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FAST_PWM_MODE,

}Timer0Mode_t;


/******************************************************************************
* !comment  :  TIMER0 Prescaler Value.  							 		  *   
******************************************************************************/

typedef enum{

	TIMER0_STOP = 0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	TIMER0_EXTERNAL_FALLING,
	TIMER0_EXTERNAL_RISING,

}Timer0Scaler_t;


/******************************************************************************
* !comment  :  TIMER0 Output Compare Mode.  							      *   
******************************************************************************/

typedef enum{

	TIMER0_OC0_DISCONNECTED_MODE = 0,
	TIMER0_OC0_TOGGLE_MODE,
	TIMER0_OC0_NON_INVERTING_MODE,
	TIMER0_OC0_INVERTING_MODE,

}Timer0_OutputCompareMode_t;


/******************************************************************************
***************************** Function Prototypes *****************************
******************************************************************************/


/******************************************************************************
* Description 	: TIMER0 Initialization Function to select timer mode         *
*			      & Prescaler vale.                                           *
*                                                                             *
* Parameters  	: Mode( TIMER0_NORMAL_MODE, TIMER0_PHASE_CORRECT_MODE         *
* 				        TIMER0_CTC_MODE, TIMER0_FAST_PWM_MODE ).              *
* 				  Scaler( TIMER0_STOP, TIMER0_SCALER_1, TIMER0_SCALER_8,      *
* 				          TIMER0_SCALER_64, TIMER0_SCALER_256,                *
* 				          TIMER0_SCALER_1024, TIMER0_EXTERNAL_FALLING,        *
* 				          TIMER0_EXTERNAL_RISING).			   		          *
* Return type 	: void                       								  *
*******************************************************************************
* Pre_condition : none.      												  *
******************************************************************************/

void TIMER0_voidInit(Timer0Mode_t Mode, Timer0Scaler_t Prescaler);


/******************************************************************************
* Description 	: TIMER0 Output Compare initialization Function to            *
*                 Select Output Compare Mode.                                 *
* Parameters  	: Output Compare Mode( TIMER0_OC0_DISCONNECTED_MODE, 		  *
* 				  TIMER0_OC0_TOGGLE_MODE, TIMER0_OC0_NON_INVERTING_MODE,      *
* 				  TIMER0_OC0_INVERTING_MODE ).								  *
* Return type 	: void                       								  *
*******************************************************************************
* Pre_condition : This function must be used after timer initialization.      *
******************************************************************************/

void TIMER0_voidOutputCompareInit(Timer0_OutputCompareMode_t OC0Mode);


/******************************************************************************
* Description 	: TIMER0 Update Duty Cycle Value Function                     *
* 			      and put it in the OCR0 register.                            *
* Parameters  	: Duty Cycle ( 1 ---> 100 ). 					              *								      *
* Return type 	: void                       								  *
*******************************************************************************
* Pre_condition : This function must be used after timer initialization       *
* 				  and output compare initialization.				 		  *
******************************************************************************/

void TIMER0_voidUpdateDutyCycle(uint8 Copy_u8DutyCycle);


/******************************************************************************
* Description 	: TIMER0 Get Timer Counter Value Function.				      *
* Parameters  	: none.                                                       *
* Return type 	: uint8.                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after timer initialization.      *
******************************************************************************/

uint8 TIMER0_u8GetTimerCounterValue(void);


/******************************************************************************
* Description 	: TIMER0 Set Output Compare Register Value.				                  *
* Parameters  	: Compare Value ( 0 ---> 255 ).                               *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after timer initialization       *
* 				  and output compare initialization.		                  *
******************************************************************************/

void TIMER0_voidSetOutputCompareValue(uint8 Copy_u8CompareValue);


/******************************************************************************
* Description 	: TIMER0 Set Timer Counter Value Function.				      *
* Parameters  	: Duty Cycle Value( 0 ---> 255 ).                             *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after timer initialization.      *
******************************************************************************/

void TIMER0_voidSetTimerCounterValue(uint8 Copy_u8TimerValue);


/******************************************************************************
* Description 	: TIMER0 Overflow Interrupt Enable Function.		          *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after Enable global interrupt.   *
******************************************************************************/

void TIMER0_voidOverflowInterruptEnable(void);


/******************************************************************************
* Description 	: TIMER0 Overflow Interrupt Disable Function.				  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after Enable global interrupt.   *
******************************************************************************/

void TIMER0_voidOverflowInterrupttDisable(void);


/******************************************************************************
* Description 	: TIMER0 Output Compare Interrupt Enable Function.			  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after Enable global interrupt.   *
******************************************************************************/

void TIMER0_voidCompareMatchnterruptEnable(void);


/******************************************************************************
* Description 	: TIMER0 Output Compare Interrupt Disable Function.			  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after Enable global interrupt.   *
******************************************************************************/

void TIMER0_voidCompareMatchInterruptDisable(void);


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function TIMER0 OVF) -                   *
*		          [ Layer Architecture Problem Solved ].                      *
* Parameters  	: Pointer to function that points to the first line           *
*				  of the function (ISR).                                      *
* Return type 	: void.                                                    	  *
*******************************************************************************
* Pre_condition : This function must be used after timer1 overflow interrupt  *
*				  enable .                                         			  *
******************************************************************************/

void TIMER0_voidOverflowSetCallBack(void(*Local_Fptr)(void));


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function TIMER0 OC0) -                   *
*		          [ Layer Architecture Problem Solved ].                      *
* Parameters  	: Pointer to function that points to the first line           *
*				  of the function (ISR).                                      *
* Return type 	: void.                                                    	  *
*******************************************************************************
* Pre_condition : This function must be used after timer1 overflow interrupt  *
*				  enable .                                         			  *
******************************************************************************/

void TIMER0_voidCompareMatchSetCallBack(void(*Local_Fptr)(void));



#endif 
/*** !comment : End of gaurd [TIMER0_INTERFACE_H] ****************************/
