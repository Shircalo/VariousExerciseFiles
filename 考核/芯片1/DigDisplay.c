#include"header.h"

uchar DisplayData[8];	 //��̬�������ʾֵ

/*******************************************************************************
* �� �� ��         : DisplayDatapros() 
* ��������		   : ѡ��Ҫ��ʾ�Ķ���
*******************************************************************************/
void DisplayDatapros()
{
	uchar i;
	switch(DisplayChoice)		 //����DisplayChoice��ֵѡ��Ҫ��ʾ��ֵ
	{
		case 1:
			for(i = 0; i < 8; i++)
			{
				DisplayData[i] = DisplayData1[i];	   //���¶Ȳɼ�ֵ�Ķ���ȷ��Ϊ��̬�������ʾֵ
			}
			break;
		case 2:
			for(i = 0; i < 8; i++)
			{
				DisplayData[i] = DisplayData2[i];	   //���¶���ֵ�Ķ���ȷ��Ϊ��̬�������ʾֵ
			}										   
			break;
		case 3:
			for(i = 0; i < 8; i++)
			{
				DisplayData[i] = DisplayData3[i];	   //���ٶ��趨ֵ�Ķ���ȷ��Ϊ��̬�������ʾֵ
			}
			break;
	}
}


/*******************************************************************************
* ������         :DigDisplay()
* ��������		 :�������ʾ����
* ����           : ��
* ���         	 : ��
*******************************************************************************/
void DigDisplay()
{
	uchar i;
	DisplayDatapros();
	for(i=0;i<8;i++)
	{
		switch(i)	 //λѡ��ѡ�����������ܣ�
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;//��ʾ��0λ
			case(1):
				LSA=1;LSB=0;LSC=0; break;//��ʾ��1λ
			case(2):
				LSA=0;LSB=1;LSC=0; break;//��ʾ��2λ
			case(3):
				LSA=1;LSB=1;LSC=0; break;//��ʾ��3λ
			case(4):
				LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
			case(5):
				LSA=1;LSB=0;LSC=1; break;//��ʾ��5λ
			case(6):
				LSA=0;LSB=1;LSC=1; break;//��ʾ��5λ
			case(7):
				LSA=1;LSB=1;LSC=1; break;//��ʾ��5λ	
					
		}
		P0=DisplayData[i];//��������
		delay(20); //���һ��ʱ��ɨ��	
		P0=0x00;//����
	}		
}














