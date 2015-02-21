//GPIO.c

#include "GPIO.h"
#include "regop.h"

void gpio_initDigital(unsigned char* baseAddr, unsigned char inMask, unsigned char outMask)
{
	baseAddr[GPIODIR] = outMask;
	baseAddr[GPIODR2R] = inMask | outMask;
	baseAddr[GPIOODR] = outMask;
	baseAddr[GPIOPUR] = inMask;
	baseAddr[GPIODEN] = inMask | outMask;
	
}

void gpio_initAF(unsigned char* baseAddr, unsigned char AF_Mask, unsigned int AF_PCTL)
{
	
	baseAddr[GPIOAFSEL] = AF_Mask;
	
	//only needed on Tiva C
	//writeReg(baseAddr, GPIOPCTL, AF_PCTL);
	
}
