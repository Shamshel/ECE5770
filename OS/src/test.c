//test.c

#include "OS/OS.h"
#include "OS/MPI.h"
#include "OS/Kernel.h"

#include "stdio.h"
#include "CUnit/Basic.h"

static int global = 0;

/*
 *
 * test functions
 *
 */

void test_OSLib()
{
  int size = 36;
    int i;
  //test memcpy
  char sourceStr[] = "abcdefghijklmnopqrstuvwxyz1234567890";
  char destStr[100];

  OS_memcpy(destStr, sourceStr, size);

  for(i = 0; i < size; i++)
    {
      CU_ASSERT(sourceStr[i] == destStr[i]);

    }

}

void test_MPI()
{
  int i;
  int rcode;
  int testPID = 1;

  unsigned int size = 36;
  char sourceStr[] = "abcdefghijklmnopqrstuvwxyz1234567890";

  unsigned int rcvSize = -1;
  int rcvPID = -1;
  char destStr[100];

  MPI_initialize();

  //test general MPI functionality
  CU_ASSERT(MPI_check_available(OS_PID) == false);

  //int PID_src, int PID_dst, unsigned int size, void* data
  rcode = MPI_send_message(testPID, OS_PID, size, sourceStr);

  if(rcode != OS_SUCCESS)
    {
      printf("send failed with code: %d", rcode);

    }

  CU_ASSERT(MPI_check_available(OS_PID) == true);
  
  //int PID, int* PID_src, unsigned int* size, void* data
  rcode = MPI_get_message(OS_PID, &rcvPID, &rcvSize, &destStr);

  if(rcode != OS_SUCCESS)
    {
      printf("send failed with code: %d", rcode);

    }

  CU_ASSERT(rcvSize == size);
  CU_ASSERT(rcvPID == testPID);

  for(i = 0; i < size; i++)
    {
      CU_ASSERT(sourceStr[i] == destStr[i]);

    }

  CU_ASSERT(MPI_check_available(OS_PID) == false);

  //test MPI error reporting

  //int PID_src, int err
  MPI_send_error(testPID, OS_SUCCESS);

  CU_ASSERT(MPI_check_available(OS_PID) == true);

  MPI_get_message(OS_PID, &rcvPID, &rcvSize, &rcode);

  CU_ASSERT(rcvPID == testPID);
  CU_ASSERT(rcvSize == sizeof(int));
  CU_ASSERT(rcode == OS_SUCCESS);

  CU_ASSERT(MPI_check_available(OS_PID) == false);

  //test various send error handlers
  //test invalid source PID
  rcode = MPI_send_message(MPI_SIZE, OS_PID, size, sourceStr);

  CU_ASSERT(rcode == E_MPI_INVALID_SRC_PID);

  CU_ASSERT(MPI_check_available(OS_PID) == true);

  MPI_get_message(OS_PID, &rcvPID, &rcvSize, &rcode);

  CU_ASSERT(rcvPID == OS_PID);
  CU_ASSERT(rcvSize == sizeof(int));
  CU_ASSERT(rcode == E_MPI_INVALID_SRC_PID);

  CU_ASSERT(MPI_check_available(OS_PID) == false);

  //test invalid destination PID
  rcode = MPI_send_message(testPID, MPI_SIZE, size, sourceStr);

  CU_ASSERT(rcode == E_MPI_INVALID_DST_PID);

  CU_ASSERT(MPI_check_available(OS_PID) == true);

  MPI_get_message(OS_PID, &rcvPID, &rcvSize, &rcode);

  CU_ASSERT(rcvPID == testPID);
  CU_ASSERT(rcvSize == sizeof(int));
  CU_ASSERT(rcode == E_MPI_INVALID_DST_PID);

  CU_ASSERT(MPI_check_available(OS_PID) == false);

  //test oversize message
  rcode = MPI_send_message(testPID, OS_PID, MESSAGE_SIZE+1, sourceStr);

  CU_ASSERT(rcode == E_MPI_OVERSIZED_MSG);

  CU_ASSERT(MPI_check_available(OS_PID) == true);  

  MPI_get_message(OS_PID, &rcvPID, &rcvSize, &rcode);

  CU_ASSERT(rcvPID == testPID);
  CU_ASSERT(rcvSize == sizeof(int));
  CU_ASSERT(rcode == E_MPI_OVERSIZED_MSG);

  CU_ASSERT(MPI_check_available(OS_PID) == false);

  //test mailbox full
  CU_ASSERT(MPI_check_available(testPID) == false);

  for(i = 0; i <= MAILBOX_SIZE; i++)
    {
      rcode = MPI_send_message(testPID, testPID, size, sourceStr);

      CU_ASSERT(MPI_check_available(testPID) == true);

      if(rcode != OS_SUCCESS && i != MAILBOX_SIZE)
	{
	  CU_FAIL("Unable to fill mailbox!");

	  break;

	}

    }

  CU_ASSERT(rcode == E_MPI_MAILBOX_BUF_OVERFLOW);

  CU_ASSERT(MPI_check_available(OS_PID) == true);

  MPI_get_message(OS_PID, &rcvPID, &rcvSize, &rcode);

  CU_ASSERT(rcvPID == testPID);
  CU_ASSERT(rcvSize == sizeof(int));
  CU_ASSERT(rcode == E_MPI_MAILBOX_BUF_OVERFLOW);

  CU_ASSERT(MPI_check_available(OS_PID) == false);

  //test OS mailbox full
  for(i = 0; i <= MAILBOX_SIZE; i++)
    {
      rcode = MPI_send_message(testPID, OS_PID, size, sourceStr);

      CU_ASSERT(MPI_check_available(OS_PID) == true);

      if(rcode != OS_SUCCESS && i != MAILBOX_SIZE)
	{
	  CU_FAIL("Unable to fill mailbox!");

	  break;

	}

    }

  CU_ASSERT(rcode == E_MPI_MAILBOX_BUF_OVERFLOW);

  CU_ASSERT(MPI_check_available(OS_PID) == true);

  MPI_get_message(OS_PID, &rcvPID, &rcvSize, &rcode);

  CU_ASSERT(rcvPID == OS_PID);
  CU_ASSERT(rcvSize == sizeof(int));
  CU_ASSERT(rcode == E_MPI_MAILBOX_BUF_OVERFLOW);

  CU_ASSERT(MPI_check_available(OS_PID) == true);

  //reinitalize MPI for further tests
  MPI_initialize();

}

void Kernel_test_function_1()
{
  global++;

}

void Kernel_test_function_2()
{
  MPI_send_error(OS_PID, E_KERNEL_TERMINATE);

}

void test_Kernel()
{
  int i;
  int rcode;

  for(i = 0; i < NUM_TASKS-1; i++)
    {
      rcode = Kernel_register_function(Kernel_test_function_1);

      CU_ASSERT(rcode == OS_SUCCESS);

    }

  rcode = Kernel_register_function(Kernel_test_function_2);

  CU_ASSERT(rcode == OS_SUCCESS);
  
  rcode = Kernel_register_function(Kernel_test_function_1);

  CU_ASSERT(rcode == E_KERNEL_TASK_OVERFLOW);

  Kernel_run();

  CU_ASSERT(global == NUM_TASKS-1);

}

int main(int argc, char** argv)
{
  CU_pSuite pSuite = NULL;

  if(CUE_SUCCESS != CU_initialize_registry())
    {
      return CU_get_error();

    }

  pSuite = CU_add_suite("OS test suite", NULL, NULL);

  if(NULL == pSuite)
    {
      CU_cleanup_registry();
      return CU_get_error();

    }

  //add tests to suite
  if(NULL == CU_add_test(pSuite, "OSLib", test_OSLib))
    {
      CU_cleanup_registry();
      return CU_get_error();

    }

  if(NULL == CU_add_test(pSuite, "MPI", test_MPI))
    {
      CU_cleanup_registry();
      return CU_get_error();

    }

  if(NULL == CU_add_test(pSuite, "Kernel", test_Kernel))
    {
      CU_cleanup_registry();
      return CU_get_error();

    }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();

}

