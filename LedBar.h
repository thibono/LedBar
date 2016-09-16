/*
 * LedBar.h
 *
 *  Created on: Sep 16, 2016
 *      Author: Onofre
 */

#ifndef LEDBAR_H_
#define LEDBAR_H_

#define LEDBAR (*((volatile unsigned long *)0x400053FC))

void LedBar_Init(void);

void Led_Blink_Loop(uint32_t delay, uint32_t repetitions);
void Led_Scale(uint32_t intensity);
#endif /* LEDBAR_H_ */
