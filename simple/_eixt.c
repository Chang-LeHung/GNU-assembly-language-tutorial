
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdatomic.h>

int main() {

  if(fork() ==  0) {
    _exit(1);  
  } else {
    int status;
    wait(&status);
    printf("status = %d\n", WEXITSTATUS(status));
  } 
  return 0;
}