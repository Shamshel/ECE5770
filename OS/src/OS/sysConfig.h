//sysconfig.h

#ifndef SYSCONFIG_H
#define SYSCONFIG_H

//Task definitions and PID assignments
#define OS_PID 0
#define WIFI_DRIVER_PID 1
#define WIFI_CONTROLLER_PID 2
#define MOTOR_DRIVER_PID 3
#define MAIN_CONTROLLER_PID 4

//WiFi setup and configuration
#define WIFI_SSID "BLUEZONE"
#define WIFI_PASS ""
#define WIFI_PORT "8888"
#define MAX_INCOMING 10
#define CLOSE_CONN_DELAY 1000
#define MAC_ADDRESS "18:fe:34:9e:2c:8d"

//MPI configuration
#define MESSAGE_SIZE 128
#define MAILBOX_SIZE 10
#define MPI_SIZE 10 //must be no smaller than the largest PID

//Kernel configuration
#define NUM_TASKS 10 //must be no smaller than the number of tasks in the hyperperiod

#endif
