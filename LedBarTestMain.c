/*
 * main.c


 */

#include <stdint.h>
#include "LedBar.h"
#include "SysTick.h"

int main(void) {

	uint32_t i = 0;
	SysTick_Init();
	LedBar_Init();

	while(1){
		i = 0;
		LedBar_Up(20);
		LedBar_Down(20);

		LedBar_Blink_Loop(10,5);

		// Testing going up and down with individual leds
		LedBar_Down(10);
		LedBar_Up(10);

		// testing the blinking loop
		LedBar_Blink_Loop(5,10);

		//Testing the analog to digital scale - going up
		while(i != 4100){

			LedBar_6BitScale(LedBar_12BitAnalogTo6BitScale(i));
			i+=100;
			SysTick_Wait10ms(5);
		}

		//Testing the analog to digital scale - going down
		while(i != 0){

			LedBar_6BitScale(LedBar_12BitAnalogTo6BitScale(i));
			i-=100;
			SysTick_Wait10ms(5);
		}

		//Testing the analog to digital scale - going up
		while(i != 30){

			LedBar_Random(10);
			i++;
		}


	}
}
