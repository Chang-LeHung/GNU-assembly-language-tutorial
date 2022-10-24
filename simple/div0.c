#include <unistd.h>
#include <stdio.h>
#include <sysexits.h>

int main() {
  printf("pid = %d\n", getpid());
  while (1)
  {
    /* code */
  }
  
  return 0;
}