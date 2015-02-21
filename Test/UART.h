//UART.h

/*
 * Written by Cody Herndon
 */
 
#include "regop.h"
#include "SYSCTL.h"
#include "GPIO.h"
 
#ifndef UART_H
#define UART_H
 
 
#define UART0 ((unsigned char*)0x4000C000)
#define UART1 ((unsigned char*)0x4000D000)
#define UART2 ((unsigned char*)0x4000E000)
#define UART3 ((unsigned char*)0x4000F000)
#define UART4 ((unsigned char*)0x40000000)
#define UART5 ((unsigned char*)0x40001000)
#define UART6 ((unsigned char*)0x40002000)
#define UART7 ((unsigned char*)0x40003000)
 
#define UARTDR		0x0000
#define UARTRSR		0x0004
#define UARTFR		0x0018
#define UARTIBRD 	0x0024
#define UARTFBRD 	0x0028
#define UARTLCRH 	0x002C
#define UARTCTL		0x0030
#define UARTIFLS	0x0034
#define UARTIM		0x0038
#define UARTRIS		0x003C
#define UARTMIS		0x0040
#define UARTICR		0x0044
#define UARTDMACTL	0x0048
#define UARTCC		0x0FC8

void uart_init0(void);
void uart_init1(void);
void uart_init2(void);
void uart_init3(void);
void uart_init4(void);
void uart_init5(void);
void uart_init6(void);
void uart_init7(void);

int uart_send0(char* msg);
int uart_send1(char* msg);
int uart_send2(char* msg);
int uart_send3(char* msg);
int uart_send4(char* msg);
int uart_send5(char* msg);
int uart_send6(char* msg);
int uart_send7(char* msg);
 
int uart_recv0(char* msg);
int uart_recv1(char* msg);
int uart_recv2(char* msg);
int uart_recv3(char* msg);
int uart_recv4(char* msg);
int uart_recv5(char* msg);
int uart_recv6(char* msg);
int uart_recv7(char* msg);
 
#endif
