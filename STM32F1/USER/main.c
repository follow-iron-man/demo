#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 
u8 keynum;
u32 p11=0,p22=0;//舵机目前的角度
float angle;
int num=0;
 int main(void)
 {		
	delay_init();	    	 //延时函数初始化	  
 KEY_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
 	
	TIM3_PWM_Init(1999,720-1);	 //72M/72=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz.     
	TIM1_PWM_Init(1999,720-1);
	printf("\r\n初始化到0度");
	TIM_SetCompare2(TIM3,210);	  //先转到0度	210  250   170   110  50
	TIM_SetCompare1(TIM1,218);	  //先转到0度  215   250
	
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
TIM_SetCompare2(TIM3,210);	  //先转到0度	210  250   170   110  50
	TIM_SetCompare1(TIM1,218);	  				
			break;
				case 2:
					TIM_SetCompare2(TIM3,170);	
delay_ms(10000);				
	TIM_SetCompare1(TIM1,250);
delay_ms(20000);
TIM_SetCompare2(TIM3,210);	  //先转到0度	210  250   170   110  50
	TIM_SetCompare1(TIM1,218);	
				break;
				case 3:
								TIM_SetCompare2(TIM3,110);	  
				delay_ms(10000);
	TIM_SetCompare1(TIM1,250);
delay_ms(20000);
TIM_SetCompare2(TIM3,210);	  //先转到0度	210  250   170   110  50
	TIM_SetCompare1(TIM1,218);	
				break;
			
			case 4:
			
								TIM_SetCompare2(TIM3,50);	  
			delay_ms(20000);
	TIM_SetCompare1(TIM1,250);
delay_ms(20000);
TIM_SetCompare2(TIM3,210);	  //先转到0度	210  250   170   110  50
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
		quick_move(0,90);//一号舵机，二号舵机
		delay_ms(5000);
		quick_move(180,145);//一号舵机，二号舵机
 		
		printf("\r\n慢速转到90度");
		
		
		
	}	 */
 

}
