
#include <stdio.h>

typedef struct data
{
  int a;
  int b;
  int c;
}data_t;

data_t find(data_t t) {
  printf("a = %d b = %d c = %d\n", t.a, t.b, t.c);
  t.a = 1;
  t.b = 2;
  t.c = 3;
  return t;
}

int main() {
  data_t a;
  a.a = -1;
  a.b = -2;
  a.c = -3;
  a = find(a);
  printf("a = %d b = %d c = %d\n", a.a, a.b, a.c);
  return 0;
}
