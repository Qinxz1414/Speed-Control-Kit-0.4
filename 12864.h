#ifndef __12864_H
#define __12864_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define CLK_1 GPIO_SetBits(GPIOC, GPIO_Pin_6);  
#define CLK_0 GPIO_ResetBits(GPIOC, GPIO_Pin_6); 

#define SID_1 GPIO_SetBits(GPIOC, GPIO_Pin_5);  
#define SID_0 GPIO_ResetBits(GPIOC, GPIO_Pin_5);

#define CS_1 GPIO_SetBits(GPIOC, GPIO_Pin_4);  
#define CS_0 GPIO_ResetBits(GPIOC, GPIO_Pin_4);


void Delay(__IO uint32_t nCount);
unsigned char get_byte(void);
void check_busy(void);
void send_cmd(unsigned char cmd);
void write_char(unsigned char dat);
void lcd_clear(void);        //清除显示
void lcd_pos(unsigned char y_add , unsigned char x_add);
void lcd_wstr(unsigned char y_add , unsigned char x_add , unsigned char *str) ;
void write_figer(unsigned char y_add , unsigned char x_add , unsigned int figer);//在任何位置写数字
void lcd_init(void);     //
void Delay(__IO uint32_t nCount);
void img_disp(unsigned char const *img);
void send_dat(unsigned char dat);
void LcdClearBMP(void); 

#endif
