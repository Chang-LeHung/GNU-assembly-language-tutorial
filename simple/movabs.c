

#include <stdio.h>
#include <assert.h>

int main() {
  long a;
  asm volatile(
    "movabs $-0x100020, %0;"
    :"=r"(a)::
  );
  printf("a = %ld\n", a);
  assert(a == 0x100020);
  return 0;
}