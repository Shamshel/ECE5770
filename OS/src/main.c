#include "OS/OS.h"

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"

int main(int argc, char** argv)
{

  //                                                                                                                                   
  // Set the clocking to run directly from the crystal.                                                                                
  //                                                                                                                                   
  ROM_SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
		     SYSCTL_XTAL_16MHZ);
  //                                                                                                                                   
  // Enable the GPIO port that is used for the on-board LED.                                                                           
  //                                                                                                                                   
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

  //                                                                                                                                   
  // Enable the GPIO pins for the LED (PF2).                                                                                           
  //                                                                                                                                   
  ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);


  while(1)
    {
      //                                                                                                                               
      // Blink the LED to show a character transfer is occuring.                                                                       
      //                                                                                                                               
      GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);

      //                                                                                                                               
      // Delay for 1 millisecond.  Each SysCtlDelay is about 3 clocks.                                                                 
      //                                                                                                                               
      SysCtlDelay(SysCtlClockGet() / 10 / 3);

      //                                                                                                                               
      // Turn off the LED                                                                                                              
      //                                                                                                                               
      GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);

      SysCtlDelay(SysCtlClockGet() / 10 / 3);

    }

  return 1;
}
