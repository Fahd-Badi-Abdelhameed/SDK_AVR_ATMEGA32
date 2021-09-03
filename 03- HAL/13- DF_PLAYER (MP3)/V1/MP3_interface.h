/*****************************************************************************/
/* Title        	: 	DF_PLAYER(MP3) Driver								 */
/* File Name    	: 	MP3_interface.h   		                             */
/* Author       	: 	Fahd Badi                                            */
/* Version      	: 	1.0.0                                                */
/* Origin Date  	: 	05/05/2021                                           */
/* Notes        	: 	None                                                 */
/*****************************************************************************/

/******************************************************************************
* Description 	: Guard to protect this File from include more 			      *
*                 than one time.                               	 	 		  *
******************************************************************************/

#ifndef MP3_INTERFACE_H
#define MP3_INTERFACE_H


/******************************************************************************
****************************** Functions Prototypes ***************************
******************************************************************************/

void MP3_voidInit(void);
void MP3_voidPlay(void);
void MP3_voidStop(void);
void MP3_voidReset(void);
void MP3_voidPause(void);
void MP3_voidPlayNextTrack(void);
void MP3_voidPlayPreviousTrack(void);
void MP3_voidPlayRandomTrack(void);
void MP3_voidIncreaseVolume(void);
void MP3_voidDecreaseVolume(void);
void MP3_voidPlayTrack(uint16 Copy_u16TrackNumber);
void MP3_voidSelectVolume(uint16 Copy_u16VolumeLevel);
void MP3_voidPlayTrackInFolder(uint8 Copy_u8FolderName, uint16 Copy_u16TrackNumber);
void MP3_voidPlayTrackIn3kFolder(uint8 Copy_u8FolderName, uint16 Copy_u16TrackNumber);


#endif 
/*** !comment : End of gaurd [MP3_INTERFACE_H] *******************************/
