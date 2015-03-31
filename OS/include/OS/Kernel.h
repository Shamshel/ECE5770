//Kernel.h

#ifndef KERNEL_H
#define KERNEL_H

#include "OS/OS.h"
#include "OS/MPI.h"

//defines a "task_ptr_t" for functions of the form "void foo()"
typedef void (*task_ptr_t)();

#define Kernel_run function_Kernel_run
#define Kernel_register_function function_Kernel_register_function

extern void Kernel_run();
extern int Kernel_register_function(task_ptr_t task);

#endif

