//oserr.h

#ifndef OSERR_H
#define OSERR_H

#define OS_SUCCESS 0

/*
 *
 * Command Message: 
 * Request Message: 
 * Error Handling Message: 
 *
 */

#define C_DRIVE_FORWARD 10
#define C_DRIVE_REVERSE 11
#define C_DRIVE_RIGHT 12
#define C_DRIVE_LEFT 13
#define C_DRIVE_HALT 14

/*
 *
 * reserve range 3000-7999 for server error codes
 * 
 * Main controller: 3000-3999
 * Wi-Fi driver: 4000-4999
 * Wi-Fi controller: 5000-5999
 * GPS driver: 6000-6999
 * Motor driver: 7000-7999
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
