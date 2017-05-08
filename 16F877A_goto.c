#include "16F877A.h"
#use delay(clock=4000000) //4MHz clock

void main()
{
	int outbyte;
	again: outbyte = 0;

	while(1)
	{
		output_C(outbyte);
		delay_ms(10);
		outbyte++;

		if(!input(PIN_D0))  continue;	//input 0 = low, skip everything
		if(!input(PIN_D1))  break;	//input 1 = low, terminate loop

		delay_ms(10);
		if(outbyte == 100)  goto again;	//restarts the loop
	}
}