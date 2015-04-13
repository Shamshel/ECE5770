//UART_driver.h

#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

#include "OS/Kernel.h"

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

#define UART_init function_UART_init
#define UART_run fuction_UART_run

extern void UART_init();
extern void UART_run();

#endif
