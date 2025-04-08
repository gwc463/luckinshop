#include "mode.h"
#include "OLED_Data.h"
#include "OLED.h"
#include "led.h"
#include "delay.h"
u16 count=0;

//1�Ž�--->��ǰ
//2�Ž�--->�Һ�
//3�Ž�--->��ǰ
//4�Ž�--->���

u8 bug = 0;//���ǰ�����˸տ�ʼ�Ĳ�̬��Ӧ

/**
  * ��    ����������ʱ����
  * ��    ����x�ǳ�ʼֵ��y��Ҫ�����ֵ��num��ͨ����
  * �� �� ֵ����
  */
void For(int x,int y,int num)
{
	int i,sign;
	if(x>y)sign=1;
	if(y>x)sign=0;
	if(num==1)//ͨ��1
	{
		if(sign==1)
		{
			for(i=x;i>=y;i--)
			{
				TIM_SetCompare1(TIM4,i);
				delay_us(100);
			}
		}
		else if(sign==0)
		{
			for(i=x;i<=y;i++)
			{
				TIM_SetCompare1(TIM4,i);
				delay_us(100);
			}
		}
	}
	if(num==2)//ͨ��2
	{
		if(sign==1)
		{
			for(i=x;i>=y;i--)
			{
				TIM_SetCompare2(TIM4,i);
				delay_us(100);
			}
		}
		else if(sign==0)
		{
			for(i=x;i<=y;i++)
			{
				TIM_SetCompare2(TIM4,i);
				delay_us(100);
			}
		}
	}
	if(num==3)//ͨ��3
	{
		if(sign==1)
		{
			for(i=x;i>=y;i--)
			{
				TIM_SetCompare3(TIM4,i);
				delay_us(100);
			}
		}
		else if(sign==0)
		{
			for(i=x;i<=y;i++)
			{
				TIM_SetCompare3(TIM4,i);
				delay_us(100);
			}
		}
	}
	if(num==4)//ͨ��4
	{
		if(sign==1)
		{
			for(i=x;i>=y;i--)
			{
				TIM_SetCompare4(TIM4,i);
				delay_us(100);
			}
		}
		else if(sign==0)
		{
			for(i=x;i<=y;i++)
			{
				TIM_SetCompare4(TIM4,i);
				delay_us(100);
			}
		}
	}
}




void Stand(void)//վ��
{
	int j=0,sign=0;
	
	OLED_ShowImage(0,0,128,64,BMP1);
	OLED_Update();
	TIM_SetCompare1(TIM4,150 );//ռ�ձ�7.5%��ת90��
	TIM_SetCompare2(TIM4,150 );//ռ�ձ�7.5%��ת90��
	TIM_SetCompare3(TIM4,150 );//ռ�ձ�7.5%��ת90��
	TIM_SetCompare4(TIM4,150 );//ռ�ձ�7.5%��ת90��
	
	while(1)
	{
		count++;
		delay_ms(1);
		if(count%2==0)//ҡβ�ͺ��� 
		{
			j++;
			if(sign%2!=0)
			{
				TIM_SetCompare1(TIM3,(100+j));
			}
			if(sign%2==0)
			{
				TIM_SetCompare1(TIM3,(200-j));
			}
			if(j==100)
			{
				sign++;
				j=0;
			}
		}
		if(count==600)
		{
			count=0;
			break;
		}
	}
}

void Rock(void)//ҡ��
{
	int j=0,sign=0;
	
	OLED_ShowImage(0,0,128,64,BMP9);
	OLED_Update();
	
	while(1)
	{
		count++;
		delay_ms(1);
		
		if(count%2==0)
		{
			j++;
			if(sign%2!=0)
			{
				TIM_SetCompare1(TIM3,(100+j));
			}
			if(sign%2==0)
			{
				TIM_SetCompare1(TIM3,(200-j));
			}
			if(j==100)
			{
				sign++;
				j=0;
			}
		}
		
		if(count==150)
		{
			For(180,120,1);
			For(120,180,2);
			For(120,180,3);
			For(180,120,4);
		}
		if(count==350)
		{
			For(120,180,1);
			For(180,120,2);
			For(180,120,3);
			For(120,180,4);
		}
		if(count>=370)
		{
			count=0;
			break;
		}
	}
}

void Handshake(void)//����
{
	int j=0,sign=0;
	
	OLED_ShowImage(0,0,128,64,BMP11);
	OLED_Update();
	TIM_SetCompare2(TIM4,220 );
	TIM_SetCompare3(TIM4,160 );
	TIM_SetCompare4(TIM4,140 );
	while(1)
	{
		delay_ms(1);
		count++;
		
		if(count%2==0)
		{
			j++;
			if(sign%2!=0)
			{
				TIM_SetCompare1(TIM3,(100+j));
			}
			if(sign%2==0)
			{
				TIM_SetCompare1(TIM3,(200-j));
			}
			if(j==100)
			{
				sign++;
				j=0;
			}
		}
		
		if(count==200)
		{
			For(115,55,1);
		}
		if(count==500)
		{
			For(55,115,1);
		}
		if(count>=550)
		{
			count=0;
			break;
		}
	}
}



void Sleep(void)//˯��
{
	OLED_ShowImage(0,0,128,64,BMP6);
	OLED_Update();
	TIM_SetCompare1(TIM4,70 );
	TIM_SetCompare2(TIM4,70 );
	TIM_SetCompare3(TIM4,225 );
	TIM_SetCompare4(TIM4,225 );
}

void Sit(void)//��
{
	int j=0,sign=0;
	
	OLED_ShowImage(0,0,128,64,BMP10);
	OLED_Update();
	TIM_SetCompare1(TIM4,85 );
	TIM_SetCompare2(TIM4,215 );
	TIM_SetCompare3(TIM4,215 );
	TIM_SetCompare4(TIM4,85 );
	
	while(1)
	{
		count++;
		delay_ms(1);
		if(count%2==0)
		{
			j++;
			if(sign%2!=0)
			{
				TIM_SetCompare1(TIM3,(100+j));
			}
			if(sign%2==0)
			{
				TIM_SetCompare1(TIM3,(200-j));
			}
			if(j==100)
			{
				sign++;
				j=0;
			}
		}
		if(count==600)
		{
			count=0;
			break;
		}
	}
}



void Advance(void)//ǰ��
{
	int j=0,sign=0;
	
	OLED_ShowImage(0,0,128,64,BMP2);
	OLED_Update();
	
	while(1)
	{
		count++;
		delay_ms(1);
		if(count%2==0)
		{
			j++;
			if(sign%2!=0)
			{
				TIM_SetCompare1(TIM3,(100+j));
			}
			if(sign%2==0)
			{
				TIM_SetCompare1(TIM3,(200-j));
			}
			if(j==100)
			{
				sign++;
				j=0;
			}
		}
		if(count==50&&bug==0)
		{
			For(150,150,1);
			For(150,150,2);
		}
		if(count==50&&bug!=0)
		{
			For(150,195,1);
			For(150,105,2);
		}
		if(count==200)
		{
			For(105,150,4);
			For(195,150,3);
		}
		if(count==350&&bug==0)
		{
			For(150,105,1);
			For(150,195,2);
		}
		if(count==350&&bug!=0)
		{
			For(195,105,1);
			For(105,195,2);
		}
		if(count==550)
		{
			For(150,195,4);
			For(150,105,3);
		}
		if(count==700)
		{
			For(105,150,1);
			For(195,150,2);
		}
		if(count==900)
		{
			For(195,105,4);
			For(105,195,3);
		}

		if(count>=920)
		{
			count=0;
			break;
		}
	}
}

void Queen(void)//����
{
	int j=0,sign=0;
	
	OLED_ShowImage(0,0,128,64,BMP2);
	OLED_Update();
	
	while(1)
	{
		count++;
		delay_ms(1);
		
		if(count%2==0)
		{
			j++;
			if(sign%2!=0)
			{
				TIM_SetCompare1(TIM3,(100+j));
			}
			if(sign%2==0)
			{
				TIM_SetCompare1(TIM3,(200-j));
			}
			if(j==100)
			{
				sign++;
				j=0;
			}
		}
		if(count==50&&bug==0)
		{
			For(150,150,1);
			For(150,150,2);
		}
		if(count==50&&bug!=0)
		{
			For(150,115,1);
			For(150,185,2);
		}
		if(count==200)
		{
			For(185,150,4);
			For(115,150,3);
		}
		if(count==350&&bug==0)
		{
			For(150,185,1);
			For(150,115,2);
		}
		if(count==350&&bug!=0)
		{
			For(115,185,1);
			For(185,115,2);
		}
		if(count==550)
		{
			For(150,115,4);
			For(150,185,3);
		}
		if(count==700)
		{
			For(185,150,1);
			For(115,150,2);
		}
		if(count==900)
		{
			For(115,185,4);
			For(185,115,3);
		}
		if(count>=920)
		{
			count=0;
			break;
		}
	}
}

void Right(void)//��ת
{
	int j=0,sign=0;
	
	OLED_ShowImage(0,0,128,64,BMP3);
	OLED_Update();
	
	while(1)
	{
		count++;
		delay_ms(1);
		
		if(count%2==0)
		{
			j++;
			if(sign%2!=0)
			{
				TIM_SetCompare1(TIM3,(100+j));
			}
			if(sign%2==0)
			{
				TIM_SetCompare1(TIM3,(200-j));
			}
			if(j==100)
			{
				sign++;
				j=0;
			}
		}
		
		if(count==50)
		{
			For(150,105,1);
			For(150,105,2);
		}
		if(count==200)
		{
			For(150,195,4);
			For(150,195,3);
		}
		if(count==350)
		{
			For(105,150,1);
			For(105,150,2);
		}
		if(count==500)
		{
			For(195,150,4);
			For(195,150,3);
		}
		if(count>=550)
		{
			count=0;
			break;
		}
	}
}

void Left(void)//��ת
{
	int j=0,sign=0;
	
	OLED_ShowImage(0,0,128,64,BMP4);
	OLED_Update();

	while(1)
	{
		count++;
		delay_ms(1);
		
		if(count%2==0)
		{
			j++;
			if(sign%2!=0)
			{
				TIM_SetCompare1(TIM3,(100+j));
			}
			if(sign%2==0)
			{
				TIM_SetCompare1(TIM3,(200-j));
			}
			if(j==100)
			{
				sign++;
				j=0;
			}
		}
		

		if(count==50)
		{
			For(150,195,4);
			For(150,195,3);
		}
		if(count==200)
		{
			For(150,105,1);
			For(150,105,2);
		}
		if(count==350)
		{
			For(195,150,4);
			For(195,150,3);
		}
		if(count==500)
		{
			For(105,150,1);
			For(105,150,2);
		}
		if(count>=550)
		{
			count=0;
			break;
		}
	}
}

void pee(void)//����
{
	int j=0,sign=0;
	
	TIM_SetCompare1(TIM4,150 );//ռ�ձ�7.5%��ת90��
	TIM_SetCompare2(TIM4,50 );//ռ�ձ�7.5%��ת90��
	TIM_SetCompare3(TIM4,130 );//ռ�ձ�7.5%��ת90��
	TIM_SetCompare4(TIM4,170 );//ռ�ձ�7.5%��ת90��
	
	OLED_ShowImage(0,0,128,64,BMP9);
	OLED_Update();
	
	while(1)
	{
		count++;
		delay_ms(1);
		if(count%2==0)//ҡβ�ͺ��� 
		{
			j++;
			if(sign%2!=0)
			{
				TIM_SetCompare1(TIM3,(100+j));
			}
			if(sign%2==0)
			{
				TIM_SetCompare1(TIM3,(200-j));
			}
			if(j==100)
			{
				sign++;
				j=0;
			}
		}
		if(count==600)
		{
			count=0;
			break;
		}
	}
}

void dance(void)//����
{
	int j=0,sign=0;
	
	OLED_ShowImage(0,0,128,64,BMP11);
	OLED_Update();

	while(1)
	{
		count++;
		delay_ms(1);
		
		if(count%2==0)
		{
			j++;
			if(sign%2!=0)
			{
				TIM_SetCompare1(TIM3,(100+j));
			}
			if(sign%2==0)
			{
				TIM_SetCompare1(TIM3,(200-j));
			}
			if(j==100)
			{
				sign++;
				j=0;
			}
		}
		
		if(count==50)
		{
			For(150,90,1);
			For(150,90,2);
			For(150,90,3);
			For(150,90,4);
		}
		if(count==200)
		{
			For(90,150,1);
			For(90,150,2);
			For(90,150,3);
			For(90,150,4);
		}
		if(count==350)
		{
			For(150,210,1);
			For(150,210,2);
			For(150,210,3);
			For(150,210,4);
		}
		if(count==500)
		{
			For(210,150,1);
			For(210,150,2);
			For(210,150,3);
			For(210,150,4);
		}
		if(count==650)
		{
			For(150,105,1);
			For(150,195,2);
			For(150,195,3);
			For(150,105,4);
		}
		if(count==800)
		{
			For(105,150,1);
			For(195,150,2);
			For(195,150,3);
			For(105,150,4);
		}
		if(count==950)
		{
			For(150,195,1);
			For(150,105,2);
			For(150,105,3);
			For(150,195,4);
		}
		if(count==1100)
		{
			For(195,150,1);
			For(105,150,2);
			For(105,150,3);
			For(195,150,4);
		}
		if(count==1250)
		{
			For(150,195,1);
			For(150,105,2);
			For(150,105,3);
			For(150,195,4);
		}
		if(count==1400)
		{
			For(195,150,1);
			For(105,150,2);
			For(105,150,3);
			For(195,150,4);
		}
		if(count==1550)
		{
			For(150,105,1);
			For(150,195,2);
			For(150,195,3);
			For(150,105,4);
		}
		if(count==1700)
		{
			For(105,150,1);
			For(195,150,2);
			For(195,150,3);
			For(105,150,4);
		}
		if(count==1850)
		{
			For(150,90,1);
			For(150,90,2);
		}
		if(count==2000)
		{
			For(90,150,1);
			For(90,150,2);
		}
		if(count==2150)
		{
			For(150,210,3);
			For(150,210,4);
		}
		if(count==2300)
		{
			For(210,150,3);
			For(210,150,4);
		}
		if(count>=2350)
		{
			count=0;
			break;
		}
	}
}
void SwingLegs(void) {
	//int j=0,sign=0;
   // ��ѡ����OLED��Ļ����ʾ���¶�����ͼ��
    OLED_ShowImage(0, 0, 128, 64, BMP13);
    OLED_Update();

    // ��ʼλ�ã�������վ����β�;���
    TIM_SetCompare1(TIM4, 150); // ��ǰ��
    TIM_SetCompare2(TIM4, 150); // �Һ���
    TIM_SetCompare3(TIM4, 150); // ��ǰ��
    TIM_SetCompare4(TIM4, 150); // �����
    TIM_SetCompare1(TIM3, 150); // β��
    delay_ms(200); // �ȴ�500ms���ȶ���ʼ״̬

    // �������ȵ�����λ��
    For(150, 200, 2); // �Һ��ȴ�150ƽ��������200
    For(150, 100, 4); // ����ȴ�150ƽ��������100
    delay_ms(200); // �ȴ����¶������
		TIM_SetCompare2(TIM4, 70); // �Һ���
		TIM_SetCompare4(TIM4, 225); // �����
		TIM_SetCompare1(TIM4, 70); // ��ǰ��
		TIM_SetCompare3(TIM4, 225); // ��ǰ��
		delay_ms(200);
		TIM_SetCompare1(TIM4, 150); // ��ǰ��
    TIM_SetCompare2(TIM4, 150); // �Һ���
    TIM_SetCompare3(TIM4, 150); // ��ǰ��
    TIM_SetCompare4(TIM4, 150); // �����
//    while(1)
//	{
//		count++;
//		delay_ms(1);
//		if(count%2==0)//ҡβ�ͺ��� 
//		{
//			j++;
//			if(sign%2!=0)
//			{
//				TIM_SetCompare1(TIM3,(100+j));
//			}
//			if(sign%2==0)
//			{
//				TIM_SetCompare1(TIM3,(200-j));
//			}
//			if(j==100)
//			{
//				sign++;
//				j=0;
//			}
//		}
//		if(count==600)
//		{
//			count=0;
//			break;
//		}
//	}



}
void Sit_half(void)//����
{
	//int j=0,sign=0;
	
	OLED_ShowImage(0,0,128,64,BMP14);
	OLED_Update();
	TIM_SetCompare1(TIM4,85 );
	TIM_SetCompare2(TIM4,150 );
	TIM_SetCompare3(TIM4,215 );
	TIM_SetCompare4(TIM4,150 );
	
//	delay_ms(1000);
////	For(85,150,1);
////	For(215,150,3);
//	TIM_SetCompare1(TIM4,150);
//	TIM_SetCompare3(TIM4,150);
//	TIM_SetCompare2(TIM4,150);
//	TIM_SetCompare4(TIM4,150);
	
//	while(1)
//	{
//		count++;
//		delay_ms(1);
//		if(count%2==0)
//		{
//			j++;
//			if(sign%2!=0)
//			{
//				TIM_SetCompare1(TIM3,(100+j));
//			}
//			if(sign%2==0)
//			{
//				TIM_SetCompare1(TIM3,(200-j));
//			}
//			if(j==100)
//			{
//				sign++;
//				j=0;
//			}
//		}
//		if(count==600)
//		{
//			count=0;
//			break;
//		}
//	}
}
void dunqi(void){
	
	OLED_ShowImage(0,0,128,64,BMP15);
	OLED_Update();
	TIM_SetCompare1(TIM4, 85); // ��ǰ��
  TIM_SetCompare2(TIM4, 215); // �Һ���
  TIM_SetCompare3(TIM4, 215); // ��ǰ��
  TIM_SetCompare4(TIM4, 85); // �����
  TIM_SetCompare1(TIM3, 150); // β��
	delay_ms(300);
	For(85,150,1);
	For(215,150,2);
	For(215,150,3);
	For(85,150,4);
	delay_ms(300);
	
}
void kaiji(void){
	LED = !LED; // LED��˸
        OLED_ShowImage(0, 0, 128, 64,gImage_1);
				OLED_Update();
				delay_ms(80);
			OLED_ShowImage(0, 0, 128, 64,gImage_2);
				OLED_Update();
				delay_ms(80);
			OLED_ShowImage(0, 0, 128, 64,gImage_3);
				OLED_Update();
				delay_ms(80);
			OLED_ShowImage(0, 0, 128, 64,gImage_4);
				OLED_Update();
				delay_ms(80);
			OLED_ShowImage(0, 0, 128, 64,gImage_5);
				OLED_Update();
				delay_ms(80);
				OLED_ShowImage(0, 0, 128, 64,gImage_6);
				OLED_Update();
				delay_ms(80);
			OLED_ShowImage(0, 0, 128, 64,gImage_7);
				OLED_Update();
				delay_ms(80);
			OLED_ShowImage(0, 0, 128, 64,gImage_8);
				OLED_Update();
				delay_ms(80);
			OLED_ShowImage(0, 0, 128, 64,gImage_9);
				OLED_Update();
				delay_ms(80);
			OLED_ShowImage(0, 0, 128, 64,gImage_10);
				OLED_Update();
				delay_ms(80);
	
}

void welcome(void){
	
	OLED_ShowImage(0,0,128,64,BMP16);
	OLED_Update();
	TIM_SetCompare1(TIM4, 85); // ��ǰ��
  TIM_SetCompare2(TIM4, 150); // �Һ���
  TIM_SetCompare3(TIM4, 215); // ��ǰ��
  TIM_SetCompare4(TIM4, 150); // �����
  //TIM_SetCompare1(TIM3, 150); // β��
	delay_ms(200);
	For(85,150,1);
	//For(215,150,2);
	For(215,150,3);
	//For(85,150,4);
	//delay_ms(300);
	
}