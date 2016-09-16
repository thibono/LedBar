/*
 * LedBar.c
 *
 *  Created on: Sep 16, 2016
 *      Author: Onofre
 */


/*
 * PB2 is an output to 0 led - red led bar
 * PB3 is an output to 1 led - yellow led bar
 * PB4 is an output to 2nd~3rd - Green Led bar
 * PB5 is an output to 4th~5th - Green Led Bar
 * PB6 is an output to 6th~7th - Green Led Bar
 */
#include <stdint.h>
#include <stdlib.h>
#include "tm4c123gh6pm.h"
#include "LedBar.h"
#include "SysTick.h"



void LedBar_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x02;        // 1) activate port D
	while((SYSCTL_PRGPIO_R&0x02)==0){};   // allow time for clock to stabilize
	// 2) no need to unlock PD3-0
	GPIO_PORTB_AMSEL_R &= ~0xFC;      // 3) disable analog functionality on PB7-2
	GPIO_PORTB_PCTL_R &= ~0xFFFFFF00; // 4) GPIO
	GPIO_PORTB_DIR_R |= 0xFC;         // 5) make PB7-2 out
	GPIO_PORTB_AFSEL_R &= ~0xFC;      // 6) regular port function
	GPIO_PORTB_DEN_R |= 0xFC;         // 7) enable digital I/O on PB7-2
	GPIO_PORTB_DR8R_R |= 0xFC; 		  // 8) Set the pins as high current drive 8mA

}


void LedBar_Blink_Loop(uint32_t delay, uint32_t repetitions){

	do{
	LEDBAR = 0xFF;
	SysTick_Wait10ms(delay);
	 LEDBAR = 0x0;
	SysTick_Wait10ms(delay);

	repetitions--;
	}while(repetitions !=0);
}

void LedBar_6BitScale(uint32_t intensity){

	switch(intensity){

		case(0):
			LEDBAR = ~0x0;
			break;
		case(1):
			LEDBAR = ~0x4;
			break;
		case(2):
			LEDBAR = ~0xC;
			break;
		case(3):
			LEDBAR = ~0x1C;
			break;
		case(4):
			LEDBAR = ~0x3C;
			break;
		case(5):
			LEDBAR = ~0x7C;
			break;
		case(6):
			LEDBAR = ~0xFC;
			break;
		default :
			LEDBAR = ~0x0;
	}
}

void LedBar_Inividual(uint8_t pin){

	switch(pin){


			case(0):
		        LEDBAR = ~0x0;
				break;
			case(1):
				LEDBAR = ~0x4;
				break;
			case(2):
				LEDBAR = ~0x8;
				break;
			case(3):
				LEDBAR = ~0x10;
				break;
			case(4):
				LEDBAR = ~0x20;
				break;
			case(5):
				LEDBAR = ~0x40;
				break;
			case(6):
				LEDBAR = ~0x80;
				break;
			default :
				LEDBAR = ~0x0;
		}
}


void LedBar_Up(uint32_t delay){

	uint8_t i = 0;

	while(i++ != 6){
		LedBar_6BitScale(i);
		SysTick_Wait10ms(delay);
	}

}

void LedBar_Down(uint32_t delay){

	uint8_t i = 6;

	while(i-- != 0){
		LedBar_6BitScale(i);
		SysTick_Wait10ms(delay);
	}

}

int LedBar_12BitAnalogTo6BitScale(uint32_t analogValue){

	  if (analogValue <  200) return (0);          // ~ 5%
	  if (analogValue <  410) return (1);          // ~ 10%
	  if (analogValue <  820) return (2);          // ~ 20%
	  if (analogValue < 1640) return (3);          // ~ 40%
	  if (analogValue < 2460) return (4);          // ~ 60%
	  if (analogValue < 3280) return (5);          // ~ 80%
	  if (analogValue < 4095) return (6);          //  100%

}
void LedBar_Random(uint32_t delay){
    uint32_t random;

	random = rand() % 7;
	LedBar_Inividual(random);
	SysTick_Wait10ms(delay);
}

//void LedBar_Test(void){
//
//	LEDBAR
//
//}
