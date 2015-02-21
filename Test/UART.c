//UART.c

/*
 * Written by Cody Herndon
 */
 
 #include "UART.h"
 
 void wait_for_TX_empty(unsigned char* baseaddr)
 {
	 while((readReg(baseaddr, UARTFR) & 0x80) == 0x00);
	 
 }

void uart_init0()
{
	//disable UART
	andWriteReg(UART0, UARTCTL, 0xFFFFFFFE);
	
	//1. enable RCGCUART (pg 342)
	sysctl_enableRCGC(RCGCUART, 0x01);
	
	//2. enable RCGCGPIO (pg 338, table on pg 892)
	//	UART0 on port A
	sysctl_enableRCGC(RCGCGPIO, 0x01);
	
	//3. set GPIO AFSEL (pg 668)
	//5. configure PMCn in GPIOCTL (pg 685 and pg 1344)
	//	UART0 on pin 0:1
	gpio_initAF(GPIOA, 0x3, 0x11);
	
	//4. configure GPIO slew rate
	//GPIODR2R will work
	
	//enable digital pins
	orWriteReg(GPIOA, GPIODEN, 0x03);
	
	//setup for 9600 baud
	//set the baud rate divisor: BRD = SysClk/(16*baudrate) = 16MHz/(16*9600) = 104.1666667
	//IBRD = 104 = 0x68
	//FBRD = 11 = 0x0B
	writeReg(UART0, UARTIBRD, 0x68);
	writeReg(UART0, UARTFBRD, 0x0B);
	
	//set uart word length of 8 bits
	writeReg(UART0, UARTLCRH, 0x60);
	
	//enable uart0
	orWriteReg(UART0, UARTCTL, 0x01);
	
}

int uart_send(unsigned char* baseaddr, char* msg)
{
	int result = 0;
	
	int index = 0;
	
	while(msg[index] != 0)
	{
		writeReg(baseaddr, UARTDR, msg[index]);
		
		wait_for_TX_empty(baseaddr);
		
		index++;
		result++;
		
	}
	
	return result;
	
}

int uart_recv(unsigned char* baseaddr, char* msg)
{
	int result = 0;
	
	
	return result;
	
}

int uart_send0(char* msg)
{
	int result = 0;
	
	
	return result;
	
}

int uart_recv0(char* msg)
{
	int result = 0;
	
	
	return result;
	
}
