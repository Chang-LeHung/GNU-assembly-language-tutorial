

int main() {

  asm volatile(
    "movl $1, %%eax;"
    "movl $1, %%ebx;"
    "int $0x80;"
    :::"eax"
  );
  return 0;
}