/*****************************************************************************/
/* Title        	: 	DF_PLAYER(MP3) Driver								 */
/* File Name    	: 	MP3_program.c   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	05/05/2021                                           */
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
********************************* Delay DIRECTIVES ****************************
******************************************************************************/
#include <util/delay.h>

/******************************************************************************
********************************* UART DIRECTIVES *****************************
******************************************************************************/
#include "UART_interface.h"

/******************************************************************************
****************************** Component DIRECTIVES ***************************
******************************************************************************/
#include "MP3_interface.h"
#include "MP3_private.h"
#include "MP3_config.h"


/******************************************************************************
******************************** Global Variables ***************************** 
******************************************************************************/

uint8 MP3_DefaultCommand[MP3_CMD_SIZE] =
{
	MP3_START_BYTE,
	MP3_VERSION,
	MP3_LENGTH,
	MP3_COMMAND,
	MP3_NO_FEEDBACK,
	MP3_PARAMTER_MSB,
	MP3_PARAMTER_LSB,
	MP3_CHECK_SUM_MSB,
	MP3_CHECK_SUM_LSB,
	MP3_END_BYTE

};


/******************************************************************************
***************************** Function Implementation *************************
******************************************************************************/

void MP3_voidInit(void){

	/* Configure USART During RunTime */
	UART0.BaudRate = 9600;
	UART0.EnableMode = USART_TX_Only;
	UART0.CommunicationMode = USART_Async_DoubleSpeed;
	UART0.CommunicationTerminal = USART_SingleProcessor;
	UART0.ControlFrame = USART_ParityDisable_1BitStop;
	UART0.DataFrame = USART_8BitData;
	UART0.InterruptSource = USART_InterruptDisable;

	/* Init USART */
	USART_voidInit();
	
	/* MP3 Player Online */
	MP3_DefaultCommand[MP3_IDX_COMMAND] = MP3_CMD_RESET;
	MP3_voidSendCommandFrame();
	/* Return to Default Value */
	MP3_DefaultCommand[MP3_IDX_COMMAND] = 0;
	
	/* Delay 1 Sec to Make Sure MP3 Module is Online */
	_delay_ms(1000);
	
}


void MP3_voidPlayTrack(uint16 Copy_u16TrackNumber){
	
	if(Copy_u16TrackNumber > 3000){ Copy_u16TrackNumber = 3000; }
	
	MP3_DefaultCommand[MP3_IDX_COMMAND	   ] = MP3_CMD_PLAY_TRACK;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = Copy_u16TrackNumber >> 8;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = (uint8)Copy_u16TrackNumber;
	
	MP3_voidSendCommandFrame();
	
	MP3_DefaultCommand[MP3_IDX_COMMAND     ] = 0;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0;
	
}



void MP3_voidSelectVolume(uint16 Copy_u16VolumeLevel){

	if(Copy_u16VolumeLevel > 30){ Copy_u16VolumeLevel = 30; }	
	
	MP3_DefaultCommand[MP3_IDX_COMMAND     ] = MP3_CMD_SET_VOLUME;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = Copy_u16VolumeLevel >> 8;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = (uint8)Copy_u16VolumeLevel;
	
	MP3_voidSendCommandFrame();
	
	MP3_DefaultCommand[MP3_IDX_COMMAND     ] = 0;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0;

}



static void MP3_voidSendCommandFrame(void){

	uint8 Iteration = 0;
	uint16 Local_u16CheckSum  = 0;
	uint16 Local_u16AddFrame = 0;
	
	for(Iteration=0; Iteration<10; Iteration++){
			
		if((Iteration > 0)&&(Iteration<7)){
		
			Local_u16AddFrame += MP3_DefaultCommand[Iteration];
		}
		else if(Iteration == 7){
			
			/* Checksum Equation */
			Local_u16CheckSum = 0xFFFF - Local_u16AddFrame + 1;
			
			MP3_DefaultCommand[MP3_IDX_CHECK_SUM_MSB] = Local_u16CheckSum >> 8;
			/* MP3_DefaultCommand[8] = Local_u16CheckSum & 0xFF; */
			MP3_DefaultCommand[MP3_IDX_CHECK_SUM_LSB] = (uint8)Local_u16CheckSum;
			
		}
		
		USART_voidSensByteBlocking(MP3_DefaultCommand[Iteration]);
	}
	
}



void MP3_voidPlayNextTrack(void){
		
	MP3_DefaultCommand[MP3_IDX_COMMAND	   ] = MP3_CMD_PLAY_NEXT;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0x00;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0x00;
	
	MP3_voidSendCommandFrame();
	MP3_DefaultCommand[MP3_IDX_COMMAND] = 0;
		
}


void MP3_voidPlayPreviousTrack(void){
		
	MP3_DefaultCommand[MP3_IDX_COMMAND	   ] = MP3_CMD_PLAY_PREVIOUS;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0x00;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0x00;
	
	MP3_voidSendCommandFrame();
	MP3_DefaultCommand[MP3_IDX_COMMAND] = 0;
		
}


void MP3_voidIncreaseVolume(void){

	MP3_DefaultCommand[MP3_IDX_COMMAND	   ] = MP3_CMD_INC_VOLUME;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0x00;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0x00;
	
	MP3_voidSendCommandFrame();
	MP3_DefaultCommand[MP3_IDX_COMMAND] = 0;

}


void MP3_voidDecreaseVolume(void){

	MP3_DefaultCommand[MP3_IDX_COMMAND	   ] = MP3_CMD_DEC_VOLUME;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0x00;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0x00;
	
	MP3_voidSendCommandFrame();
	MP3_DefaultCommand[MP3_IDX_COMMAND] = 0;

}


void MP3_voidReset(void){

	MP3_DefaultCommand[MP3_IDX_COMMAND	   ] = MP3_CMD_RESET;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0x00;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0x00;
	
	MP3_voidSendCommandFrame();
	MP3_DefaultCommand[MP3_IDX_COMMAND] = 0;

}


void MP3_voidPause(void){

	MP3_DefaultCommand[MP3_IDX_COMMAND	   ] = MP3_CMD_PAUSE;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0x00;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0x00;
	
	MP3_voidSendCommandFrame();
	MP3_DefaultCommand[MP3_IDX_COMMAND] = 0;

}


void MP3_voidPlay(void){

	MP3_DefaultCommand[MP3_IDX_COMMAND	   ] = MP3_CMD_PLAY;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0x00;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0x00;
	
	MP3_voidSendCommandFrame();
	MP3_DefaultCommand[MP3_IDX_COMMAND] = 0;
	
}


void MP3_voidStop(void){

	MP3_DefaultCommand[MP3_IDX_COMMAND	   ] = MP3_CMD_STOP;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0x00;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0x00;
	
	MP3_voidSendCommandFrame();
	MP3_DefaultCommand[MP3_IDX_COMMAND] = 0;

}


void MP3_voidPlayRandomTrack(void){

	MP3_DefaultCommand[MP3_IDX_COMMAND	   ] = MP3_CMD_PLAY_RANDOM;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0x00;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0x00;
	
	MP3_voidSendCommandFrame();
	MP3_DefaultCommand[MP3_IDX_COMMAND] = 0;

}


void MP3_voidPlayTrackInFolder(uint8 Copy_u8FolderName, uint16 Copy_u16TrackNumber){

	if(Copy_u8FolderName > 99){ Copy_u8FolderName = 99; }
	if(Copy_u16TrackNumber > 3000){ Copy_u16TrackNumber = 3000; }

	MP3_DefaultCommand[MP3_IDX_COMMAND     ] = MP3_CMD_PLAY_TRACK_FOLDER;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = Copy_u8FolderName;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = Copy_u16TrackNumber;
	
	MP3_voidSendCommandFrame();
	
	MP3_DefaultCommand[MP3_IDX_COMMAND     ] = 0;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0;

}



void MP3_voidPlayTrackIn3kFolder(uint8 Copy_u8FolderName, uint16 Copy_u16TrackNumber){

	if(Copy_u8FolderName > 99){ Copy_u8FolderName = 99; }
	if(Copy_u16TrackNumber > 3000){ Copy_u16TrackNumber = 3000; }

	MP3_DefaultCommand[MP3_IDX_COMMAND     ] = MP3_CMD_PLAY_3K_FOLDER;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = ((Copy_u8FolderName << 4)|((Copy_u16TrackNumber & 0xF00) >> 8));
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = (Copy_u16TrackNumber & 0xFF);
	
	MP3_voidSendCommandFrame();
	
	MP3_DefaultCommand[MP3_IDX_COMMAND     ] = 0;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_MSB] = 0;
	MP3_DefaultCommand[MP3_IDX_PARAMTER_LSB] = 0;

}


/******************************************************************************
********************************* END OF PROGRAM ******************************
******************************************************************************/
