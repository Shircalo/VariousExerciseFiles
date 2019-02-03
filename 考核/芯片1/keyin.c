#include"header.h"	

uint thresholdvalue;	      //温度阈值
uchar speedvalue;		      //速度设定值
uchar DisplayData2[8];	      //温度阈值段码
uchar DisplayData3[8];	      //速度设定值段码
uint KeyValue = 0;			  //一个按键值
uchar d;					  //用于判断按键是否按下，如果按键按下则修改当前显示数值

							  
/*******************************************************************************
* 函 数 名         : KeyDown()
* 函数功能		   : 检测有按键按下并读取键值
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void KeyDown(void)
{
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)     //读取按键是否按下
	{
		delay(1000);       //延时10ms进行消抖
		if(GPIO_KEY!=0x0f) //再次检测键盘是否按下
		{	
			//测试列
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}

	     	GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(GPIO_KEY!=0xf0))	 //检测按键松手检测
			{
				delay(1000);
				a++;
			}
			d=1;	//用于判断按键是否按下，如果按键按下则修改当前显示数值
		}
	}
}
/*******************************************************************************
* 函 数 名         : DisplayValue()
* 函数功能		   : 确定输入的温度阈值或速度设定值
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void DisplayValue()
{
	switch(DisplayChoice)	  //通过DisplayChoice的值选择要显示的值
	{
		case 2:				  
			if(d == 1)		  //判断按键是否按下
			{
				thresholdvalue = KeyValue + thresholdvalue*10;	//通过单个矩阵按键值确定温度阈值				
			}			
			if((thresholdvalue != 0) || (d == 1))				//如果有数值输入，则修改当前显示值
			{
				d = 0;
				DisplayData2[1] = smgduan[thresholdvalue / 10];	   //温度用两位数显示
				DisplayData2[2] = smgduan[thresholdvalue % 10];
			}
			break;
		case 3:
			if(d == 1)
			{
				speedvalue = KeyValue + speedvalue*10;				
			}			
			if((speedvalue != 0) || (d == 1))
			{
				d = 0;	
				DisplayData3[3] = smgduan[speedvalue % 1000 / 100];	 //速度设定值用三位数显示
				DisplayData3[4] = smgduan[speedvalue % 100 / 10];
				DisplayData3[5] = smgduan[speedvalue % 10];
			}
			break;  
	}	
}

	








