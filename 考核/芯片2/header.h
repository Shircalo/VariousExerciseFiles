#ifndef _HEADER_H_
#define _HEADER_H_

#include <reg51.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

sbit SDA=P3^2;			  //������
sbit SCL=P3^3;			  //ʱ����
sbit MOTOA = P2^0;		  //�����
sbit MOTOB = P2^1;
sbit MOTOC = P2^2;
sbit MOTOD = P2^3; 

extern uchar speedvalue;  //�ٶ��趨ֵ
extern uint SPEED;		  //��ǰ�ٶ�
//--����ȫ�ֺ���--//
void Delay10us();
uchar I2cStartDistinguish();
uchar I2cStopDistinguish();
uchar ReceiveByte();
void Receive();
void delay(uint);

#endif