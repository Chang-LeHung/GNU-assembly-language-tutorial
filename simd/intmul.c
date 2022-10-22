

#include <stdio.h>

/*
  Single Double Effect Description
  addss addsd D ← D + S Floating-point add
  subss subsd D ← D − S Floating-point subtract
  mulss mulsd D ← D × S Floating-point multiply
  divss divsd D ← D / S Floating-point divide
  maxss maxsd D ← max(D, S) Floating-point maximum
  minss minsd D ← min(D, S) Floating-point minimum
  sqrtss sqrtsd D ← √S Floating-point square root 
 */

/*
Instruction Source Destination Description
movss M32/X X Move single precision
movss X M32 Move single precision
movsd M64/X X Move double precision
movsd X M64 Move double precision
cvtss2sd M32/X X Convert single to double precision
cvtsd2ss M64/X X Convert double to single precision
cvtsi2ss M32/R32 X Convert integer to single precision
cvtsi2sd M32/R32 X Convert integer to double precision
cvtsi2ssq M64/R64 X Convert quadword integer to single precision
cvtsi2sdq M64/R64 X Convert quadword integer to double precision
cvttss2si X/M32 R32 Convert with truncation single precision to integer
cvttsd2si X/M64 R32 Convert with truncation double precision to integer
cvttss2siq X/M32 R64 Convert with truncation single precision to quadword integer
cvttsd2siq X/M64 R64 Convert with truncation double precision to quadword integer
*/
int main() {
  int a = 3;
  double b = 2.2;
  asm(
    "cvtsi2sd %1, %%xmm0;"
    "movsd %0, %%xmm1;"
    "mulsd %%xmm1, %%xmm0;"
    "movsd %%xmm0, %0"
    :"+m"(b):"m"(a):"memory"
  );
  printf("b = %lf\n", b);
  return 0;
}