#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 
u8 keynum;
u32 p11=0,p22=0;//���Ŀǰ�ĽǶ�
float angle;
int num=0;
 int main(void)
 {		
	delay_init();	    	 //��ʱ������ʼ��	  
 KEY_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
 	
	TIM3_PWM_Init(1999,720-1);	 //72M/72=1Mhz�ļ���Ƶ��,��װ��ֵ500������PWMƵ��Ϊ 1M/500=2Khz.     
	TIM1_PWM_Init(1999,720-1);
	printf("\r\n��ʼ����0��");
	TIM_SetCompare2(TIM3,210);	  //��ת��0��	210  250   170   110  50
	TIM_SetCompare1(TIM1,218);	  //��ת��0��  215   250
	
	  while(1)
	{
	 keynum=Key_GetNum();
		
		
		if(keynum==1)
		{
		num+=1;
		switch(num)
			{
				case 1:
				TIM_SetCompare2(TIM3,250);	
delay_ms(10000);				
	TIM_SetCompare1(TIM1,250);
delay_ms(20000);
TIM_SetCompare2(TIM3,210);	  //��ת��0��	210  250   170   110  50
	TIM_SetCompare1(TIM1,218);	  				
			break;
				case 2:
					TIM_SetCompare2(TIM3,170);	
delay_ms(10000);				
	TIM_SetCompare1(TIM1,250);
delay_ms(20000);
TIM_SetCompare2(TIM3,210);	  //��ת��0��	210  250   170   110  50
	TIM_SetCompare1(TIM1,218);	
				break;
				case 3:
								TIM_SetCompare2(TIM3,110);	  
				delay_ms(10000);
	TIM_SetCompare1(TIM1,250);
delay_ms(20000);
TIM_SetCompare2(TIM3,210);	  //��ת��0��	210  250   170   110  50
	TIM_SetCompare1(TIM1,218);	
				break;
			
			case 4:
			
								TIM_SetCompare2(TIM3,50);	  
			delay_ms(20000);
	TIM_SetCompare1(TIM1,250);
delay_ms(20000);
TIM_SetCompare2(TIM3,210);	  //��ת��0��	210  250   170   110  50
	TIM_SetCompare1(TIM1,218);	
			break;
					}
		if(num>4)
		{
		num=0;
		}
		
	}
}
	
	
	
	
	
	
	





	 /*while(1)  
	{
		delay_ms(5000);
		quick_move(0,90);//һ�Ŷ�������Ŷ��
		delay_ms(5000);
		quick_move(180,145);//һ�Ŷ�������Ŷ��
 		
		printf("\r\n����ת��90��");
		
		
		
	}	 */
 

}
