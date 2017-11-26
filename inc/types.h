#ifndef _TYPES_H_
#define _TYPES_H_

#define ASCII(x)	((x < 10) ? (x + 0x30) : (x + 0x37))

typedef union
{
	unsigned int 		uInt;
	struct
	{
		unsigned short uShortL;
		unsigned short uShortH;
	};
	struct
	{
		unsigned char 	uCharLL;
		unsigned char 	uCharLH;
		unsigned char 	uCharHL;
		unsigned char 	uCharHH;
	};
	struct
	{
		unsigned int 	uNibbleLLL	: 4;
		unsigned int 	uNibbleLLH	: 4;
		unsigned int 	uNibbleLHL	: 4;
		unsigned int 	uNibbleLHH	: 4;
		unsigned int 	uNibbleHLL	: 4;
		unsigned int 	uNibbleHLH	: 4;
		unsigned int 	uNibbleHHL	: 4;
		unsigned int 	uNibbleHHH	: 4;
	};
}TUINT;

#endif
