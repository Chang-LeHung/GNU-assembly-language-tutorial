

#include <stdio.h>
#include <emmintrin.h>

typedef union { __m128 a4; float a[4]; } data_t;

int main() {
  data_t d, t;
  d.a4 = _mm_set_ps( 4.0f, 4.1f, 4.2f, 4.3f );
  t.a4 = _mm_set_ps( 1.0f, 1.0f, 1.0f, 1.0f );
  t.a4 = _mm_add_ps( d.a4, t.a4);
  for(int i = 0; i < 4; i++) {
    printf("d.a4[%d] = %g\t", i, d.a[i]);
  }
  printf("\n");
  for(int i = 0; i < 4; i++) {
    printf("t.4[%d] = %g\t", i, t.a[i]);
  }
  printf("\n");
  t.a4 = _mm_cmpge_ps(d.a4, t.a4);
  printf("\n");
  for(int i = 0; i < 4; i++) {
    printf("t.4[%d] = %g\t", i, t.a[i]);
  }
  printf("\n");
  return 0;
}