//oserr.h

#ifndef OSERR_H
#define OSERR_H

#define OS_SUCCESS 0

/*
 *
 * reserve range 3000-7999 for server error codes
 * 
 * Main Controller: 3000-3999
 * Wi-Fi Controller: 4000-4999
 * Console Controller: 5000-5999
 * GPS Controller: 6000-6999
 * IO Controllers: 7000-7999
 *
 */

//reserve range 7000-9999 for message opcodes

/*
 *
 * Command Message: 7000-7999
 * Request Message: 8000-8999
 * Error Handling Message: 9000-9999
 *
 */

/*
 *
 * MPI errors
 * 1000-1099
 *
 */
#define E_MPI_INVALID_SRC_PID 1000
#define E_MPI_INVALID_DST_PID 1001
#define E_MPI_OVERSIZED_MSG 1002
#define E_MPI_MAILBOX_BUF_OVERFLOW 1003
#define E_MPI_INVALID_RCV_PID 1004
#define E_MPI_NO_MSG_AVAILABLE 1005

/*
 *
 * Kernel errors
 * 2000-2099
 *
 */
#define E_KERNEL_TASK_OVERFLOW 2000
#define E_KERNEL_TERMINATE 2001

#endif
