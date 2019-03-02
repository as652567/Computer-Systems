/**                                                                 
 *                                              
 * \file signal-parent.cpp                       
 *                                                               
 * \brief program to explore Linux processes and shells by creating the shell of typical daemon process            
 *                                                         
 * \author Allison Smith                                                    
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void sig_handler(int sig) {

  int status = 0;
  printf("Sending signal to parent process...");
  int child_pid = wait(&status);
  if (child_pid== -1) {
    printf("waitpid error");
    exit(EXIT_FAILURE);
  } else {
    printf("Parent: getting exit status of child\n");
    printf("Parent: child pid upon return is %u and exit status is %d\n", child_pid, WEXITSTATUS(status));
  }
}

int main(int argc, char* argv[]) {
   
  /* initialization of child process */
  char child[] = "/home/as652567/signal-child";
  pid_t child_pid = 0; 
  char* const params[] = {(char*)"signal-child",(char*)  NULL};

  printf("Running program to simulate a typical daemon process\n");

  /* Simulate daemon process initializing and waiting for an incoming request */
  printf("Main program sleeping for 10 seconds to simulate initialization of daemon process\n");
  sleep(10);

  printf("Parent PID = %u\n",(int)getpid());

  /* fork/exec parent process to create a child process */
  int status = 0;
  printf("Parent forking child process...\n");
  pid_t pid =fork();

  if(pid == -1) {
    printf("Error forking: -1 return to parent and no child process created");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0) {
    printf("Child process created with pid: %u\n", getpid());
    child_pid = getpid();

    execv(child, params);
    exit(EXIT_FAILURE); ///< should only reach this line is exec returns -1 (exec error)
  }
  else if (pid > 0) {
    
    /* parent process sleeps for longer period of time after fork/exec of child process */
    printf("Parent: going to sleep for 2 minutes\n"); 

    /* parent process determines when child exits and returns the child's pid and exit status using SIGCHLD signal */
    signal(SIGCHLD, sig_handler);  
    sleep(120);
  }
  
  return 0;
 }
