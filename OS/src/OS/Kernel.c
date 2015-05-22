//Kernel.c

//includes
//OS base
#include "OS/OS.h"

//Kernel external functions (hardware dependent)
#include "Tasks/Kernel_driver.h"

//hardware defines
#include "OS/hardware_drivers.h"

//tasks
#include "Tasks/Wi-Fi_driver.h"
#include "Tasks/Wi-Fi_controller.h"
#include "Tasks/Motor_driver.h"

//this array determines the schedule that the system will run
static task_ptr_t schedule[NUM_TASKS];

static int num_tasks = 0;
static int current_task = 0;

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

  // Setup gpio and clocking
  Kernel_init();

  //task inits
  WiFi_init();
  WiFi_controller_init();
  Motor_init();

  //Kernel_register_function(dummy_function);
  Kernel_register_function(WiFi_run);
  Kernel_register_function(WiFi_controller_run);
  Kernel_register_function(Motor_run);

  while(done == false)
    {
      Kernel_task_complete();
      
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

