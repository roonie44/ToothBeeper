#include "main.hpp"

void CTimerModule::Init(void)
{

}

void CTimerModule::Handle(void)
{
	// Display current timer value
	Display.PrintDec(u32TimerValue);
	// Beep on special values
	switch(u32TimerValue)
	{
	case 120:
		Buzzer.BeepShort(1);
		break;
	case 90:
		Buzzer.BeepShort(2);
		break;
	case 60:
		Buzzer.BeepShort(3);
		break;
	case 30:
		Buzzer.BeepShort(4);
		break;
	case 0:
	   Buzzer.BeepLong(1);
		// Exception to wait one more second before shutdown
		u32TimerValue = 10000;
		return;
	case 10000:
		EnterShutdownMode();
	}

	// Decrement
	if(u32TimerValue)
		u32TimerValue--;
}

void CTimerModule::Reload(void)
{
	u32TimerValue = TIMER_RELOAD_VALUE;
}
