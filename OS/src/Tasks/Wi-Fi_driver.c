//Wi-Fi_driver.c

#include "OS/OS.h"
#include "Tasks/Wi-Fi_driver.h"

static unsigned int sendSize;
static unsigned char sendBuffer[MESSAGE_SIZE];

static unsigned int recvSize;
static unsigned char recvBuffer[MESSAGE_SIZE];

//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
void WiFiSend()
{
  int i;

  for(i = 0; i<sendSize; i++)
    {
      //
      // Write the next character to the UART.
      //
      UARTCharPutNonBlocking(UART2_BASE, sendBuffer[i]);
    }

  sendSize = 0;

}

void UARTReceive()
{
  while(UARTCharsAvail(UART2_BASE) && recvSize < MESSAGE_SIZE)
    {
      recvBuffer[recvSize] = UARTCharGet(UART2_BASE);
      recvSize++;

    }

  //check for newline or max message size
  if(recvBuffer[recvSize-1] == 0x0A || recvSize == MESSAGE_SIZE)
    {
      OS_memcpy(sendBuffer, recvBuffer, recvSize);
      WiFiSend();

    }

}

//*****************************************************************************
//
// Echo input from the UART.
//
//*****************************************************************************
void WiFiEcho()
{
  while(UARTCharsAvail(UART2_BASE) && recvSize < MESSAGE_SIZE)
    {
      recvBuffer[recvSize] = UARTCharGetNonBlocking(UART2_BASE);
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
void WiFi_init()
{
  sendSize = 0;
  recvSize = 0;

  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

  GPIOPinConfigure(GPIO_PD6_U2RX);
  GPIOPinConfigure(GPIO_PD7_U2TX);
  GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);

  GPIOPinConfigure(GPIO_PB0_U1RX);
  GPIOPinConfigure(GPIO_PB1_U1TX);
  GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);  

  UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), 9600,
			  (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
			   UART_CONFIG_PAR_NONE));

  UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 9600,
			  (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
			   UART_CONFIG_PAR_NONE));

  UARTFIFOEnable(UART2_BASE);
  UARTFIFOEnable(UART1_BASE);

  UARTEnable(UART2_BASE);
  UARTEnable(UART1_BASE);

}

void WiFi_run()
{

  //test program
  //echos incoming characters back out on the same interface

  //UARTReceive();
  WiFiEcho();

  //end test program

  // grab MPI messages
  

  // send MPI message over UART
  

  // grab incoming UART message


  // if '\n' detected, send string over MPI message


}
