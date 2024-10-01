/*
 * DC.h
 *
 *  Created on: Sep 30, 2024
 *      Author: DELL
 */

#ifndef DC_H_
#define DC_H_
#include "stdio.h"
#include "state.h"

enum{
	DC_start,
	DC_stop
}DC_state_id;

STATE_define(DC_start);
STATE_define(DC_stop);

void DC_init();
extern void (*DC_state) ();


void US_Get_Distance(int Distance);
void DC_Motor_Set(int Speed);

#endif /* DC_H_ */
