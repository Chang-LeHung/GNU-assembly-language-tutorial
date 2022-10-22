

#include <stdio.h>


int main() {

  double d = 2.5;
  double l = 2.5;
  asm volatile(
    "movlpd %0, %%xmm0;"
    "movlpd %1, %%xmm1;"
    "mulsd %%xmm1, %%xmm0;"
    "movlpd %%xmm0, %0"
    :"+m"(d):"m"(l):"memory", "xmm0", "xmm1"
  );
  // d *= 2.5;
  printf("d = %lf\n", d);
  return 0;
}