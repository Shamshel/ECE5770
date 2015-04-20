//Motor_driver.c

#include "Tasks/Motor_driver.h"

static int cmdSize;
static char incomingMsg[MESSAGE_SIZE];
static int incomingCmd;
static int incomingPID;

void driveForward()
{
  GPIOPinWrite(PORT_BASE, PWM_LEFT, PWM_LEFT);
  GPIOPinWrite(PORT_BASE, PWM_RIGHT, PWM_RIGHT);

  GPIOPinWrite(PORT_BASE, CTRL1_LEFT, CTRL1_LEFT);
  GPIOPinWrite(PORT_BASE, CTRL2_LEFT, 0);

  GPIOPinWrite(PORT_BASE, CTRL1_RIGHT, CTRL1_RIGHT);
  GPIOPinWrite(PORT_BASE, CTRL2_RIGHT, 0);

}

void driveReverse()
{
  GPIOPinWrite(PORT_BASE, PWM_LEFT, PWM_LEFT);
  GPIOPinWrite(PORT_BASE, PWM_RIGHT, PWM_RIGHT);

  GPIOPinWrite(PORT_BASE, CTRL1_LEFT, 0);
  GPIOPinWrite(PORT_BASE, CTRL2_LEFT, CTRL2_LEFT);

  GPIOPinWrite(PORT_BASE, CTRL1_RIGHT, 0);
  GPIOPinWrite(PORT_BASE, CTRL2_RIGHT, CTRL2_RIGHT);

}

void driveLeft()
{
  GPIOPinWrite(PORT_BASE, PWM_LEFT, PWM_LEFT);
  GPIOPinWrite(PORT_BASE, PWM_RIGHT, PWM_RIGHT);

  GPIOPinWrite(PORT_BASE, CTRL1_LEFT, CTRL1_LEFT);
  GPIOPinWrite(PORT_BASE, CTRL2_LEFT, 0);

  GPIOPinWrite(PORT_BASE, CTRL1_RIGHT, 0);
  GPIOPinWrite(PORT_BASE, CTRL2_RIGHT, CTRL2_RIGHT);

}

void driveRight()
{
  GPIOPinWrite(PORT_BASE, PWM_LEFT, PWM_LEFT);
  GPIOPinWrite(PORT_BASE, PWM_RIGHT, PWM_RIGHT);

  GPIOPinWrite(PORT_BASE, CTRL1_LEFT, 0);
  GPIOPinWrite(PORT_BASE, CTRL2_LEFT, CTRL2_LEFT);

  GPIOPinWrite(PORT_BASE, CTRL1_RIGHT, 0);
  GPIOPinWrite(PORT_BASE, CTRL2_RIGHT, CTRL2_RIGHT);

}

void driveHalt()
{
  GPIOPinWrite(PORT_BASE, PWM_LEFT, 0);
  GPIOPinWrite(PORT_BASE, PWM_RIGHT, 0);

  GPIOPinWrite(PORT_BASE, CTRL1_LEFT, CTRL1_LEFT);
  GPIOPinWrite(PORT_BASE, CTRL2_LEFT, CTRL2_LEFT);

  GPIOPinWrite(PORT_BASE, CTRL1_RIGHT, CTRL1_RIGHT);
  GPIOPinWrite(PORT_BASE, CTRL2_RIGHT, CTRL2_RIGHT);

}

void Motor_init()
{
  int i = 100;
  
  cmdSize = 0;
  incomingMsg[cmdSize] = 0;

  // Enable the GPIO port(s)
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

  // Enable the GPIO pins
  GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);

  while(i > 0)
    {
      i--;

    }

}

void Motor_run()
{
  if(MPI_check_available(MOTOR_DRIVER_PID) == true)
    {
      MPI_get_message(MOTOR_DRIVER_PID, &incomingPID, &cmdSize, incomingMsg);

      if(cmdSize == sizeof(int))
	{
	  OS_memcpy(&incomingCmd, incomingMsg, cmdSize);

	  switch(incomingCmd)
	    {
	    case C_DRIVE_FORWARD:
	      driveForward();

	      break;

	    case C_DRIVE_REVERSE:
	      driveReverse();

	      break;

	    case C_DRIVE_LEFT:
	      driveLeft();
	      
	      break;

	    case C_DRIVE_RIGHT:
	      driveRight();

	      break;

	    case C_DRIVE_HALT:
	      driveHalt();

	      break;

	    }

	}

    }

}

