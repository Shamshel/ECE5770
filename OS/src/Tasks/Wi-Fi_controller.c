//Wi-Fi_controller.c

#include "Tasks/Wi-Fi_controller.h"
#include "Tasks/Wi-Fi_driver.h"

static unsigned int bufSize = 0;
static char msgBuffer[MESSAGE_SIZE];

static char incomingConnection;
static unsigned int incomingBytes;
static unsigned int bytesRecvd;
static bool connectionOpen = false;

void WiFi_controller_init()
{
  //inits currently all handled by driver code
  

}

void WiFi_controller_run()
{
  int incomingPID;
  int index;
  int pinNum;

  if(MPI_check_available(WIFI_CONTROLLER_PID) == true)
    {
      MPI_get_message(WIFI_CONTROLLER_PID, &incomingPID, &bufSize, msgBuffer);

      if(connectionOpen == true)
	{
	  //add received bytes to count
	  bytesRecvd += OS_strlen(msgBuffer);

	  //wait for "OK\r\n"
	  if(OS_strcmp(msgBuffer, "OK\r\n"))
	    {
	      OS_strcpy(msgBuffer, "AT+CIPCLOSE=");
	      bufSize = OS_strlen(msgBuffer);

	      msgBuffer[bufSize] = incomingConnection;
	      bufSize++;

	      msgBuffer[bufSize] = '\r';
	      bufSize++;
	      msgBuffer[bufSize] = '\n';
	      bufSize++;
	      msgBuffer[bufSize] = 0;

	      MPI_send_message(WIFI_CONTROLLER_PID, WIFI_DRIVER_PID, bufSize+1, msgBuffer);

	      bytesRecvd = 0;
	      incomingBytes = 0;
	      connectionOpen = false;
	      bufSize = 0;
	      msgBuffer[bufSize] = 0;

	    }

	}

      else
	{
	  //check if incoming message is post
	  index = OS_strstr(msgBuffer, "+IPD,");

	  //check http://allaboutee.com/2015/01/02/esp8266-arduino-led-control-from-webpage/
	  if(index != -1)
	    {
	      //seek to character after "+IPD,"
	      index += 5;
	      incomingConnection = msgBuffer[index];

	      //seek to character after "x,"
	      index += 2;

	      //get the number of incoming bytes (assume its in the triple digits)
	      incomingBytes = (msgBuffer[index]-48)*100;
	      UART_send(&msgBuffer[index], CONSOLE_BASE);
	      index++;
	      incomingBytes += (msgBuffer[index]-48)*10;
	      index++;
	      incomingBytes += msgBuffer[index]-48;

	      index = OS_strstr(msgBuffer, "pin=");

	      //seek to end of "pin="
	      index += 4;

	      //get 10's digit
	      pinNum = 10*(msgBuffer[index]-48);

	      index++;
	      pinNum += msgBuffer[index]-48;

	      connectionOpen = true;
	  
	  
	      //add the number of characters in the current string
	      bytesRecvd = OS_strlen(&msgBuffer[5]);

	    }

	}
      

    }

}

