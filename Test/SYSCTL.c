//SYSCTL.c

#include "SYSCTL.h"
#include "regop.h"

void sysctl_enableRCGC(unsigned int offset, unsigned int val)
{
	orWriteReg(SYSCTL, offset, val);
	
}
