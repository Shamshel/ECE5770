//sysconfig.h

#ifndef SYSCONFIG_H
#define SYSCONFIG_H

//Task definitions and PID assignments
#define OS_PID 0

//MPI configuration
#define MESSAGE_SIZE 128
#define MAILBOX_SIZE 10
#define MPI_SIZE 10 //must be no smaller than the largest PID

//Kernel configuration
#define NUM_TASKS 10 //must be no smaller than the number of tasks in the hyperperiod


#endif
