/*****************************************************************************/
/* Title        	: 	EXIT Driver									         */
/* File Name    	: 	EXIT_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	3.0.0                                                */
/* Origin Date  	: 	08/08/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef EXIT_INTERFACE_H
#define EXIT_INTERFACE_H

/******************************************************************************
*********************************** Typedef ***********************************
******************************************************************************/

/******************************************************************************
* !comment : EXTI trigger edge options Definition.  			         	  *
******************************************************************************/

typedef enum{
	
	LOW_LEVEL = 0,
	ANY_CHANGE   ,
	FALLING_EDGE ,
	RISING_EDGE  ,
	
}EXIT_TriggerEdge_t;


/******************************************************************************
* !comment : EXTI state options Definition.  			         	          *
******************************************************************************/

typedef enum{
	
	DISABLE = 0,
	ENABLE     ,
	
}EXIT_State_t;

/******************************************************************************
***************************** Function Prototypes *****************************
******************************************************************************/


/******************************************************************************
* Description 	: External Interrupt Request 0 Enable Function.				  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after Enable global interrupt.   *
******************************************************************************/
void EXIT0_voidInit(EXIT_State_t Copy_State);

/******************************************************************************
* Description 	: External Interrupt Request 1 Enable Function.               *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after Enable global interrupt.   *
******************************************************************************/
void EXIT1_voidInit(EXIT_State_t Copy_State);

/******************************************************************************
* Description 	: External Interrupt Request 2 Enable Function.               *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after Enable global interrupt.   *
******************************************************************************/
void EXIT2_voidInit(EXIT_State_t Copy_State);


/******************************************************************************
* Description 	: Control the trigger edge of an EXIT0 Function.			  *
* Parameters  	: Trigger Edge( LOW_LEVEL, ANY_CHANGE, FALLING_EDGE,          *
*     		      RISING_EDGE).   											  *
* Return type 	: void.                                                    	  *
*******************************************************************************
* Pre_condition : This function must be used after External Interrupt         *
*				  Request 0 Enable .                                          *
******************************************************************************/

void EXIT0_voidTriggerEdge(EXIT_TriggerEdge_t Edge);


/******************************************************************************
* Description 	: Control the trigger edge of an EXIT1 Function.  		      *
* Parameters  	: Trigger Edge ( LOW_LEVEL, ANY_CHANGE, FALLING_EDGE,         *
*     		      RISING_EDGE).   											  *
* Return type 	: void.                                                    	  *
*******************************************************************************
* Pre_condition : This function must be used after External Interrupt         *
*				  Request 1 Enable .                                          *
******************************************************************************/

void EXIT1_voidTriggerEdge(EXIT_TriggerEdge_t Edge);


/******************************************************************************
* Description 	: Control the trigger edge of an EXIT2 Function.			  *
* Parameters  	: Trigger Edge ( FALLING_EDGE,  RISING_EDGE).                 *
* Return type 	: void.                                                    	  *
*******************************************************************************
* Pre_condition : This function must be used after External Interrupt         *
*				  Request 2 Enable .                                          *
******************************************************************************/

void EXIT2_voidTriggerEdge(EXIT_TriggerEdge_t Edge);


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function) -                              *
*		          [ Layer Architecture Problem Solved ].                      *
* Parameters  	: Pointer to function that points to the first line           *
*				  of the function (ISR).                                      *
* Return type 	: void.                                                    	  *
*******************************************************************************
* Pre_condition : This function must be used after External Interrupt         *
*				  Request 0 Enable .                                          *
******************************************************************************/

void EXTI0_voidSetCallBack(void(*Local_ptr)(void));


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer(The Callback function) -                              *
*		          [ Layer Architecture Problem Solved ].                      *
* Parameters  	: Pointer to function that points to the first line           *
*				  of the function (ISR).                                      *
* Return type 	: void.                                                    	  *
*******************************************************************************
* Pre_condition : This function must be used after External Interrupt         *
*				  Request 1 Enable .                                          *
******************************************************************************/

void EXTI1_voidSetCallBack(void(*Local_ptr)(void));


/******************************************************************************
* Description 	: This function used to	communicate with the function in App  *
*                 Layer( The Callback function ) -                            *
*		          [ Layer Architecture Problem Solved ].                      *
* Parameters  	: Pointer to function that points to the first line           *
*				  of the function (ISR).                                      *
* Return type 	: void.                                                    	  *
*******************************************************************************
* Pre_condition : This function must be used after External Interrupt         *
*				  Request 2 Enable .                                          *
******************************************************************************/

void EXTI2_voidSetCallBack(void(*Local_ptr)(void));



#endif 
/*** !comment : End of gaurd [EXIT_INTERFACE_H] ******************************/
