#include "init.h"
#include "main.hpp"

CDisplayModule		Display;
CBuzzerModule		Buzzer;
CTimerModule		Timer;
bool					ButtonState;

int main(void)
{
   Init_Hardware();

   Display.Init();
	Timer.Init();
   Timer.Reload();
   Timer.Handle();

   ButtonState = false;

   /* Infinite loop */
   while (ButtonState == false);
   while (ButtonState == true);

   EnterShutdownMode();
}

void EnterShutdownMode(void)
{
	// Disable internal wakeup line
	PWR->CR3 &= ~PWR_CR3_EIWF;

  	// Clear all wake up Flags
  	PWR->SCR |= PWR_SCR_CWUF;

  	// Select wakeup pin polarity (0: rising, 1: falling)
  	PWR->CR4 |= PWR_CR4_WP1;
  	//PWR->CR4 &= PWR_CR4_WP1;
  	// Enable wakeup pin WKUP1 (PA0)
  	PWR->CR3 |= LL_PWR_WAKEUP_PIN1;

  	// Set SHUTDOWN mode when CPU enters deepsleep
  	LL_PWR_SetPowerMode(LL_PWR_MODE_SHUTDOWN);

  	// Set SLEEPDEEP bit of Cortex System Control Register
  	LL_LPM_EnableDeepSleep();

  	/* Request Wait For Interrupt */
  	__WFI();
}
