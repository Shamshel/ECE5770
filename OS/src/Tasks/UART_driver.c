//UART_driver.c

#include "OS/OSLib.h"
#include "Tasks/UART_driver.h"

//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
void UART_send(const char* msg, uint32_t base)
{
  int i = 0;

  while(msg[i] != 0)
    {
      UARTCharPut(base, msg[i]);

      i++;

    }

}

void UART_recv(char* buf, uint32_t base)
{
  int len;

  if(UARTCharsAvail(base))
    {
      len = OS_strlen(buf);

      buf[len] = UARTCharGet(base);
      buf[len+1] = 0;

    }

}

//*****************************************************************************
//
// Echo input from the UART.
//
//*****************************************************************************
/*
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
*/
//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
/*
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
*/
