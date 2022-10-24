
#include <stdio.h>

int main() {
  float A[4] = {-1, -2, -3, -4};
  float B[4] = {6, 7, 8, 9};
  asm(
    "movaps %0, %%xmm0;" // mov start_address xmm_register
    "movaps %1, %%xmm1;" // p *(float*)(-0x20 + $rbp)@4
    "movmskps %%xmm1, %%ebx;"
    "movq $3, %%rcx;"
    "repeat:addps %%xmm0, %%xmm1;"
    "loop repeat;"
    "movaps %%xmm1, %0"
    :"+m"(B):"m"(A):"memory", "rcx", "ebx"
  );
  for(int i = 0; i < 4; i++) {
    printf("A[%d] = %lf\t", i, A[i]);
  }
  printf("\n");
  for(int i = 0; i < 4; i++) {
    printf("B[%d] = %lf\t", i, B[i]);
  }
  printf("\n");
  // int i;
  // asm(
  //   ""
  //   :::"memory"
  // );
  return 0;
}