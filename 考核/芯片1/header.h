#ifndef _HEADER_H_
#define _HEADER_H_

#include<reg51.h>
//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

extern uchar DisplayData[8];	 //��̬�������ʾֵ
extern uchar DisplayData1[8];	 //�¶Ȳɼ�ֵ�Ķ���
extern uchar DisplayData2[8];	 //�¶���ֵ����
extern uchar DisplayData3[8];	 //�ٶ��趨ֵ����
extern uchar code smgduan[17];	 //��ʾ0~F��ֵ
extern float Temp;               //�¶�
extern uint thresholdvalue;	     //�¶���ֵ
extern uchar speedvalue;		 //�ٶ��趨ֵ
extern uint DisplayChoice;		 //1���¶Ȳɼ�ֵ  2���¶���ֵ 3���ٶ��趨ֵ 
extern uint KeyValue;	         //һ������ֵ
extern uchar d;

//--����ʹ�õ�IO��--//
sbit DSPORT=P3^7;			  //���ڲɼ��¶�
sbit LSA=P2^2;				  //���ڿ���λѡ
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit k1=P2^5;	          //����P25����k1
sbit k2=P2^6;	          //����P26����k2
sbit k3=P2^7;	          //����P27����k3
#define GPIO_KEY P1		  //���ڿ��ƾ��󰴼�
sbit SDA=P2^0;			  //������
sbit SCL=P2^1;			  //ʱ����

//--����ȫ�ֺ���--//
void Delay1ms(uint );
uchar Ds18b20Init();
void Ds18b20WriteByte(uchar com);
uchar Ds18b20ReadByte();
void  Ds18b20ChangTemp();
void  Ds18b20ReadTempCom();
int Ds18b20ReadTemp();

void datapros(int temp);
void DigDisplay();
void delay(uint i);

void DisplayValue();
void DisplayDatapros();

void keypros();
void KeyDown(void);

void Delay10us();
void I2cStart();
void I2cStop();
unsigned char I2cSendByte(unsigned char dat);
void At24c02Write(unsigned char addr,unsigned char dat);


#endif