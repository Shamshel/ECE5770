//NVIC.c

#include "NVIC.h"
#include "regop.h"

void enableInterrupt(unsigned char interruptNum, unsigned char priority)
{
	
	if(interruptNum>31)
	{
		orWriteReg(M3CP, EN1, 0x01<<(interruptNum-31));
		
	}
	
	else
	{
		orWriteReg(M3CP, EN0, 0x01<<interruptNum);
		
	}
	
	if(interruptNum%4 == 0)
	{
		orWriteReg(M3CP, PRI0+(interruptNum), priority<<5);
		
	}
	
	else if(interruptNum%4 == 1)
	{
		orWriteReg(M3CP, PRI0+(interruptNum-1), priority<<13);
		
	}
	
	else if(interruptNum%4 == 2)
	{
		orWriteReg(M3CP, PRI0+(interruptNum-2), priority<<21);
		
	}
	
	else if(interruptNum%4 == 3)
	{
		orWriteReg(M3CP, PRI0+(interruptNum-3), priority<<29);
		
	}
	
	
	
}
