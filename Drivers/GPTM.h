//GPTM.h

#ifndef GPTM_H
#define GPTM_H

//base addresses
#define GPTM0 ((unsigned char*) 0x40030000)
#define GPTM1 ((unsigned char*) 0x40031000)
#define GPTM2 ((unsigned char*) 0x40032000)
#define GPTM3	((unsigned char*) 0x40033000)

//offsets
#define GPTMCFG			0x000
#define GPTMTAMR		0x004
#define GPTMTBMR		0x008
#define GPTMCTL			0x00C
#define GPTMIMR			0x018
#define GPTMRIS			0x01C
#define GPTMMIS			0x020
#define GPTMICR			0x024
#define GPTMTAILR		0x028
#define GPTMTBILR		0x02C
#define GPTMTAMATCHR	0x030
#define GPTMTBMATCHR	0x034
#define GPTMTAPR		0x038
#define GPTMTBPR		0x03C
#define GPTMTAPMR		0x040
#define GPTMTBPMR		0x044
#define GPTMTAR			0x048
#define GPTMTBR			0x04C

void initGPTM_EdgeCount(unsigned char* gptmBaseAddr, unsigned int timeout, unsigned int irqMask);
void initGPTMA_Periodic(unsigned char* base, unsigned int timeout, unsigned int irqMask);

#endif
