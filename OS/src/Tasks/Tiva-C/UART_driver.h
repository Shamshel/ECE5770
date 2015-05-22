//UART_driver.h

#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include "OS/MPI.h"
#include "OS/Tiva-C/hardware_drivers.h"

#define CONSOLE_BASE UART1_BASE
#define WIFI_BASE UART7_BASE

#define UART_recv function_UART_recv
#define UART_send function_UART_send

extern void UART_recv(char* msg, uint32_t base);
extern void UART_send(const char* msg, uint32_t base);

#endif
