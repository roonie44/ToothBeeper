#include "main.hpp"

void CBuzzerModule::Handle(void)
{
	if(u32BeepCount)
	{
		if(Beep)
		{
			Beep = false;
			LL_GPIO_ResetOutputPin(PIN_BUZZER_VCC_PORT, PIN_BUZZER_VCC_PIN);
			LL_TIM_SetAutoReload(TIM6, BUZZER_BEEP_INTERVAL);
			u32BeepCount--;
		}
		else
		{
			Beep = true;
			LL_GPIO_SetOutputPin(PIN_BUZZER_VCC_PORT, PIN_BUZZER_VCC_PIN);
			LL_TIM_SetAutoReload(TIM6, u32BeepLength);
		}

		if(u32BeepCount > 0)
		{
			LL_TIM_SetCounter(TIM6, 0);
			LL_TIM_EnableCounter(TIM6);
		}
	}
}

void CBuzzerModule::BeepShort(unsigned int u32BeepCount)
{
	this->u32BeepCount 	= u32BeepCount;
	this->u32BeepLength 	= BUZZER_BEEP_SHORT_LENGTH;
	Handle();
}

void CBuzzerModule::BeepLong(unsigned int u32BeepCount)
{
	this->u32BeepCount 	= u32BeepCount;
	this->u32BeepLength	= BUZZER_BEEP_LONG_LENGTH;
	Handle();
}
