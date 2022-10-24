
#include <stdio.h>

int main() {

  unsigned int a = (1 << 31);
  unsigned int b = 16;
  printf("a = %u b = %u\n", a, b);
  asm(
    "mul %1;"
    "movl %%edx, %1;"
    :"+a"(a), "+r"(b)::"rdx"
  );
  printf("a = %u b = %u\n", a, b);
  return 0;
}