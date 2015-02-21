//SYSCTL.h

#ifndef SYSCTL_H
#define SYSCTL_H

#define FREQUENCY 12000000//Hz

#define SYSCTL ((unsigned char*) 0x400FE000)
#define RIS 0x050
#define IMC 0x054
#define MISC 0x058
#define RCC 0x060
#define PLLCFG 0x064
#define RCC2 0x070
#define RCGC0 0x100
#define RCGC1 0x104
#define RCGC2 0x108

void sysctl_enableRCGC(unsigned int offset, unsigned int val);

#endif
