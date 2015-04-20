//Wi-Fi_driver.c

#include "Tasks/Wi-Fi_driver.h"

static unsigned int recvSize = 0;
static unsigned int sendSize = 0;

static char recvBuffer[MESSAGE_SIZE];
static char sendBuffer[MESSAGE_SIZE];

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
  recvSize = 0;
  recvBuffer[sendSize] = 0;

  while(recvSize < MESSAGE_SIZE-1)
    {
      UART_recv(recvBuffer, WIFI_BASE);
      recvSize = OS_strlen(recvBuffer);

      //newlines are represented by CR+LF
      //look for line feed at end of line
      if(recvBuffer[recvSize-1] == '\n')
	{
	  //UART_send(msgBuffer, CONSOLE_BASE);
	  if(OS_strcmp(resp, recvBuffer) == 0)
	    {
	      UART_send(recvBuffer, CONSOLE_BASE);
	      recvSize = 0;
	      recvBuffer[recvSize] = 0;
	      return true;

	    }

	  recvSize = 0;
	  recvBuffer[recvSize] = 0;

	}

    }

  recvSize = 0;
  recvBuffer[recvSize] = 0;

  return false;

}

//*****************************************************************************
//
// Send a string to the UART.
//
//*****************************************************************************
void WiFi_init()
{
  int i = 100;
  recvSize = 0;
  recvBuffer[recvSize] = 0;

  sendSize = 0;
  sendBuffer[sendSize] = 0;

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
  WiFiSendCommandWait("AT+CWMODE=1\r\n", "no change\r\n");

  OS_strcpy(sendBuffer, "AT+CWJAP=\"");
  OS_strcat(sendBuffer, WIFI_SSID);
  OS_strcat(sendBuffer, "\",\"");
  OS_strcat(sendBuffer, WIFI_PASS);
  OS_strcat(sendBuffer, "\"\r\n");
  WiFiSendCommandWait(sendBuffer, "OK\r\n");

  sendSize = 0;
  sendBuffer[sendSize] = 0;

  WiFiSendCommandWait("AT+CIPMUX=1\r\n", "OK\r\n");
  //WiFiSendCommandWait("AT+CIPSERVER=1,1336\r\n", "OK\r\n");
  
  OS_strcpy(sendBuffer, "AT+CIPSERVER=1,");
  OS_strcat(sendBuffer, WIFI_PORT);
  OS_strcat(sendBuffer, "\r\n");

  WiFiSendCommandWait(sendBuffer, "OK\r\n");

  sendSize = 0;
  sendBuffer[sendSize] = 0;  

}

void WiFi_run()
{
  int incomingPID;

  // grab MPI messages
  if(MPI_check_available(WIFI_DRIVER_PID) == true)
    {
      MPI_get_message(WIFI_DRIVER_PID, &incomingPID, &sendSize, sendBuffer);

      // send MPI message over UART
      if(sendSize > 0)
	{
	  UART_send(sendBuffer, WIFI_BASE);
	  UART_send(sendBuffer, CONSOLE_BASE);

	  sendSize = 0;
	  sendBuffer[sendSize] = 0;

	}

    }

  // grab incoming UART message
  UART_recv(recvBuffer, WIFI_BASE);

  // if '\n' detected, send string over MPI message
  recvSize = OS_strlen(recvBuffer);
 
  if(recvSize > 0 && recvBuffer[recvSize-1] == '\n')
    {
      MPI_send_message(WIFI_DRIVER_PID, WIFI_CONTROLLER_PID, recvSize+1, recvBuffer);
      UART_send(recvBuffer, CONSOLE_BASE);

      recvSize = 0;
      recvBuffer[recvSize] = 0;

    }


}

