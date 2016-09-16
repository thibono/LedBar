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

void LedBar_Blink_Loop(uint32_t delay, uint32_t repetitions);
void LedBar_6BitScale(uint32_t intensity);
int LedBar_12BitAnalogTo6BitScale(uint32_t analogValue);
void LedBar_Inividual(uint8_t pin);
void LedBar_Up(uint32_t delay);
void LedBar_Down(uint32_t delay);
void LedBar_Random(uint32_t delay);



#endif /* LEDBAR_H_ */
