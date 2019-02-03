#include "reg51.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include "header.h"	

char num=0;
uchar code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
			0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//显示0~F的值

/*******************************************************************************
* 函 数 名       : main()
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	while(1)
	{
		datapros(Ds18b20ReadTemp());	  //数据处理函数
		keypros();						  //按键处理函数，选择要显示的数据
		KeyDown();						  //检测有按键按下并读取键值，用于修改当前显示数据
		DisplayValue();
		DigDisplay();                     //数码管显示函数	
		if(Temp > thresholdvalue)		  //判断是否发送数据
		{
			At24c02Write(0x01,speedvalue);	//发送速度设定值	
		}

	}		
}




