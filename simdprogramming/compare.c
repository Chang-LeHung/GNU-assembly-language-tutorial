
#include <stdio.h>
#include <emmintrin.h>

typedef union data
{
  __m128 m;
  float mm[4];
}data_t;


int main() {
  data_t t;
  t.m = _mm_set_ps(-1, -2, 2, 1);
  t.m = _mm_cmpge_ps(t.m, _mm_setzero_ps() );

  for(int i = 0; i < 4; i++) {
    printf("t.mm[%d] = %g\t", i, t.mm[i]);
  }
  printf("\n");
  printf("%lf\n", t.mm[0]);
  return 0;
}