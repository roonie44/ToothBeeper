#ifndef BUZZER_HPP_
#define BUZZER_HPP_

#define BUZZER_BEEP_SHORT_LENGTH		100
#define BUZZER_BEEP_LONG_LENGTH		1000
#define BUZZER_BEEP_INTERVAL			150

class CBuzzerModule
{
	bool Beep;
	unsigned int u32BeepCount;
	unsigned int u32BeepLength;

public:
   void Init     			(void);
   void Handle   			(void);

   void BeepShort			(unsigned int u32BeepCount);
   void BeepLong 			(unsigned int u32BeepCount);
};
#endif /* BUZZER_HPP_ */
