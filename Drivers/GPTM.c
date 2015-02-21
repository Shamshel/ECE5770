//GPTM.c

#include "GPTM.h"
#include "regop.h"

void initGPTM_EdgeCount(unsigned char* gptmBaseAddr, unsigned int timeout, unsigned int irqMask)
{
	//disable timer
	writeReg(gptmBaseAddr, GPTMCTL, 0x00);
	
	//write GPTMCFG with 0x4
	writeReg(gptmBaseAddr, GPTMCFG, 0x04);
	
	//write the TACMR field to 0x0 and the TAMR to 0x3
	writeReg(gptmBaseAddr, GPTMTAMR, 0x03);
	
	//load the start value
	writeReg(gptmBaseAddr, GPTMTAILR, timeout);
	
	//set interrupt mask
	orWriteReg(gptmBaseAddr, GPTMIMR, irqMask);
	
	//define the event type by writing TAEVENT in GPTMCTL and enable
	//(posedge)
	writeReg(gptmBaseAddr, GPTMCTL, 0x01);
	
}

void initGPTMA_Periodic(unsigned char* base, unsigned int timeout, unsigned int irqMask)
{
	//disable timer
	writeReg(base, GPTMCTL, 0x00);
	
	//write GPTMCFG 0x00
	writeReg(base, GPTMCFG, 0x04);
	
	//configure GPTMTAMR for periodic operation
	writeReg(base, GPTMTAMR, 0x02);
	
	//load GPTMTAILR with countdown value
	writeReg(base, GPTMTAILR, timeout);
	
	//set interrupt mask
	writeReg(base, GPTMIMR, irqMask);
	
	//enable TMRA
	orWriteReg(base, GPTMCTL, 0x01);
	
}

