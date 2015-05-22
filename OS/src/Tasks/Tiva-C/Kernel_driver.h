//Kernel_driver.h

#ifndef KERNEL_DRIVER_H
#define KERNEL_DRIVER_H

#include "OS/OS.h"
#include "OS/Tiva-C/hardware_drivers.h"

#include "Tasks/Tiva-C/UART_driver.h"

#define Kernel_init function_Kernel_init
#define Kernel_task_complete function_Kernel_task_complete

extern void Kernel_init();
extern void Kernel_task_complete();

#endif
