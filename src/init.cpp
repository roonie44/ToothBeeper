#include "main.hpp"

#define VECT_TAB_OFFSET  0x00

void Init_SystemClock(void)
{
  /* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
  #endif
  /* Reset the RCC clock configuration to the default reset state ------------*/
  /* Set MSION bit */
  RCC->CR |= RCC_CR_MSION;

  /* Reset CFGR register */
  RCC->CFGR = 0x00000000;

  /* Reset HSEON, CSSON , HSION, and PLLON bits */
  RCC->CR &= (uint32_t)0xEAF6FFFF;

  /* Reset PLLCFGR register */
  RCC->PLLCFGR = 0x00001000;

  /* Reset HSEBYP bit */
  RCC->CR &= (uint32_t)0xFFFBFFFF;

  /* Disable all interrupts */
  RCC->CIER = 0x00000000;

  /* Configure the Vector Table location add offset address ------------------*/
  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */

}

void Init_PeriphClock(void)
{
   LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
   LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);

   LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
   LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
   LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
   LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOD);
   LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOH);

   LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM6);	// BUZZER
   LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM7);	// DISPLAY
}

void Init_GPIO(void)
{
   LL_GPIO_InitTypeDef GPIO_InitStruct;
   GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
   GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_MEDIUM;
	GPIO_InitStruct.Pin = LL_GPIO_PIN_ALL;

	LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
	LL_GPIO_Init(GPIOH, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = LL_GPIO_PIN_ALL & ~(LL_GPIO_PIN_13 | LL_GPIO_PIN_14);
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

   // Display
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;

   GPIO_InitStruct.Pin     = PIN_DISPLAY_SEG_A_PIN;
   LL_GPIO_Init(PIN_DISPLAY_SEG_A_PORT, &GPIO_InitStruct);
   GPIO_InitStruct.Pin     = PIN_DISPLAY_SEG_B_PIN;
   LL_GPIO_Init(PIN_DISPLAY_SEG_B_PORT, &GPIO_InitStruct);
   GPIO_InitStruct.Pin     = PIN_DISPLAY_SEG_C_PIN;
   LL_GPIO_Init(PIN_DISPLAY_SEG_C_PORT, &GPIO_InitStruct);
   GPIO_InitStruct.Pin     = PIN_DISPLAY_SEG_D_PIN;
   LL_GPIO_Init(PIN_DISPLAY_SEG_D_PORT, &GPIO_InitStruct);
   GPIO_InitStruct.Pin     = PIN_DISPLAY_SEG_E_PIN;
   LL_GPIO_Init(PIN_DISPLAY_SEG_E_PORT, &GPIO_InitStruct);
   GPIO_InitStruct.Pin     = PIN_DISPLAY_SEG_F_PIN;
   LL_GPIO_Init(PIN_DISPLAY_SEG_F_PORT, &GPIO_InitStruct);
   GPIO_InitStruct.Pin     = PIN_DISPLAY_SEG_G_PIN;
   LL_GPIO_Init(PIN_DISPLAY_SEG_G_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin     = PIN_DISPLAY_DIG_0_PIN;
	LL_GPIO_Init(PIN_DISPLAY_DIG_0_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin     = PIN_DISPLAY_DIG_1_PIN;
	LL_GPIO_Init(PIN_DISPLAY_DIG_1_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin     = PIN_DISPLAY_DIG_2_PIN;
	LL_GPIO_Init(PIN_DISPLAY_DIG_2_PORT, &GPIO_InitStruct);

	// Buzzer
	GPIO_InitStruct.Pin     = PIN_BUZZER_VCC_PIN;
	LL_GPIO_Init(PIN_BUZZER_VCC_PORT, &GPIO_InitStruct);

	// Button
	GPIO_InitStruct.Mode    = LL_GPIO_MODE_INPUT;
	GPIO_InitStruct.Pin     = PIN_BUTTON_PIN;
	LL_GPIO_Init(PIN_BUTTON_PORT, &GPIO_InitStruct);
}

void Init_Timers(void)
{
	// 1 tick/1 s
	SysTick_Config(CPU_CLOCK_FREQUENCY);

	// Buzzer Timer
	LL_TIM_SetPrescaler(TIM6, CPU_CLOCK_FREQUENCY/1000);
	LL_TIM_SetOnePulseMode(TIM6, 1);
	LL_TIM_GenerateEvent_UPDATE(TIM6);

	// Display Timer
	LL_TIM_SetOnePulseMode(TIM7, LL_TIM_ONEPULSEMODE_REPETITIVE);
	LL_TIM_SetAutoReload(TIM7, CPU_CLOCK_FREQUENCY / (DISPLAY_DIGIT_COUNT * DISPLAY_REFRESH_RATE));
	LL_TIM_EnableCounter(TIM7);
}

void Init_Interrupts(void)
{
   // TIM6 Update (Buzzer)
	LL_TIM_EnableIT_UPDATE(TIM6);
   NVIC_EnableIRQ(TIM6_DAC_IRQn);

   // TIM7 Update (Display)
	LL_TIM_EnableIT_UPDATE(TIM7);
   NVIC_EnableIRQ(TIM7_IRQn);

   // Button
   LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_0);
   LL_EXTI_EnableFallingTrig_0_31(LL_EXTI_LINE_0);
   LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_0);
   LL_EXTI_EnableIT_0_31(LL_EXTI_LINE_0);
   NVIC_EnableIRQ(EXTI0_IRQn);
}

void Init_Hardware(void)
{
   Init_SystemClock();
	//SystemInit();
   Init_PeriphClock();
	Init_GPIO();
   Init_Timers();
   Init_Interrupts();
}
