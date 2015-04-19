//UART_driver.h

#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include "OS/MPI.h"
#include "OS/hardware_drivers.h"

#define UART_recv function_UART_recv
#define UART_send function_UART_send

extern void UART_recv();
extern void UART_send();

#endif
