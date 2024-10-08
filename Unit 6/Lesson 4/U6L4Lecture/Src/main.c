/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include"stdint.h"
#define RCC_Base 0x40021000
#define GPIOA_Base 0x40010800

#define APB2ENR    *((volatile uint32_t *)(RCC_Base +0x18))
#define GPIOA_CRL        *(volatile uint32_t *)(GPIOA_Base + 0x00)
#define GPIOA_CRH        *(volatile uint32_t *)(GPIOA_Base + 0x04)
#define GPIOA_ODR        *(volatile uint32_t *)(GPIOA_Base + 0x0C)

#define RCC_CFGR    *((volatile uint32_t *)(RCC_Base +0x04))
#define RCC_CR    *((volatile uint32_t *)(RCC_Base +0x0))



#define EXTI_BASE       0x40010400
#define EXTI_IMR        *((volatile uint32_t * )(EXTI_BASE + 0x00))
#define EXTI_EMR        *((volatile uint32_t * )(EXTI_BASE +  0x04))
#define EXTI_RTSR        *((volatile uint32_t * )(EXTI_BASE + 0x08))
#define EXTI_FTSR        *((volatile uint32_t * )(EXTI_BASE + 0x0C))
#define EXTI_SWIER        *((volatile uint32_t * )(EXTI_BASE + 0x10))
#define EXTI_PR        *((volatile uint32_t * )(EXTI_BASE + 0x14))


#define AFIO_BASE               0x40010000
#define  AFIO_EXTICR1          *((volatile uint32_t * )(AFIO_BASE + 0x08))
#define NVIC_ISER0         *(volatile uint32_t *)(0xE000E100)




typedef volatile unsigned int vint32_t;


void clock_init(){
	// enable clock of GPIOA
	 APB2ENR |= (1<<2);
	 APB2ENR |= (1<<0);

}

void GPIOA_INIT(){
	//set pin 13 as ouptput pin
	GPIOA_CRH = 0xff0fffff;
	GPIOA_CRH |= 0x00200000;
}

int main(void)
{
	clock_init();
	GPIOA_INIT();


	EXTI_IMR |= (1<<0) ;

	EXTI_RTSR |= (1<<0);

	EXTI_SWIER |= (1<<0);

	AFIO_EXTICR1 = 0;

	GPIOA_CRL |= (1<<2);

	NVIC_ISER0 |= (1<<6);
	while(1);
}


void EXTI0_IRQHandler(){

	GPIOA_ODR ^= (1<<13);
	EXTI_PR |= (1<<0);
}
