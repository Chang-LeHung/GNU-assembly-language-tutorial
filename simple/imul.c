
#include <stdio.h>

int main() {

  unsigned int a = 10;
  unsigned int b = 2;
  printf("a = %d b = %d\n", a, b);
  asm(
    "imull %1, %0;"
    :"+r"(a):"r"(b):
  );
  printf("a = %d b = %d\n", a, b);
  return 0;
}