/*
 * main.c
 *
 *  Created on: Sep 30, 2024
 *      Author: DELL
 */

#include "CA.h"


void Setup()
{
	/* init all drivers */
	/* inti IRQ */
	/* init HAL Drivers */
	/* init Block */
	/* Set State pointer for each block */
	CA_state = STATE(CA_WAITING);
}
int main()
{
	Setup();

	while(1)
	{
		/* Call state for each block */
		CA_state();

	}
	return 0;
}
