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

// 串口1标志,接收到A赋值1，接收到B赋值2
u8 USART1_Sign = 0;

int main(void)
{	
    u32 i = 0;  // 循环计数器

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // 设置NVIC中断分组2
    //delay_init();  // 延时函数初始化
    LED_Init();    // 初始化LED
    //My_EXTI_Init(); // 按键中断初始化
    USART1_Init(115200); // 串口1初始化
    USART2_Init(115200);
    USART3_Init(9600);
    OLED_Init();   // OLED初始化
    OLED_Clear();  // 清屏
    TIM4_CH1_Init(1999,719); // 左前
    TIM4_CH2_Init(1999,719); // 左后
    TIM4_CH3_Init(1999,719); // 右前
    TIM4_CH4_Init(1999,719); // 右后
    TIM3_CH1_Init(1999,719); // 尾巴
    TIM_SetCompare1(TIM4,150); // 占空比7.5%旋转90度
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
			Advance();//前进
			bug++;//解决立正到前进的连贯问题
			if(Sign1!=0)
			{
				bug=0;
				Sign1=0;
			}
		}
		else if(Sign==2)
		{
			OLED_Clear();  // 清屏
			Queen();//后退
			bug++;
			if(Sign1!=0)
			{
				bug=0;
				Sign1=0;
			}
		}
		else if(Sign==3)
		{
			OLED_Clear();  // 清屏
			Left();//左转
		}
		else if(Sign==4)
		{
			OLED_Clear();  // 清屏
			Right();//右转
		}
		else if(Sign==5)
		{
			OLED_Clear();  // 清屏
			Stand();//站立
		}
		else if(Sign==6)
		{
			OLED_Clear();  // 清屏
			Rock();//摇摆
		}
		else if(Sign==7)
		{
			OLED_Clear();  // 清屏
			Handshake();//握手
		}
		else if(Sign==8)
		{
			OLED_Clear();  // 清屏
			Sleep();//睡觉
		}
		else if(Sign==9)
		{
			OLED_Clear();  // 清屏
			Sit();//坐
		}
		else if(Sign==10)
		{
			OLED_Clear();  // 清屏
			dance();//跳舞
		}
		else if(Sign==11)
		{
			OLED_Clear();  // 清屏
			pee();//撒尿
		}
		else if(Sign==12)
		{
			OLED_Clear();  // 清屏
			Stand();//立正
		}
		else if (Sign == 13) {
			OLED_Clear();  // 清屏
            SwingLegs(); // 前后腿持续摆动
        }
		else if (Sign == 14) {
			OLED_Clear();  // 清屏
            Sit_half(); // 前后腿持续摆动
        }
		else if (Sign == 15) {
			OLED_Clear();  // 清屏
            dunqi();
        }
		else if (Sign == 16) {
			OLED_Clear();  // 清屏
            welcome();
        }


		i++ ;
		delay_ms(10);

    }
}