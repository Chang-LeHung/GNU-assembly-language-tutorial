

int main() {

  asm volatile(
    "movq $60, %%rax;"
    "movq $1, %%rdi;"
    "syscall;"
    :::"eax"
  );
  return 0;
}