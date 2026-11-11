/*
 * i2c_concertado.c
 *
 * Created: 17/10/2026 17:01:41
 * Author : atoin
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "IncFile1.h"
#define slave 0x3c

int main(void)
{
	
	DDRC|=(1<<PORTC4)|(1<<PORTC5);
	PORTC|=(1<<PORTC4)|(1<<PORTC5);
	init(slave);
	
    for (int i=0; i<128;i++)
    {
		sendram(slave,0x80);
		sendram(slave,0x80);
		sendram(slave,0x80);
		sendram(slave,0x80);
		sendram(slave,0x80);
		sendram(slave,0x80);
		sendram(slave,0x80);
		sendram(slave,0xFF); }
		
		/*sendram(0x3c,0x03);
		sendram(0x3c,0x0e);
		sendram(0x3c,0x34);
		sendram(0x3c,0xC4);
		sendram(0x3c,0xC4);
		sendram(0x3c,0x34);
		sendram(0x3c,0x0e);
		sendram(0x3c,0x03);*/
		
    while (1) 
    {
		sendcomm(slave,0xA7);
		_delay_ms(500);
		sendcomm(slave,0xA6);
		_delay_ms(500);
    }
}

