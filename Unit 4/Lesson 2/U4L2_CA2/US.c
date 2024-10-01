/*
 * US.c
 *
 *  Created on: Sep 30, 2024
 *      Author: DELL
 */
/* Variables */

#include "US.h"


static int US_Distance = 0;


void (*US_state) ();


void US_init()
{

	printf("US_init \n");
}
STATE_define(US_busy)
{

	US_state_id = US_busy;

	US_Distance = US_GetDistanceRandom(45, 55, 1);

	printf("US_waiting State: Distance = %d \n",US_Distance);
	US_Get_Distance(US_Distance);
	US_state = STATE(US_busy);
}

int US_GetDistanceRandom(int l , int r , int count)
{

	int i;
	for(i=0; i<count; ++i){
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
}

