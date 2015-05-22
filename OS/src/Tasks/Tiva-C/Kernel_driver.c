//Kernel_driver.c

#include "Kernel_driver.h"

static uint32_t LED_state = 0;

void Kernel_init()
{
  // Set the clocking to run directly from the crystal.
  SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
		 SYSCTL_XTAL_16MHZ);
                                                                                
  // Enable the GPIO port that is used for the on-board LED.
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

  // Enable the GPIO pins for the LED (PF2).
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

}

void Kernel_task_complete()
{
  if(LED_state == GPIO_PIN_2)
    {
      LED_state = 0;

    }

  else
    {
      LED_state = GPIO_PIN_2;

    }

  // Blink the LED to show a character transfer is occuring.
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, LED_state);

}

