/*****************************************************************************/
/* Title        	: 	DF_PLAYER(MP3) Driver								 */
/* File Name    	: 	MP3_private.h      	                 	             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	05/05/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef MP3_PRIVATE_H
#define MP3_PRIVATE_H


/******************************************************************************
* !comment : List of MP3 Frame.							                      *
******************************************************************************/

#define MP3_CMD_SIZE	             10
#define MP3_START_BYTE	             0x7E
#define MP3_VERSION  	             0xFF
#define MP3_NO_FEEDBACK	        	 0x00
#define MP3_RQT_FEEDBACK	    	 0x01
#define MP3_END_BYTE	        	 0xEF
#define MP3_LENGTH  	             0x00
#define MP3_COMMAND  	             0x00
#define MP3_PARAMTER_MSB  	         0x00
#define MP3_PARAMTER_LSB   	         0x00
#define MP3_CHECK_SUM_MSB   	     0x00
#define MP3_CHECK_SUM_LSB  	         0x00


/******************************************************************************
* !comment : List of MP3 Frame Index.							              *
******************************************************************************/

#define MP3_IDX_START_BYTE	      0
#define MP3_IDX_VERSION  	      1
#define MP3_IDX_LENGTH  	      2
#define MP3_IDX_COMMAND  	      3
#define MP3_IDX_FEEDBACK	      4
#define MP3_IDX_PARAMTER_MSB  	  5
#define MP3_IDX_PARAMTER_LSB   	  6
#define MP3_IDX_CHECK_SUM_MSB     7
#define MP3_IDX_CHECK_SUM_LSB  	  8
#define MP3_IDX_END_BYTE	      9


/******************************************************************************
* !comment : List of MP3 Control Commands.							          *
******************************************************************************/

#define MP3_CMD_PLAY_NEXT 	         0x01
#define MP3_CMD_PLAY_PREVIOUS  	     0x02
#define MP3_CMD_PLAY_TRACK 	         0x03
#define MP3_CMD_INC_VOLUME 	         0x04
#define MP3_CMD_DEC_VOLUME  	     0x05
#define MP3_CMD_SET_VOLUME  	     0x06
#define MP3_CMD_SET_EQ  	         0x07
#define MP3_CMD_REPEAT_TRACK 	     0x08
#define MP3_CMD_SET_STORAGE  	     0x09
#define MP3_CMD_SET_SLEEP 	         0x0A
#define MP3_CMD_RESET 	             0x0C
#define MP3_CMD_PLAY 	             0x0D
#define MP3_CMD_PAUSE 	             0x0E
#define MP3_CMD_PLAY_TRACK_FOLDER  	 0x0F
#define MP3_CMD_REPEAT_ALL	         0x11
#define MP3_CMD_PLAY_MP3_FOLDER 	 0x12
#define MP3_CMD_INSERT_ADVERT	     0x13
#define MP3_CMD_PLAY_3K_FOLDER 	     0x14
#define MP3_CMD_STOP_ADVERT	         0x15
#define MP3_CMD_STOP	             0x16
#define MP3_CMD_REPEAT_FOLDER	     0x17
#define MP3_CMD_PLAY_RANDOM 	     0x18
#define MP3_CMD_REPEAT_CUR_TRACK	 0x19
#define MP3_CMD_SET_DAC	             0x1A


/******************************************************************************
* !comment : List of MP3 ......							                      *
******************************************************************************/

#define MP3_NO_VOLUME 	         0
#define MP3_NO_TRACK         	 0
#define MP3_MAX_VOLUME 	         30
#define MP3_MAX_TRACK_NUMBER 	 3000



/******************************************************************************
*************************** Private Functions Prototypes **********************
******************************************************************************/

static void MP3_voidSendCommandFrame(void);


#endif 
/*** !comment : End of gaurd [MP3_PRIVATE_H] *********************************/
