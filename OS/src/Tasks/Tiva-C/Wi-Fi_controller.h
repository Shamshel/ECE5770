//Wi-Fi_controller.h


#ifndef WI_FI_CONTROLLER_H
#define WI_FI_CONTROLLER_H

#include "OS/OS.h"
#include "Tasks/Tiva-C/UART_driver.h"

#define WiFi_controller_init function_WiFi_controller_init
#define Wifi_controller_run function_WiFi_controller_run

extern void WiFi_controller_init();
extern void WiFi_controller_run();

#endif
