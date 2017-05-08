#include "16F877A.h"
#use delay(count=4000000)
#use rs232(baud=9600, xmit=PIN_D0, rcv=PIN_D1)

void main()
{
	char testchar = 'A';  //test character
	delay_ms(1000);  //wake LCD, then wait for powerup
	putc(0xFE);  //clear
	putc(1); //cursor

	delay_ms(10);
	while(1)
	{
		putc(testchar);
		putc(0xfe);
		putc(0xC0);	//goto next line
		printf("ASCII %c CHAR %d", testchar, testchar);
		while(1);	//stops the output.
	}
}

