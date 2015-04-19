//Wi-Fi_driver.c

#include "OS/OS.h"
#include "Tasks/UART_driver.h"
#include "Tasks/Wi-Fi_driver.h"

static unsigned int bufSize = 0;
static char msgBuffer[MESSAGE_SIZE];

//*****************************************************************************
//
// Send a command to the WiFi board, do not wait for response (reduce blocking overhead)
//
//*****************************************************************************

void WiFiSendCommand(const char* cmd)
{
  UART_send(cmd, WIFI_BASE);
  UART_send(cmd, CONSOLE_BASE);

}

//*****************************************************************************
//
// Send a command to the WiFi board, wait for response
//
//*****************************************************************************

bool WiFiSendCommandWait(const char* cmd, const char* resp)
{
  UART_send(cmd, WIFI_BASE);
  UART_send(cmd, CONSOLE_BASE);
 
  //reset buffer
  bufSize = 0;
  msgBuffer[bufSize] = 0;
 
  while(bufSize < MESSAGE_SIZE-1)
    {
      UART_recv(msgBuffer, WIFI_BASE);

      bufSize = OS_strlen(msgBuffer);

      //newlines are represented by CR+LF
      //look for line feed at end of line
      if(msgBuffer[bufSize-1] == '\n')
	{
	  //UART_send(msgBuffer, CONSOLE_BASE);

	  if(OS_strcmp(resp, msgBuffer) == 0)
	    {
	      UART_send(msgBuffer, CONSOLE_BASE);

	      bufSize = 0;
	      msgBuffer[bufSize] = 0;
	  
	      return true;

	    }

	  bufSize = 0;
	  msgBuffer[bufSize] = 0;
	  
	}

    }
	  
  bufSize = 0;
  msgBuffer[bufSize] = 0;

  return false;

}

//*****************************************************************************
//
// Echo input from the WiFi.
//
//*****************************************************************************
/*
void WiFiEcho()
{
  while(UARTCharsAvail(WIFI_BASE) && recvSize < MESSAGE_SIZE)
    {
      recvBuffer[recvSize] = UARTCharGetNonBlocking(WIFI_BASE);
      recvSize++;

    }

  while(recvSize > 0)
    {
      recvSize--;
      
      UARTCharPutNonBlocking(CONSOLE_BASE, recvBuffer[recvSize]);

    }

}
*/
//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
void WiFi_init()
{
  int i = 100;
  bufSize = 0;
  msgBuffer[bufSize] = 0;

  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

  //delay to avoid bus errors
  while(i > 0)
    {
      i--;

    }

  GPIOPinConfigure(GPIO_PE0_U7RX);
  GPIOPinConfigure(GPIO_PE1_U7TX);
  GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1);
  
  GPIOPinConfigure(GPIO_PB0_U1RX);
  GPIOPinConfigure(GPIO_PB1_U1TX);
  GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);  
  

  UARTConfigSetExpClk(WIFI_BASE, SysCtlClockGet(), 9600,
			  (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
			   UART_CONFIG_PAR_NONE));
  
  UARTConfigSetExpClk(CONSOLE_BASE, SysCtlClockGet(), 9600,
			  (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
			  UART_CONFIG_PAR_NONE));

  UARTFIFOEnable(WIFI_BASE);
  UARTFIFOEnable(CONSOLE_BASE);

  UARTEnable(WIFI_BASE);
  UARTEnable(CONSOLE_BASE);

  //initialize WiFi module
  WiFiSendCommandWait("AT+RST\r\n", "ready\r\n");
  WiFiSendCommandWait("AT+CWMODE=2\r\n", "no change\r\n");
  WiFiSendCommandWait("AT+CIFSR\r\n", "OK\r\n");
  WiFiSendCommandWait("AT+CIPMUX=1\r\n", "OK\r\n");
  WiFiSendCommandWait("AT+CIPSERVER=1,80\r\n", "OK\r\n");

  bufSize = 0;
  msgBuffer[bufSize] = 0;

}

void WiFi_run()
{

  //test program
  //echos incoming characters back out on the same interface
  UART_recv(msgBuffer, WIFI_BASE);

  bufSize = OS_strlen(msgBuffer);

  //newlines are represented by CR+LF (\r\n)
  if(bufSize > 0 && msgBuffer[bufSize-1] == '\n')
    {
      UART_send(msgBuffer, CONSOLE_BASE);

      bufSize = 0;
      msgBuffer[bufSize] = 0;
      
    }

  //end test program

  // grab MPI messages
  

  // send MPI message over UART
  

  // grab incoming UART message


  // if '\n' detected, send string over MPI message


}
