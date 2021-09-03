
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "DIO_interface.h"
#include "MP3_interface.h"



void main(void){

	MP3_voidInit();
	
	/* Volume Number From 0 to 30 */
	MP3_voidSelectVolume(30);
	
	MP3_voidPlayTrack(3);
	_delay_ms(5000);
	MP3_voidPlayTrack(2);
	
	while(1){
	
	
	}
	
}