#include "reg51.h"
#include "header.h"

uint SPEED;		  //当前速度

/*******************************************************************************
* 函 数 名         : delay
* 函数功能		   : 延时函数，i=1时，大约延时10us
*******************************************************************************/
void delay(uint i)
{
	while(i--);	
}
/*******************************************************************************
* 函 数 名         : main()
* 函数功能		   : 主函数
*******************************************************************************/
void main()
{
	while(1)
	{							
		SPEED = 15000 / speedvalue;	 //得到延时数值
		Receive();					 //通过IIC得到速度设定值
		if(speedvalue != 0x00)		 //判断是否启动电机
		{
			MOTOA = 1;
			MOTOB = 0;
			MOTOC = 1;
			MOTOD = 1;
			delay(SPEED);
			
			MOTOA = 1;
			MOTOB = 1;
			MOTOC = 1;
			MOTOD = 0;
			delay(SPEED);
			
			MOTOA = 0;
			MOTOB = 1;
			MOTOC = 1;
			MOTOD = 1;
			delay(SPEED);
			
			MOTOA = 1;
			MOTOB = 1;
			MOTOC = 0;
			MOTOD = 1;
		}				  		
	}		
}









