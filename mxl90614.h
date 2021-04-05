#ifndef __mxl90614_H
#define __mxl90614_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define ACK         0
#define NACK          1
#define SA1          0x5a
#define SA2          0x11
#define SA3          0x22
#define RAM_ACCESS                  0x00 //RAM access command
#define EEPROM_ACCESS            0x20 //EEPROM access command
#define RAM_TOBJ1                0x07 //To1 address in the eeprom

#define SMBUS_PORT            GPIOB
#define SMBUS_SCK                GPIO_Pin_6
#define SMBUS_SDA                GPIO_Pin_7

#define RCC_APB2Periph_SMBUS_PORT                RCC_APB2Periph_GPIOB


#define SMBUS_SCK_H()            SMBUS_PORT->BSRR = SMBUS_SCK
#define SMBUS_SCK_L()            SMBUS_PORT->BRR = SMBUS_SCK
#define SMBUS_SDA_H()            SMBUS_PORT->BSRR = SMBUS_SDA
#define SMBUS_SDA_L()            SMBUS_PORT->BRR = SMBUS_SDA

#define SMBUS_SDA_PIN()            SMBUS_PORT->IDR & SMBUS_SDA //??????

#define uint unsigned int

void SMBus_Init(void);
void SMBus_StartBit(void);
void SMBus_StopBit(void);
u8 SMBus_SendByte(u8 Tx_buffer);
void SMBus_SendBit(u8 bit_out);
u8 SMBus_ReceiveBit(void);
u8 SMBus_ReceiveByte(u8 ack_nack);
void SMBus_Delay(u16 time);
u16 SMBus_ReadMemory(u8 slaveAddress, u8 command);
u8 PEC_Calculation(u8 pec[]);
float SMBus_ReadTemp(u8 SA);
void number(unsigned char o,unsigned char p);
void slave_num(unsigned char r,unsigned char w);
void display( unsigned int q,unsigned s,unsigned int Tem);
#endif 
