//UART_driver.c

#include "OS/OSLib.h"
#include "Tasks/UART_driver.h"

static unsigned int sendSize;
static unsigned char sendBuffer[MESSAGE_SIZE];

static unsigned int recvSize;
static unsigned char recvBuffer[MESSAGE_SIZE];

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
      UARTCharPutNonBlocking(UART0_BASE, sendBuffer[i]);
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
  int i;

  while(UARTCharsAvail(UART0_BASE))
    {
      recvBuffer[recvSize] = UARTCharGet(UART0_BASE);
      recvSize++;

    }

  while(recvSize > 0)
    {
      UARTCharPut(UART0_BASE, recvBuffer[recvSize-1]);

      recvSize--;

    }

}

//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
void UART_init()
{
  sendSize = 0;
  recvSize = 0;

  //
  // Enable the peripherals used by this example.
  //
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

  //
  // Set GPIO A0 and A1 as UART pins.
  //
  GPIOPinConfigure(GPIO_PA0_U0RX);
  GPIOPinConfigure(GPIO_PA1_U0TX);
  GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

  //
  // Configure the UART for 115,200, 8-N-1 operation.
  //
  UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 38400,
			  (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
			   UART_CONFIG_PAR_NONE));

  UARTFIFOEnable(UART0_BASE);

  UARTEnable(UART0_BASE);

}

void UART_run()
{

  //test program
  //echos incoming characters back out on the same interface

  UARTEcho();

  //end test program

  // grab MPI messages
  

  // send MPI message over UART
  

  // grab incoming UART message


  // if '\n' detected, send string over MPI message


}

