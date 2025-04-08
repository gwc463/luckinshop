#include "tianwen.h"
#include "infrared.h"
#include "led.h"

u16 USART2_Res=0;
u16 USART2_Res2=0;
int USART2_Sign = 0;
int Sign = 0;

void USART2_Init(u32 baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate=baud;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(USART2,&USART_InitStructure);
	
	
	NVIC_InitStructure.NVIC_IRQChannel=USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART2,ENABLE);
}

void USART2_IRQHandler(void)
{

	
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) 
	{
		USART2_Res =USART_ReceiveData(USART2);	//��ȡ���յ�������
		if(USART2_Res!=USART2_Res2)
		{
			bug=0;
		}
		if(USART2_Res==0x31)Sign=5;//����
		if(USART2_Res==0x32)Sign=1;//ǰ��
		if(USART2_Res==0x33)Sign=2;//����
		if(USART2_Res==0x34)Sign=3;//��ת
		if(USART2_Res==0x35)Sign=4;//��ת
		if(USART2_Res==0x36)Sign=7;//����
		if(USART2_Res==0x37)Sign=9;//��
		if(USART2_Res==0x38)Sign=8;//˯��
		if(USART2_Res==0x39)Sign=6;//ҡ��
		if(USART2_Res==0x61)Sign=10;//����
		if(USART2_Res==0x62)Sign=11;//����
		if(USART2_Res == 0x63) Sign = 13;  // ǰ���Ȱڶ� ('c')
		if(USART2_Res==0x64) Sign=82;
		if(USART2_Res==0x65) Sign=14;//����
		if(USART2_Res==0x66) Sign=15;//����
		if(USART2_Res==0x67) Sign=16;//��ӭ
		USART2_Res2=USART2_Res;
		
	}
}