/*
 * DC.c
 *
 *  Created on: Sep 30, 2024
 *      Author: DELL
 */

#include "DC.h"


static int DC_Speed = 0;

void (*DC_state)();
void DC_init()
{

	printf("DC init \n");
}

void DC_Motor_Set(int Speed)
{
	DC_Speed = Speed;
	DC_state = STATE(DC_start);
	printf("CA --------Speed=%d--------> DC \n",DC_Speed);
}
STATE_define(DC_start)
{

	DC_state_id = DC_start;
	printf("DC_start State: Speed = %d \n",DC_Speed);
}

STATE_define(DC_stop)
{

	DC_state_id = DC_stop;
	printf("DC_stop State: Speed = %d \n",DC_Speed);
	DC_state = STATE(DC_start);
}
