#include "pcb_config.h"
#include "stm32f10x.h"


void pcb_RCC_Config(void)
 {
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
 }
 
void pcb_GPIO_Init(void)
 { 
   GPIO_InitTypeDef GPIO_InitStructure; 
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
 	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;			
   GPIO_Init(GPIOC, &GPIO_InitStructure);
	 
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
 	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;			
   GPIO_Init(GPIOA, &GPIO_InitStructure);	 
	 
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
 	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
 	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;			
   GPIO_Init(GPIOC, &GPIO_InitStructure);	 
   
 }




void pcb_Init(void)
 {
  pcb_RCC_Config();
  pcb_GPIO_Init();
  delay_init();
	 CS_1;
	GPIO_SetBits(GPIOA, GPIO_Pin_11);
  lcd_init();
  
 }


