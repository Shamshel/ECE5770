//NVIC.h

#ifndef NVIC_H
#define NVIC_H

//offsets
#define EN0 0x100
#define EN1 0x104
#define DIS0 0x180
#define DIS1 0x184
#define PEND0 0x200
#define PEND1 0x204
#define UNPEND0 0x280
#define UNPEND1 0x284
#define ACTIVE0 0x300
#define ACTIVE1 0x304
#define PRI0 0x400

//base addr
#define M3CP ((unsigned char*)0xE000E000)

void enableInterrupt(unsigned char interruptNum, unsigned char priority);

#endif
