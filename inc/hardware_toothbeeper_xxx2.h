#ifndef HARDWARE_H_
#define HARDWARE_H_

#define CPU_CLOCK_FREQUENCY		4000000

// Pattern
#define PIN__PIN              	LL_GPIO_PIN_
#define PIN__PORT             	GPIO

// DISPLAY
#define PIN_DISPLAY_SEG_A_PIN 	LL_GPIO_PIN_0
#define PIN_DISPLAY_SEG_A_PORT   GPIOB
#define PIN_DISPLAY_SEG_B_PIN 	LL_GPIO_PIN_9
#define PIN_DISPLAY_SEG_B_PORT   GPIOA
#define PIN_DISPLAY_SEG_C_PIN 	LL_GPIO_PIN_7
#define PIN_DISPLAY_SEG_C_PORT   GPIOC
#define PIN_DISPLAY_SEG_D_PIN 	LL_GPIO_PIN_11
#define PIN_DISPLAY_SEG_D_PORT   GPIOB
#define PIN_DISPLAY_SEG_E_PIN 	LL_GPIO_PIN_13
#define PIN_DISPLAY_SEG_E_PORT   GPIOB
#define PIN_DISPLAY_SEG_F_PIN 	LL_GPIO_PIN_11
#define PIN_DISPLAY_SEG_F_PORT   GPIOA
#define PIN_DISPLAY_SEG_G_PIN 	LL_GPIO_PIN_15
#define PIN_DISPLAY_SEG_G_PORT   GPIOB

#define PIN_DISPLAY_DIG_0_PIN 	LL_GPIO_PIN_9
#define PIN_DISPLAY_DIG_0_PORT   GPIOC
#define PIN_DISPLAY_DIG_1_PIN 	LL_GPIO_PIN_2
#define PIN_DISPLAY_DIG_1_PORT   GPIOB
#define PIN_DISPLAY_DIG_2_PIN 	LL_GPIO_PIN_4
#define PIN_DISPLAY_DIG_2_PORT   GPIOC

// BUZZER
#define PIN_BUZZER_VCC_PIN       LL_GPIO_PIN_1
#define PIN_BUZZER_VCC_PORT      GPIOC

// BUTTON
#define PIN_BUTTON_PIN       		LL_GPIO_PIN_0
#define PIN_BUTTON_PORT      		GPIOA
#endif /* HARDWARE_H_ */
