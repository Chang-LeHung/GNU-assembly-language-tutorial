
#include <stdio.h>
#include <sys/types.h>

 
static inline void prefetch_range(void *addr, size_t len)
{
    char *cp;
    char *end = addr + len;
 
    for (cp = addr; cp < end; cp += 4)
        __builtin_prefetch(cp);
}

int main() {
  int data[10];
  prefetch_range(data, 40);
  return 0;
}