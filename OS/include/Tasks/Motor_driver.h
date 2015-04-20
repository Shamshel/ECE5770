//Motor_driver.h

#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "OS/OS.h"
#include "OS/hardware_drivers.h"

#include "Tasks/UART_driver.h"

#define PORT_BASE GPIO_PORTA_BASE

#define PWM_LEFT GPIO_PIN_2
#define PWM_RIGHT GPIO_PIN_3
#define CTRL1_LEFT GPIO_PIN_4
#define CTRL2_LEFT GPIO_PIN_5
#define CTRL1_RIGHT GPIO_PIN_6
#define CTRL2_RIGHT GPIO_PIN_7

#define Motor_init function_Motor_init
#define Motor_run function_Motor_run

extern void Motor_init();
extern void Motor_run();

#endif

