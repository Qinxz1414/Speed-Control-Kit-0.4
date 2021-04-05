#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "key.h"  
#include "24cxx.h" 
#include "myiic.h"
#include "touch.h" 
#include "exti.h" 
#include "pcb_config.h"
#include "mxl90614.h"
#include "timer.h"

int counter=0;
int speed=0;
int PWM=0;

int FLAG=50;


 int main(void)
 { 
 	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
	LCD_Init();			   	//初始化LCD 	
	KEY_Init();				//按键初始化		
  EXTIX_Init();		//外部中断初始化	 
	//TIM3_Int_Init(4999,7199);//10Khz的计数频率，计数到5000为500ms  
	TIM3_Int_Init(35,39);//10Khz的计数频率，计数到5000为500ms  

				{unsigned int Tem1,Tem2,Tem3;
				pcb_Init();
				SMBus_Init();

				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
				GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource0);
        				
				PWM=2;	
					
				while(1)
				{
				Tem1=SMBus_ReadMemory(SA1,RAM_TOBJ1);
				display(1,1,Tem1);
				Tem2=SMBus_ReadMemory(SA2,RAM_TOBJ1);
				display(2,2,Tem2);
				Tem3=SMBus_ReadMemory(SA3,RAM_TOBJ1);
				display(3,3,Tem3);

				slave_num(4,4);
				//write_figer(4,3,GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0));	
				//write_figer(4,3,counter);	

				//write_figer(4,4,speed);	
				//write_figer(4,4,PWM);	
				write_figer(4,3,speed);	
				write_figer(4,6,PWM);	
					
					
					
					
					
					if(PAin(13) )
						PWM++;					
					if(PAin(15) )
						PWM--;					

				}
				}
}

