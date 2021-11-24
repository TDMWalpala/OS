#include <stdio.h>
#include <unistd.h>

void main(){

  int pi_d;

  int pid;

  pi_d = fork();

  if(pi_d == 0)
  {
      printf("CHILD 1\n");
  }
  if(pi_d > 0)
  {
      pid = fork();

      if(pid > 0)
      {
            printf("PARENT\n");    
      }
      else if(pid == 0)
      {
            printf("CHILD 2\n");
      }
    }
 }
