//Wi-Fi_driver.h

#ifndef WI_FI_DRIVER_H
#define WI_FI_DRIVER_H

#include "OS/OS.h"
#include "OS/hardware_drivers.h"
#include "Tasks/UART_driver.h"

#define WiFi_init function_WiFi_init
#define WiFi_run fuction_WiFi_run

extern void WiFi_init();
extern void WiFi_run();

#endif
