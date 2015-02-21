//GPIO.h
#ifndef GPIO_H
#define GPIO_H

//offsets
#define GPIODATA		0x3FC 
#define GPIODIR			0x400
#define GPIOIS			0x404
#define GPIOIBE			0x408
#define GPIOIEV			0x40C
#define GPIOIM			0x410
#define GPIORIS			0x414
#define GPIOMIS			0x418
#define GPIOICR			0x41C
#define GPIOAFSEL		0x420
#define GPIODR2R		0x500
#define GPIODR4R		0x504
#define GPIODR8R		0x508
#define GPIOODR			0x50C
#define GPIOPUR			0x510
#define GPIOPDR			0x514
#define GPIODEN			0x51C
#define GPIOLOCK		0x520
#define GPIOCR			0x524
#define GPIOPCTL		0x52C

#define GPIOA_CLK		0x01
#define GPIOB_CLK		0x02
#define GPIOC_CLK		0x04
#define GPIOD_CLK		0x08
#define GPIOE_CLK		0x10
#define GPIOF_CLK		0x20

//base addresses
#define GPIOA ((unsigned char*) 0x40004000)
#define GPIOB ((unsigned char*) 0x40005000)
#define GPIOC ((unsigned char*) 0x40006000)
#define GPIOD ((unsigned char*) 0x40007000)
#define GPIOE ((unsigned char*) 0x40024000)
#define GPIOF ((unsigned char*) 0x40025000)

void gpio_initDigital(unsigned char* baseAddr, unsigned char inMask, unsigned char outMask);
void gpio_initAF(unsigned char* baseAddr, unsigned char AF_Mask, unsigned int AF_PCTL);

#endif
