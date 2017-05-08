#include "16F877A.h"
#use delay(count=4000000)
#use rs232(baud=9600, xmit=PIN_D0, rcv=PIN_D1)

void main()
{
	int1 minbit=0, maxbit=1;
	signed int8 minbyte=-127, maxbyte=127;
	signed int16 minword=-32767, maxword=32767;
	signed int32 minlong=-2147483647, maxlong=2147483647;
	float testnum=12345.6789;

	while(1)
	{
	delay_ms(1000);  /waits for LCD to wake
	putc(0xfe);
	putc(0x1);  //puts cursor at position 1
	delay_ms(10);  //wait for LCD to draw

	printf("Bit: %d to %d", minbit, maxbit);
	delay_ms(1000);
	putc(0xfe);
	putc(0x1);
	delay_ms(10);

	printf("Byte: %d to %d", minbyte, maxbyte);
	delay_ms(1000);
	putc(0xfe);
	putc(0x1);
	delay_ms(10);

	printf("Word: %d to %d", minword, maxword);
	delay_ms(1000);
	putc(0xfe);
	putc(0x1);
	delay_ms(10);

	printf("Long: %d" minlong);  //split due to LCD screen size
	delay_ms(1000);
	putc(0xfe);
	putc(0x1);
	delay_ms(10);
	printf(" to %d", maxlong);
	delay_ms(1000);
	putc(0xfe);
	putc(0x1);
	delay_ms(10);
	} //while loop repeats until powered down
}

