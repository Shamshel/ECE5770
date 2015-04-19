//Memory.c

#include "OS/OS.h"
#include "OS/OSLib.h"

void OS_memcpy(void* destination, const void* source, unsigned int num)
{
  unsigned int i;

  //transfer byte by byte
  char* src = (char *)source;
  char* dest = (char *)destination;

  for(i = 0; i < num; i++)
    {
      dest[i] = src[i];

    }

}

int OS_strcmp(const char* str1, const char* str2)
{
  int i = 0;

  while(str1[i] != 0 && str2[i] != 0)
    {
      if(str1[i] < str2[i])
	{
	  return -1;

	}

      if(str1[i] > str2[i])
	{
	  return 1;

	}

      i++;

    }

  return 0;

}

int OS_strlen(const char* str)
{
  int i = 0;

  while(i < MESSAGE_SIZE-1 && str[i] != 0)
    {
      i++;

    }

  return i;

}

void OS_strcpy(char* destination, const char* source)
{
  int len = OS_strlen(source);

  OS_memcpy(destination, source, len+1);

}
