#ifndef _HEADER_H_
#define _HEADER_H_

#include<reg51.h>
//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

extern uchar DisplayData[8];	 //动态数码管显示值
extern uchar DisplayData1[8];	 //温度采集值的段码
extern uchar DisplayData2[8];	 //温度阈值段码
extern uchar DisplayData3[8];	 //速度设定值段码
extern uchar code smgduan[17];	 //显示0~F的值
extern float Temp;               //温度
extern uint thresholdvalue;	     //温度阈值
extern uchar speedvalue;		 //速度设定值
extern uint DisplayChoice;		 //1：温度采集值  2：温度阈值 3：速度设定值 
extern uint KeyValue;	         //一个按键值
extern uchar d;

//--定义使用的IO口--//
sbit DSPORT=P3^7;			  //用于采集温度
sbit LSA=P2^2;				  //用于控制位选
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit k1=P2^5;	          //定义P25口是k1
sbit k2=P2^6;	          //定义P26口是k2
sbit k3=P2^7;	          //定义P27口是k3
#define GPIO_KEY P1		  //用于控制矩阵按键
sbit SDA=P2^0;			  //数据线
sbit SCL=P2^1;			  //时钟线

//--声明全局函数--//
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