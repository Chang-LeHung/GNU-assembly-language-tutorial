

#include <stdio.h>
#include <sys/types.h>

static inline int ret() {
  int sum = 0;
  for(int i = 0; i < 10; i++) 
    sum += i;
  u_int64_t rsp;
  asm(
    "movq %%rsp, %0":"=m"(rsp)::
  );
  return sum;
}

int main() {

  int a = ret();
  printf("%d\n", a);
  return 0;
}