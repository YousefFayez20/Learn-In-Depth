/*
 * CA.h
 *
 *  Created on: Sep 30, 2024
 *      Author: DELL
 */

#ifndef CA_H_
#define CA_H_


#include "stdio.h"
#include "state.h"


enum{
	CA_WAITING,
	CA_DRIVING
}CA_STATE_ID;

STATE_define(CA_WAITING);
STATE_define(CA_DRIVING);
int US_GetDistanceRandom(int l , int r , int count);

extern void (*CA_state)();

#endif /* CA_H_ */
