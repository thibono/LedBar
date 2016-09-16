/*
 * main.c


 */

#include <stdint.h>
#include "LedBar.h"
#include "SysTick.h"

int main(void) {

	SysTick_Init();
	LedBar_Init();

	Led_Blink_Loop(10,3);


	while(1){
		Led_Scale(0);
		SysTick_Wait10ms(10);
		Led_Scale(1);
		SysTick_Wait10ms(10);
		Led_Scale(2);
		SysTick_Wait10ms(10);
		Led_Scale(3);
		SysTick_Wait10ms(10);
		Led_Scale(4);
		SysTick_Wait10ms(10);
		Led_Scale(5);
		SysTick_Wait10ms(10);

		Led_Scale(5);
		SysTick_Wait10ms(10);
		Led_Scale(4);
		SysTick_Wait10ms(10);
		Led_Scale(3);
		SysTick_Wait10ms(10);
		Led_Scale(2);
		SysTick_Wait10ms(10);
		Led_Scale(1);
		SysTick_Wait10ms(10);
		Led_Scale(0);
		SysTick_Wait10ms(10);
	}
}
