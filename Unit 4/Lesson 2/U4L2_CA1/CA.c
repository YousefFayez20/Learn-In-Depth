/*
 * CA.c
 *
 *  Created on: Sep 30, 2024
 *      Author: DELL
 */

#include "stdio.h"
#include "CA.h"

static int speed = 0;
static int distance = 0;
static int threshold = 50;


void (*CA_state)();




STATE_define(CA_WAITING){

	speed = 0;
	distance = US_GetDistanceRandom(45 , 55 , 1);

	if(distance <= threshold){
		CA_state = STATE(CA_WAITING);
	}
	else{
		CA_state = STATE(CA_DRIVING);
	}

	printf("CA_driving State: Distance = %d  Speed = %d \n",distance , speed);
}
STATE_define(CA_DRIVING){
	speed = 30;
	distance = US_GetDistanceRandom(45 , 55 , 1);

	if(distance <= threshold){
		CA_state = STATE(CA_WAITING);
	}
	else{
		CA_state = STATE(CA_DRIVING);
	}
	printf("CA_driving State: Distance = %d  Speed = %d \n",distance , speed);


}
int US_GetDistanceRandom(int l , int r , int count){

	int i;
	for(i=0; i<count; ++i){
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}}

