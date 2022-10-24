
#include <stdio.h>

int main() {

  int a = 10;
  int b = 2;
  printf("a = %d b = %d\n", a, b);
  asm(
    "subl %1, %0;"
    :"+r"(a):"r"(b):
  );
  printf("a = %d b = %d\n", a, b);
  return 0;
}