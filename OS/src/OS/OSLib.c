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

void OS_strcat(char* destination, const char* source)
{
  int lenDest = OS_strlen(destination);
  int lenSource = OS_strlen(source);
  int i = 0;

  while(i+lenDest < MESSAGE_SIZE-1 && i < lenSource)
    {
      destination[i+lenDest]=source[i];

      i++;

    }

  destination[i+lenDest] = 0;

}

void OS_strcpy(char* destination, const char* source)
{
  int len = OS_strlen(source);

  OS_memcpy(destination, source, len+1);

}

int OS_strstr(const char* str1, const char* str2)
{
  int i;
  int j;
  int offset = -1;
  int str1Len = OS_strlen(str1);
  int str2Len = OS_strlen(str2);

  if(str2Len > str1Len)
    {
      //printf("str2 > str1\n");

      return -1;

    }

  for(i = 0; i < str1Len; i++)
    {
      for(j = 0; j < str2Len; j++)
	{
	  if(i+j == str1Len)
	    {
	      //printf("i+j > str1Len\n");
	      return -1;

	    }

	  if(str1[i+j] == str2[j] && offset == -1)
	    {
	      offset = i;

	    }

	  else if(str1[i+j] != str2[j])
	    {
	      //printf("mismatch!\n");
	      offset = -1;
	      break;

	    }

	}

      if(offset != -1)
	{
	  return offset;
	  
	}

    }

  return offset;

}
