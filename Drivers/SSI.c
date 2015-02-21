//SSI.c

#include "SSI.h"
#include "regop.h"

void ssi_enableClock(unsigned int mask)
{
	*RCGCSSI = mask;
	
}

void ssi_config(unsigned char* ssi, unsigned int config_0, unsigned int config_1, unsigned int config_clock, unsigned int config_prescale)
{
	//disable SSI
	writeReg(ssi, SSICR1, 0x00);
	
	//config clock (only on Tiva C)
	//writeReg(ssi, SSICC, config_clock);
	
	//set SSICR0
	writeReg(ssi, SSICR0, config_0);
	
	//set prescaler
	writeReg(ssi, SSICPSR, config_prescale);
	
	//enable SSI/write config 1
	writeReg(ssi, SSICR1, config_1|0x02);
	
}

unsigned short ssi_transfer(unsigned char* ssi, unsigned short data)
{
	writeReg(ssi, SSIDR, data);
	
	while((readReg(ssi, SSISR) & 0x10) != 0x10);
	
	return (unsigned short)readReg(ssi, SSIDR);
	
}
