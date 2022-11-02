

#include <stdio.h>

int main() {
  float A[100];
  float B[100];
  float C[100];
  float D[100];
  float E[100];
  for(int i = 0; i < 100; i++) {
    A[i] = i;
    B[i] = i;
    C[i] = i;
  }
  for(int i = 0; i < 100; i++) {
    E[i] = A[i] + B[i] + C[i];
  }

  for(int i = 0; i < 100; i++) {
    E[i] = A[i] + B[i] + C[i] + D[i];
    printf("%lf\n", E[i]);
  }
  return 0;
}