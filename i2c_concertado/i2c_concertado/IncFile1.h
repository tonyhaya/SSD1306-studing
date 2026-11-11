/*
 * IncFile1.h
 *
 * Created: 17/10/2026 17:03:44
 *  Author: atoin
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_


/************************************************************************/
/* START
DATA/SLA + W
STOP                                                                     */
/************************************************************************/
#define START 0x08
#define MT_SLA_ACK 0x18
#define MT_DATA_ACK 0x28


void start();
void dado(int dado1);
void sla(int dado);
void stop();
void ERROR(int slar,int dador,int tipo);
void sendcomm(int end,int inf);
void sendram(int end,int inf);
void init(int slv);
#endif /* INCFILE1_H_ */