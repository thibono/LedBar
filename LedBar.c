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
#include "tm4c123gh6pm.h"
#include "LedBar.h"



void LedBar_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x02;        // 1) activate port D
	while((SYSCTL_PRGPIO_R&0x02)==0){};   // allow time for clock to stabilize
	// 2) no need to unlock PD3-0
	GPIO_PORTB_AMSEL_R &= ~0x7C;      // 3) disable analog functionality on PB6-2
	GPIO_PORTB_PCTL_R &= ~0x0FFFFF00; // 4) GPIO
	GPIO_PORTB_DIR_R |= 0x7C;         // 5) make PB6-2 out
	GPIO_PORTB_AFSEL_R &= ~0x7C;      // 6) regular port function
	GPIO_PORTB_DEN_R |= 0x7C;         // 7) enable digital I/O on PB6-2

}


void Led_Blink_Loop(uint32_t delay, uint32_t repetitions){

	do{
	LEDBAR = 0xFF;
	SysTick_Wait10ms(delay);
	 LEDBAR = 0x0;
	SysTick_Wait10ms(delay);

	repetitions--;
	}while(repetitions !=0);
}

void Led_Scale(uint32_t intensity){

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
	}
}

//void LedBar_Test(void){
//
//	LEDBAR
//
//}
