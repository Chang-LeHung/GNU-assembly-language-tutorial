
#include <stdio.h>
#include <stdlib.h>

int main() {
  float *A = (float*)malloc(16);
  float *B = (float*)malloc(16);
  for(int i = 0; i < 4; i++) {
    A[i] = i + 1;
    B[i] = i + 6;
  }
  printf("%ld\n", sizeof(A));
  asm(
    "movaps (%0), %%xmm0;"
    "movaps (%1), %%xmm1;"
    "movmskps %%xmm1, %%ebx;"
    "mov $3, %%ecx;"
    "repeat:addps %%xmm0, %%xmm1;"
    "loop repeat;"
    "movaps %%xmm1, (%0);"
    :"+r"(B):"r"(A):"memory", "ecx", "ebx" 
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