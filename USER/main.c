#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "exti.h"
#include "leg.h"
#include "mode.h"
#include "OLED.h"
#include "OLED_Data.h" 
#include "tianwen.h"
#include "bluetooth.h"

// ����1��־,���յ�A��ֵ1�����յ�B��ֵ2
u8 USART1_Sign = 0;

int main(void)
{	
    u32 i = 0;  // ѭ��������

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // ����NVIC�жϷ���2
    //delay_init();  // ��ʱ������ʼ��
    LED_Init();    // ��ʼ��LED
    //My_EXTI_Init(); // �����жϳ�ʼ��
    USART1_Init(115200); // ����1��ʼ��
    USART2_Init(115200);
    USART3_Init(9600);
    OLED_Init();   // OLED��ʼ��
    OLED_Clear();  // ����
    TIM4_CH1_Init(1999,719); // ��ǰ
    TIM4_CH2_Init(1999,719); // ���
    TIM4_CH3_Init(1999,719); // ��ǰ
    TIM4_CH4_Init(1999,719); // �Һ�
    TIM3_CH1_Init(1999,719); // β��
    TIM_SetCompare1(TIM4,150); // ռ�ձ�7.5%��ת90��
    TIM_SetCompare2(TIM4,150);
    TIM_SetCompare3(TIM4,150);
    TIM_SetCompare4(TIM4,150);

    
    OLED_Update();

    while (1)
    {		
			if(Sign==82){
				OLED_ShowImage(0,0,128,64,BMP1);
				OLED_Update();
			}
			if(Sign==0){	
					kaiji();
		}
        
        if(Sign==1)
		{	OLED_Clear();
			Advance();//ǰ��
			bug++;//���������ǰ������������
			if(Sign1!=0)
			{
				bug=0;
				Sign1=0;
			}
		}
		else if(Sign==2)
		{
			OLED_Clear();  // ����
			Queen();//����
			bug++;
			if(Sign1!=0)
			{
				bug=0;
				Sign1=0;
			}
		}
		else if(Sign==3)
		{
			OLED_Clear();  // ����
			Left();//��ת
		}
		else if(Sign==4)
		{
			OLED_Clear();  // ����
			Right();//��ת
		}
		else if(Sign==5)
		{
			OLED_Clear();  // ����
			Stand();//վ��
		}
		else if(Sign==6)
		{
			OLED_Clear();  // ����
			Rock();//ҡ��
		}
		else if(Sign==7)
		{
			OLED_Clear();  // ����
			Handshake();//����
		}
		else if(Sign==8)
		{
			OLED_Clear();  // ����
			Sleep();//˯��
		}
		else if(Sign==9)
		{
			OLED_Clear();  // ����
			Sit();//��
		}
		else if(Sign==10)
		{
			OLED_Clear();  // ����
			dance();//����
		}
		else if(Sign==11)
		{
			OLED_Clear();  // ����
			pee();//����
		}
		else if(Sign==12)
		{
			OLED_Clear();  // ����
			Stand();//����
		}
		else if (Sign == 13) {
			OLED_Clear();  // ����
            SwingLegs(); // ǰ���ȳ����ڶ�
        }
		else if (Sign == 14) {
			OLED_Clear();  // ����
            Sit_half(); // ǰ���ȳ����ڶ�
        }
		else if (Sign == 15) {
			OLED_Clear();  // ����
            dunqi();
        }
		else if (Sign == 16) {
			OLED_Clear();  // ����
            welcome();
        }


		i++ ;
		delay_ms(10);

    }
}