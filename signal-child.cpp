/**
 * \file signal-child.cpp
 * 
 * \brief child process code for siganls HW to create a typical daemon process to fork child to perform necessary work 
 *
 *  Child process sleeps for 30 seconds to simulate doing work and exits with a value of 53
 *
 * \author Allison Smith 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

  printf("Child: process executing\n");

  /* child process sleeps for 30 seconds to simulate a child process doing work */
  printf("Child: going to sleep for 30 seconds...\n");
  sleep(30);

  /* after child process wakes up, exits with value of 53 */
  printf("Child: process exiting\n");
  exit(53);

  return 0;

}
