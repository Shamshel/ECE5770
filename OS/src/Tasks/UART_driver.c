//UART_driver.c

#include "Tasks/UART_driver.h"

static unsigned int sendSize;
static char sendBuffer[MESSAGE_SIZE];

static unsigned int recvSize;
static char recvBuffer[MESSAGE_SIZE];

//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
void UARTInit()
{
  sendSize = 0;
  recvSize = 0;

  //
  // Set the clocking to run directly from the crystal.
  //
  ROM_SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
		     SYSCTL_XTAL_16MHZ);

  //
  // Enable the peripherals used by this example.
  //
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

  //
  // Set GPIO A0 and A1 as UART pins.
  //
  GPIOPinConfigure(GPIO_PA0_U0RX);
  GPIOPinConfigure(GPIO_PA1_U0TX);
  ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

  //
  // Configure the UART for 115,200, 8-N-1 operation.
  //
  ROM_UARTConfigSetExpClk(UART0_BASE, ROM_SysCtlClockGet(), 115200,
			  (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
			   UART_CONFIG_PAR_NONE));

}

void UARTRun()
{

  // grab MPI messages


  // send MPI message over UART

  // grab incoming UART message

  // if '\n' detected, send string over MPI message

}

//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
void UARTSend()
{
  int i;

  for(i = 0; i<sendSize; i++)
    {
      //
      // Write the next character to the UART.
      //
      ROM_UARTCharPutNonBlocking(UART0_BASE, sendBuffer[i]);
    }

  sendSize = 0;

}

void UARTReceive()
{
  

}

//*****************************************************************************
//
// Echo input from the UART.
//
//*****************************************************************************
void UARTEcho()
{
  while(ROM_UARTCharsAvail(UART0_BASE))
    {
      //
      // Read the next character from the UART and write it back to the UART.
      //
      ROM_UARTCharPutNonBlocking(UART0_BASE,
				 ROM_UARTCharGetNonBlocking(UART0_BASE));


    }

}

void UART_init()
{
  UARTInit();

}

void UART_run()
{
  //echo input from UART module
  while(1)
    {
      UARTEcho();

    }

}
