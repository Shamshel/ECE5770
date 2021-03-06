//OSLib.h

#ifndef OSLIB_H
#define OSLIB_H

#define OS_memcpy function_OS_memcpy

#include <stdbool.h>

//define boolean type
/*typedef int bool;
#define true 1
#define false 0*/

#define OS_memcpy function_OS_memcpy
#define OS_strcmp function_OS_strcmp
#define OS_strlen function_OS_strlen
#define OS_strcat function_OS_strcat
#define OS_strcpy function_OS_strcpy
#define OS_strstr function_OS_strstr

extern void OS_memcpy(void* destination, const void* source, unsigned int num);
extern int OS_strcmp(const char* str1, const char* str2);
extern int OS_strlen(const char* str);
extern void OS_strcat(char* destination, const char* source);
extern void OS_strcpy(char* destination, const char* source);
extern int OS_strstr(const char* str1, const char* str2);

#endif
