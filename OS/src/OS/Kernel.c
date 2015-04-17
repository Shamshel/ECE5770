//Kernel.c

//includes
//OS base
#include "OS/OS.h"

//hardware defines
#include "OS/hardware_drivers.h"

//tasks
#include "Tasks/UART_driver.h"

//this array determines the schedule that the system will run
static task_ptr_t schedule[NUM_TASKS];

static int num_tasks = 0;
static int current_task = 0;

void dummy_function()
{
  // Delay for 1 millisecond.  Each SysCtlDelay is about 3 clocks.
  SysCtlDelay(SysCtlClockGet() / 10 / 3);

}

int Kernel_register_function(task_ptr_t task)
{
  if(num_tasks == NUM_TASKS)
    {
      return E_KERNEL_TASK_OVERFLOW;

    }

  schedule[num_tasks] = task;
  num_tasks++;

  return OS_SUCCESS;

}

void Kernel_run()
{
  //control flags
  bool done = false;
  bool error = false;

  //message handling variables
  int srcPID;
  unsigned int size;
  int error_code;
  uint32_t LED_state = 0;

  // Setup gpio and clocking

  // Set the clocking to run directly from the crystal.
  ROM_SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
		     SYSCTL_XTAL_16MHZ);
                                                                                
  // Enable the GPIO port that is used for the on-board LED.
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

  // Enable the GPIO pins for the LED (PF2).
  ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

  //task inits
  UART_init();

  //Kernel_register_function(dummy_function);
  Kernel_register_function(UART_run);

  while(done == false)
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

      //execute next task
      if(num_tasks > 0)
	{
	  (*schedule[current_task])();

	}

      do
	{
	  //check for errors
	  error = MPI_check_available(OS_PID);

	  if(error == true)
	    {
	      //retrieve and handle errors
	      MPI_get_message(OS_PID, &srcPID, &size, &error_code);

	    }

	  //handle errors
	  if(size == sizeof(int))
	    {
	      switch(error_code)
		{
		case E_MPI_INVALID_SRC_PID:
		case E_MPI_INVALID_DST_PID:
		case E_MPI_OVERSIZED_MSG:
		case E_MPI_MAILBOX_BUF_OVERFLOW:
		case E_MPI_INVALID_RCV_PID:
		case E_MPI_NO_MSG_AVAILABLE:
		case E_KERNEL_TASK_OVERFLOW:
		  break;

		  //immediately terminate kernel execution
		case E_KERNEL_TERMINATE:
		  done = true;
		  error = false;

		  break;
		  
		}


	    }

	}while(error == true);

      current_task = (current_task+1)%num_tasks;

    }

}

