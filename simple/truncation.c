

#include <stdio.h>


int main() {

  double a = 10.1231234214;
  int i;
  asm(
    "movsd %1, %%xmm0;"
    "cvttsd2si %%xmm0, %0;"
    :"=r"(i):"m"(a):"xmm0"
  );
  printf("i = %d\n", i);
  return 0;
}