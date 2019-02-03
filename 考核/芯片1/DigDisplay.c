#include"header.h"

uchar DisplayData[8];	 //动态数码管显示值

/*******************************************************************************
* 函 数 名         : DisplayDatapros() 
* 函数功能		   : 选择要显示的段码
*******************************************************************************/
void DisplayDatapros()
{
	uchar i;
	switch(DisplayChoice)		 //根据DisplayChoice的值选择要显示的值
	{
		case 1:
			for(i = 0; i < 8; i++)
			{
				DisplayData[i] = DisplayData1[i];	   //将温度采集值的段码确定为动态数码管显示值
			}
			break;
		case 2:
			for(i = 0; i < 8; i++)
			{
				DisplayData[i] = DisplayData2[i];	   //将温度阈值的段码确定为动态数码管显示值
			}										   
			break;
		case 3:
			for(i = 0; i < 8; i++)
			{
				DisplayData[i] = DisplayData3[i];	   //将速度设定值的段码确定为动态数码管显示值
			}
			break;
	}
}


/*******************************************************************************
* 函数名         :DigDisplay()
* 函数功能		 :数码管显示函数
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void DigDisplay()
{
	uchar i;
	DisplayDatapros();
	for(i=0;i<8;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(1):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(2):
				LSA=0;LSB=1;LSC=0; break;//显示第2位
			case(3):
				LSA=1;LSB=1;LSC=0; break;//显示第3位
			case(4):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(5):
				LSA=1;LSB=0;LSC=1; break;//显示第5位
			case(6):
				LSA=0;LSB=1;LSC=1; break;//显示第5位
			case(7):
				LSA=1;LSB=1;LSC=1; break;//显示第5位	
					
		}
		P0=DisplayData[i];//发送数据
		delay(20); //间隔一段时间扫描	
		P0=0x00;//消隐
	}		
}














