/*
 * CFile1.c
 *
 * Created: 17/10/2026 17:03:54
 *  Author: atoin
 */ 
#include "IncFile1.h"
#include <avr/io.h>
int slave= 0;

void start(){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != START)
		ERROR(0,0,0);}


void sla(int dado){
	dado=dado<<1;
	TWDR = dado;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if((TWSR & 0xF8) != MT_SLA_ACK)
	ERROR(dado,0,1);
	slave=dado;
}

void dado(int dado1){
	TWDR = dado1;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8)!= MT_DATA_ACK)
	ERROR(slave,dado1,2);
}

void stop(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void sendcomm(int end,int inf){
	start();
	sla(end);
	dado(0x00);
	dado(inf);
	stop();
}

void sendram(int end,int inf){
	start();
	sla(end);
	dado(0x40);
	dado(inf);
	stop();
}

void ERROR(int slar,int dador,int tipo){
		TWCR&=(0<<TWSTO);
		TWCR|=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
		
		//SLW WR erro
		switch (tipo){
		case 1:
		 sla(slar);
		break;
		//DATA erro
		case 2:
		 sla(slar);
		  dado(dador);
		break;}

}
void init(int slv){
	sendcomm(slv,0xA8);
	sendcomm(slv,0x3F);
	sendcomm(slv,0xd3);
	sendcomm(slv,0x00);
	sendcomm(slv,0x40);
	sendcomm(slv,0xA0);
	sendcomm(slv,0xC0);
	sendcomm(slv,0xDA);
	sendcomm(slv,0x02);
	sendcomm(slv,0x81);
	sendcomm(slv,0x7f);
	sendcomm(slv,0xA4);
	sendcomm(slv,0xA6); //<----- inverte tela
	sendcomm(slv,0xD5);
	sendcomm(slv,0x80);
	sendcomm(slv,0x8D);
	sendcomm(slv,0x14);
	sendcomm(slv,0xAF);
}