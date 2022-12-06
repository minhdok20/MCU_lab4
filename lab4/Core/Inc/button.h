/*
 * button.h
 *
 *  Created on: Dec 6, 2022
 *      Author: HP PV
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "scheduler.h"

int isButton1Pressed();

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

void getKeyInput1();

#endif /* INC_BUTTON_H_ */
