//regop.h

/*
 * Written by Cody Herndon in conjunction with David Petrizze for ECE 3710, Fall 2013
 */

#ifndef REGOP_H
#define REGOP_H

void writeReg(unsigned char* baseAddr, unsigned int offset, unsigned int regVal);
unsigned int readReg(unsigned char* baseAddr, unsigned int offset);
void andWriteReg(unsigned char* baseAddr, unsigned int offset, unsigned int regVal);
void orWriteReg(unsigned char* baseAddr, unsigned int offset, unsigned int regVal);

#endif
