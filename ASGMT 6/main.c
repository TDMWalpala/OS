#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

void main(){
    int fd[2];
    if (pipe(fd)==-1){
        printf("An error ocurred with opening the pipe\n");
  }    
  int pi_d;
  pi_d = fork();

  if(pi_d == 0)
  {
      //printf("CHILD 1\n");
      //printf("Pid- %d\t",getpid());
      //printf("ppid - %d\n",getppid());
      close(fd[1]);
      char string2[20];
      read(fd[0],&string2,sizeof(string2));
      close(fd[0]);
      printf("%s\n",string2);
  }
  if(pi_d > 0)
  {
        //printf("PARENT\n"); 
        //printf(">> pid- %d\t",getpid());
	    //printf(">> ppid- %d\n",getppid());
        close(fd[0]);
        char string[20] = "Hello from parent";
        write(fd[1],&string,sizeof(string));
        close(fd[1]);   
    }
 }
