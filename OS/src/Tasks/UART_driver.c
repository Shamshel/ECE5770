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
      UARTCharPutNonBlocking(UART1_BASE, sendBuffer[i]);
    }

  sendSize = 0;

}

void UARTReceive()
{
  while(UARTCharsAvail(UART1_BASE) && recvSize < MESSAGE_SIZE)
    {
      recvBuffer[recvSize] = UARTCharGet(UART1_BASE);
      recvSize++;

    }

  //check for newline or max message size
  if(recvBuffer[recvSize-1] == 0x0A || recvSize == MESSAGE_SIZE)
    {
      OS_memcpy(sendBuffer, recvBuffer, recvSize);
      UARTSend();

    }

}

//*****************************************************************************
//
// Echo input from the UART.
//
//*****************************************************************************
void UARTEcho()
{
  while(UARTCharsAvail(UART1_BASE) && recvSize < MESSAGE_SIZE)
    {
      recvBuffer[recvSize] = UARTCharGetNonBlocking(UART1_BASE);
      recvSize++;

    }

  while(recvSize > 0)
    {
      recvSize--;
      
      UARTCharPutNonBlocking(UART1_BASE, recvBuffer[recvSize]);

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
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

  //
  // Set GPIO A0 and A1 as UART pins.
  //
  GPIOPinConfigure(GPIO_PB0_U1RX);
  GPIOPinConfigure(GPIO_PB1_U1TX);
  GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);

  UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 9600,
			  (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
			   UART_CONFIG_PAR_NONE));

  UARTFIFOEnable(UART1_BASE);

  UARTEnable(UART1_BASE);

}

void UART_run()
{

  //test program
  //echos incoming characters back out on the same interface

  //UARTReceive();
  UARTEcho();

  //end test program

  // grab MPI messages
  

  // send MPI message over UART
  

  // grab incoming UART message


  // if '\n' detected, send string over MPI message


}

