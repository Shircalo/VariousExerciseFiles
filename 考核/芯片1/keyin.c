#include"header.h"	

uint thresholdvalue;	      //�¶���ֵ
uchar speedvalue;		      //�ٶ��趨ֵ
uchar DisplayData2[8];	      //�¶���ֵ����
uchar DisplayData3[8];	      //�ٶ��趨ֵ����
uint KeyValue = 0;			  //һ������ֵ
uchar d;					  //�����жϰ����Ƿ��£���������������޸ĵ�ǰ��ʾ��ֵ

							  
/*******************************************************************************
* �� �� ��         : KeyDown()
* ��������		   : ����а������²���ȡ��ֵ
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void KeyDown(void)
{
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)     //��ȡ�����Ƿ���
	{
		delay(1000);       //��ʱ10ms��������
		if(GPIO_KEY!=0x0f) //�ٴμ������Ƿ���
		{	
			//������
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
			while((a<50)&&(GPIO_KEY!=0xf0))	 //��ⰴ�����ּ��
			{
				delay(1000);
				a++;
			}
			d=1;	//�����жϰ����Ƿ��£���������������޸ĵ�ǰ��ʾ��ֵ
		}
	}
}
/*******************************************************************************
* �� �� ��         : DisplayValue()
* ��������		   : ȷ��������¶���ֵ���ٶ��趨ֵ
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void DisplayValue()
{
	switch(DisplayChoice)	  //ͨ��DisplayChoice��ֵѡ��Ҫ��ʾ��ֵ
	{
		case 2:				  
			if(d == 1)		  //�жϰ����Ƿ���
			{
				thresholdvalue = KeyValue + thresholdvalue*10;	//ͨ���������󰴼�ֵȷ���¶���ֵ				
			}			
			if((thresholdvalue != 0) || (d == 1))				//�������ֵ���룬���޸ĵ�ǰ��ʾֵ
			{
				d = 0;
				DisplayData2[1] = smgduan[thresholdvalue / 10];	   //�¶�����λ����ʾ
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
				DisplayData3[3] = smgduan[speedvalue % 1000 / 100];	 //�ٶ��趨ֵ����λ����ʾ
				DisplayData3[4] = smgduan[speedvalue % 100 / 10];
				DisplayData3[5] = smgduan[speedvalue % 10];
			}
			break;  
	}	
}

	








