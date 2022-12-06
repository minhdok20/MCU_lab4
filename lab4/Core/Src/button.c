/*
 * button.c
 *
 *  Created on: Dec 6, 2022
 *      Author: HP PV
 */


#include "button.h"

int button1_flag = 0;

int KeyReg0Button1 = NORMAL_STATE;
int KeyReg1Button1 = NORMAL_STATE;
int KeyReg2Button1 = NORMAL_STATE;
int KeyReg3Button1 = NORMAL_STATE;

int TimeOutForKeyPress1 = 2000;
int flagTimeOut1 = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyPocess1(){
	button1_flag = 1;
}

void getKeyInput1(){
	KeyReg0Button1 = KeyReg1Button1;
	KeyReg1Button1 = KeyReg2Button1;
	KeyReg2Button1 = HAL_GPIO_ReadPin(button_GPIO_Port, button_Pin);
	//check button stability by comparing the history of push button states
	if((KeyReg1Button1 == KeyReg0Button1) && (KeyReg1Button1 == KeyReg2Button1)){
		if(KeyReg2Button1 != KeyReg3Button1){
			KeyReg3Button1 = KeyReg2Button1;
			if(KeyReg2Button1 == PRESSED_STATE){
				//After holding down for 2s, switch to long press for 1s to toggle red led
				if(flagTimeOut1 == 1)
					TimeOutForKeyPress1 = 1000/TIME_CYCLE;
				else
					TimeOutForKeyPress1 = 2000/TIME_CYCLE;
				subKeyPocess1();
			}
		} else{
			TimeOutForKeyPress1--;
			if(TimeOutForKeyPress1 == 0){
				KeyReg3Button1 = NORMAL_STATE;
				flagTimeOut1 = 1;
			}
		}
	}
	else
		//back press hold 2s
		flagTimeOut1 = 0;
}
