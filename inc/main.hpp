#ifndef MAIN_HPP_
#define MAIN_HPP_

#include "stm32l4xx.h"
#include "stm32l4xx_ll_cortex.h"
#include "stm32l4xx_ll_rcc.h"
#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_exti.h"
#include "stm32l4xx_ll_gpio.h"
#include "stm32l4xx_ll_tim.h"
#include "stm32l4xx_ll_pwr.h"

#include "hardware_toothbeeper_xxx2.h"
#include "types.h"

#include "../CDisplay/display.hpp"
#include "../CBuzzer/buzzer.hpp"
#include "../CTimer/timer.hpp"

extern CDisplayModule Display;
extern CBuzzerModule	Buzzer;
extern CTimerModule Timer;
extern bool ButtonState;

int main	(void);
void EnterShutdownMode(void);
#endif // MAIN_HPP_
