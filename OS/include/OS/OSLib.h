//OSLib.h

#ifndef OSLIB_H
#define OSLIB_H

#define OS_memcpy function_OS_memcpy

#include <stdbool.h>

//define boolean type
/*typedef int bool;
#define true 1
#define false 0*/

extern void OS_memcpy(void* destination, const void* source, unsigned int num);

#endif
