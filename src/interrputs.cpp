#include "main.hpp"

extern void *_sidata, *_sdata, *_edata, *_sbss, *_ebss, *_estack;
//void __libc_init_array(void);
void Reset_Handler(void);

void TIM6_DAC_IRQHandler(void)
{
	LL_TIM_ClearFlag_UPDATE(TIM6);
	Buzzer.Handle();
}

void TIM7_IRQHandler(void)
{
	LL_TIM_ClearFlag_UPDATE(TIM7);
	Display.Handle();
}

void SysTick_Handler(void)
{
	Timer.Handle();
}

void EXTI0_IRQHandler(void)
{
	LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_0);
	ButtonState = !LL_GPIO_IsInputPinSet(PIN_BUTTON_PORT, PIN_BUTTON_PIN);
}

void Default_Handler(void)
{
	while(1);
}

#define NMI_Handler Default_Handler
#define HardFault_Handler Default_Handler
#define MemManage_Handler Default_Handler
#define BusFault_Handler Default_Handler
#define UsageFault_Handler Default_Handler
#define SVC_Handler Default_Handler
#define DebugMon_Handler Default_Handler
#define PendSV_Handler Default_Handler
//#define SysTick_Handler Default_Handler
#define WWDG_IRQHandler Default_Handler
#define PVD_PVM_IRQHandler Default_Handler
#define TAMP_STAMP_IRQHandler Default_Handler
#define RTC_WKUP_IRQHandler Default_Handler
#define FLASH_IRQHandler Default_Handler
#define RCC_IRQHandler Default_Handler
//#define EXTI0_IRQHandler Default_Handler
#define EXTI1_IRQHandler Default_Handler
#define EXTI2_IRQHandler Default_Handler
#define EXTI3_IRQHandler Default_Handler
#define EXTI4_IRQHandler Default_Handler
#define DMA1_Channel1_IRQHandler Default_Handler
#define DMA1_Channel2_IRQHandler Default_Handler
#define DMA1_Channel3_IRQHandler Default_Handler
#define DMA1_Channel4_IRQHandler Default_Handler
#define DMA1_Channel5_IRQHandler Default_Handler
#define DMA1_Channel6_IRQHandler Default_Handler
#define DMA1_Channel7_IRQHandler Default_Handler
#define ADC1_IRQHandler Default_Handler
#define CAN1_TX_IRQHandler Default_Handler
#define CAN1_RX0_IRQHandler Default_Handler
#define CAN1_RX1_IRQHandler Default_Handler
#define CAN1_SCE_IRQHandler Default_Handler
#define EXTI9_5_IRQHandler Default_Handler
#define TIM1_BRK_TIM15_IRQHandler Default_Handler
#define TIM1_UP_TIM16_IRQHandler Default_Handler
#define TIM1_TRG_COM_IRQHandler Default_Handler
#define TIM1_CC_IRQHandler Default_Handler
#define TIM2_IRQHandler Default_Handler
#define TIM3_IRQHandler Default_Handler
#define TIM4_IRQHandler Default_Handler
#define I2C1_EV_IRQHandler Default_Handler
#define I2C1_ER_IRQHandler Default_Handler
#define I2C2_EV_IRQHandler Default_Handler
#define I2C2_ER_IRQHandler Default_Handler
#define SPI1_IRQHandler Default_Handler
#define SPI2_IRQHandler Default_Handler
#define USART1_IRQHandler Default_Handler
#define USART2_IRQHandler Default_Handler
#define USART3_IRQHandler Default_Handler
#define EXTI15_10_IRQHandler Default_Handler
#define RTC_Alarm_IRQHandler Default_Handler
#define DFSDM3_IRQHandler Default_Handler
#define TIM8_BRK_IRQHandler Default_Handler
#define TIM8_UP_IRQHandler Default_Handler
#define TIM8_TRG_COM_IRQHandler Default_Handler
#define TIM8_CC_IRQHandler Default_Handler
#define ADC3_IRQHandler Default_Handler
#define FMC_IRQHandler Default_Handler
#define SDMMC1_IRQHandler Default_Handler
#define TIM5_IRQHandler Default_Handler
#define SPI3_IRQHandler Default_Handler
#define UART4_IRQHandler Default_Handler
#define UART5_IRQHandler Default_Handler
//#define TIM6_DAC_IRQHandler Default_Handler
//#define TIM7_IRQHandler Default_Handler
#define DMA2_Channel1_IRQHandler Default_Handler
#define DMA2_Channel2_IRQHandler Default_Handler
#define DMA2_Channel3_IRQHandler Default_Handler
#define DMA2_Channel4_IRQHandler Default_Handler
#define DMA2_Channel5_IRQHandler Default_Handler
#define DFSDM0_IRQHandler Default_Handler
#define DFSDM1_IRQHandler Default_Handler
#define DFSDM2_IRQHandler Default_Handler
#define COMP_IRQHandler Default_Handler
#define LPTIM1_IRQHandler Default_Handler
#define LPTIM2_IRQHandler Default_Handler
#define OTG_FS_IRQHandler Default_Handler
#define DMA2_Channel6_IRQHandler Default_Handler
#define DMA2_Channel7_IRQHandler Default_Handler
#define LPUART1_IRQHandler Default_Handler
#define QUADSPI_IRQHandler Default_Handler
#define I2C3_EV_IRQHandler Default_Handler
#define I2C3_ER_IRQHandler Default_Handler
#define SAI1_IRQHandler Default_Handler
#define SAI2_IRQHandler Default_Handler
#define SWPMI1_IRQHandler Default_Handler
#define TSC_IRQHandler Default_Handler
#define LCD_IRQHandler Default_Handler
#define RNG_IRQHandler Default_Handler
#define FPU_IRQHandler Default_Handler

void* g_pfnVectors[] __attribute__ ((section (".isr_vector"))) =
{
   &_estack,
   (void*)&Reset_Handler,
   (void*)&NMI_Handler,
   (void*)&HardFault_Handler,
   (void*)&MemManage_Handler,
   (void*)&BusFault_Handler,
   (void*)&UsageFault_Handler,
   0,
   0,
   0,
   0,
   (void*)&SVC_Handler,
   (void*)&DebugMon_Handler,
   0,
   (void*)&PendSV_Handler,
   (void*)&SysTick_Handler,
   (void*)&WWDG_IRQHandler,
   (void*)&PVD_PVM_IRQHandler,
   (void*)&TAMP_STAMP_IRQHandler,
   (void*)&RTC_WKUP_IRQHandler,
   (void*)&FLASH_IRQHandler,
   (void*)&RCC_IRQHandler,
   (void*)&EXTI0_IRQHandler,
   (void*)&EXTI1_IRQHandler,
   (void*)&EXTI2_IRQHandler,
   (void*)&EXTI3_IRQHandler,
   (void*)&EXTI4_IRQHandler,
   (void*)&DMA1_Channel1_IRQHandler,
   (void*)&DMA1_Channel2_IRQHandler,
   (void*)&DMA1_Channel3_IRQHandler,
   (void*)&DMA1_Channel4_IRQHandler,
   (void*)&DMA1_Channel5_IRQHandler,
   (void*)&DMA1_Channel6_IRQHandler,
   (void*)&DMA1_Channel7_IRQHandler,
   (void*)&ADC1_IRQHandler,
   (void*)&CAN1_TX_IRQHandler,
   (void*)&CAN1_RX0_IRQHandler,
   (void*)&CAN1_RX1_IRQHandler,
   (void*)&CAN1_SCE_IRQHandler,
   (void*)&EXTI9_5_IRQHandler,
   (void*)&TIM1_BRK_TIM15_IRQHandler,
   (void*)&TIM1_UP_TIM16_IRQHandler,
   (void*)&TIM1_TRG_COM_IRQHandler,
   (void*)&TIM1_CC_IRQHandler,
   (void*)&TIM2_IRQHandler,
   (void*)&TIM3_IRQHandler,
   (void*)&TIM4_IRQHandler,
   (void*)&I2C1_EV_IRQHandler,
   (void*)&I2C1_ER_IRQHandler,
   (void*)&I2C2_EV_IRQHandler,
   (void*)&I2C2_ER_IRQHandler,
   (void*)&SPI1_IRQHandler,
   (void*)&SPI2_IRQHandler,
   (void*)&USART1_IRQHandler,
   (void*)&USART2_IRQHandler,
   (void*)&USART3_IRQHandler,
   (void*)&EXTI15_10_IRQHandler,
   (void*)&RTC_Alarm_IRQHandler,
   (void*)&DFSDM3_IRQHandler,
   (void*)&TIM8_BRK_IRQHandler,
   (void*)&TIM8_UP_IRQHandler,
   (void*)&TIM8_TRG_COM_IRQHandler,
   (void*)&TIM8_CC_IRQHandler,
   (void*)&ADC3_IRQHandler,
   (void*)&FMC_IRQHandler,
   (void*)&SDMMC1_IRQHandler,
   (void*)&TIM5_IRQHandler,
   (void*)&SPI3_IRQHandler,
   (void*)&UART4_IRQHandler,
   (void*)&UART5_IRQHandler,
   (void*)&TIM6_DAC_IRQHandler,
   (void*)&TIM7_IRQHandler,
   (void*)&DMA2_Channel1_IRQHandler,
   (void*)&DMA2_Channel2_IRQHandler,
   (void*)&DMA2_Channel3_IRQHandler,
   (void*)&DMA2_Channel4_IRQHandler,
   (void*)&DMA2_Channel5_IRQHandler,
   (void*)&DFSDM0_IRQHandler,
   (void*)&DFSDM1_IRQHandler,
   (void*)&DFSDM2_IRQHandler,
   (void*)&COMP_IRQHandler,
   (void*)&LPTIM1_IRQHandler,
   (void*)&LPTIM2_IRQHandler,
   (void*)&OTG_FS_IRQHandler,
   (void*)&DMA2_Channel6_IRQHandler,
   (void*)&DMA2_Channel7_IRQHandler,
   (void*)&LPUART1_IRQHandler,
   (void*)&QUADSPI_IRQHandler,
   (void*)&I2C3_EV_IRQHandler,
   (void*)&I2C3_ER_IRQHandler,
   (void*)&SAI1_IRQHandler,
   (void*)&SAI2_IRQHandler,
   (void*)&SWPMI1_IRQHandler,
   (void*)&TSC_IRQHandler,
   (void*)&LCD_IRQHandler,
   0,
   (void*)&RNG_IRQHandler,
   (void*)&FPU_IRQHandler,
};


//void __attribute__((naked, noreturn)) Reset_Handler()
void Reset_Handler(void)
{
   SCB->VTOR = (uint32_t)&g_pfnVectors;
   //Normally the CPU will setup the based on the value from the first entry in the vector table.
   //If you encounter problems with accessing stack variables during initialization, ensure
   asm ("ldr sp, =_estack");

   void **pSource, **pDest;

   // Copy the data segment initializers from flash to SRAM
   for (pSource = &_sidata, pDest = &_sdata; pDest != &_edata; pSource++, pDest++)
   	*pDest = *pSource;

   // Zero fill the bss segment
   for (pDest = &_sbss; pDest != &_ebss; pDest++)
   	*pDest = 0;

   //__libc_init_array();

   main();
}
