#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#define DISPLAY_DIGIT_COUNT	3
#define DISPLAY_REFRESH_RATE	50 // Hz

#define DISPLAY_DIGIT_OFF		255

class CDisplayModule
{
	unsigned char 	u8Digit[DISPLAY_DIGIT_COUNT];
	unsigned int	u32DigitCurrent;
public:
   void DigitSelect		(unsigned int u32DigitIdx);
	void DigitSet			(unsigned char u8Digit);
	void DigitClear  		(void);

public:
   void Init     			(void);
   void Handle   			(void);

	void PrintDec			(unsigned int u32Number);
	void PrintBCD			(unsigned int u32Number);

};
#endif /* DISPLAY_HPP_ */
