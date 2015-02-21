//regop.c

/*
 * Written by Cody Herndon in conjunction with David Petrizze for ECE 3710, Fall 2013
 */

#include "regop.h"

void writeReg(unsigned char* baseAddr, unsigned int offset, unsigned int regVal)
{
	baseAddr[offset] = regVal & 0xFF;
	baseAddr[offset+1] = regVal>>8 & 0xFF;
	baseAddr[offset+2] = regVal>>16 & 0xFF;
	baseAddr[offset+3] = regVal>>24 & 0xFF;
	
}

unsigned int readReg(unsigned char* baseAddr, unsigned int offset)
{
	unsigned int temp = 0;
	
	temp = baseAddr[offset];
	temp += baseAddr[offset+1]<<8;
	temp += baseAddr[offset+2]<<16;
	temp += baseAddr[offset+3]<<24;
	
	return temp;
	
}

void andWriteReg(unsigned char* baseAddr, unsigned int offset, unsigned int regVal)
{
	//read
	unsigned int temp = readReg(baseAddr, offset);
	
	//modify
	temp = temp & regVal;
	
	//write
	writeReg(baseAddr, offset, temp);
	
}

void orWriteReg(unsigned char* baseAddr, unsigned int offset, unsigned int regVal)
{
	//read
	int temp = readReg(baseAddr, offset);
	
	//modify
	temp = temp | regVal;

	//write
	writeReg(baseAddr, offset, temp);
	
}

