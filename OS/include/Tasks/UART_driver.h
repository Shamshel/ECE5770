//UART_driver.h

#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include "OS/MPI.h"
#include "OS/hardware_drivers.h"

#define UART_init function_UART_init
#define UART_run fuction_UART_run

extern void UART_init();
extern void UART_run();

#endif
