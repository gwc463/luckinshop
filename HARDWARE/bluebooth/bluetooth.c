#include "bluetooth.h"
#include "infrared.h"

u8 Sign1=0;
int USART3_Sign = 20;
u8 Blue_data[6];

void USART3_Init(u32 baud)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate=baud;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(USART3,&USART_InitStructure);
	
	
	NVIC_InitStructure.NVIC_IRQChannel=USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART3,ENABLE);
}


void USART3_IRQHandler(void)
{
	//OLED��ʾ����
	u8 string[10]={0};
	 static int i=0;
	
	if(USART_GetITStatus(USART3, USART_IT_RXNE)!=RESET)
	{
//		OLED_Clear();
		LED=!LED;
		Blue_data[i++]=USART_ReceiveData(USART3);
		if(i==2)i=0;
		if(Blue_data[0]==108&&Blue_data[1]==108)Sign=5;//����
		if(Blue_data[0]==102&&Blue_data[1]==102)Sign=1;//ǰ��
		if(Blue_data[0]==97&&Blue_data[1]==97)Sign=2;//����
		if((Blue_data[0]==108&&Blue_data[1]==115)||(Blue_data[0]==115&&Blue_data[1]==108))Sign=3;//��ת
		if((Blue_data[0]==114&&Blue_data[1]==115)||(Blue_data[0]==115&&Blue_data[1]==114))Sign=4;//��ת
		if((Blue_data[0]==120&&Blue_data[1]==120))Sign=10;//10����
		if(Blue_data[0]==114&&Blue_data[1]==114)Sign=6;//ҡ��
		if((Blue_data[0]==108&&Blue_data[1]==117)||(Blue_data[0]==117&&Blue_data[1]==108))Sign=7;//����
		if((Blue_data[0]==114&&Blue_data[1]==117)||(Blue_data[0]==117&&Blue_data[1]==114))Sign=9;//��
		if((Blue_data[0]==108&&Blue_data[1]==100)||(Blue_data[0]==100&&Blue_data[1]==108))Sign=8;//˯��
		if(Blue_data[0]==112&&Blue_data[1]==112)//PP
		{
			bug=0;
			Sign=12;
			Sign1++;
		}
		if(Blue_data[0]==121&&Blue_data[1]==121)Sign=14;//����
		if(Blue_data[0] == 115 && Blue_data[1] == 115) Sign = 13; // ǰ���Ȱڶ� (ss) - ����
		if(Blue_data[0]==122&&Blue_data[1]==122)Sign=15;//����
		if(Blue_data[0]==123&&Blue_data[1]==123)Sign=16;//dig
		
		
	}
}


