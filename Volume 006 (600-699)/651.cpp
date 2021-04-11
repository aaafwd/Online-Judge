/* @JUDGE_ID: 19899RK 651 C++ "By Anadan" */
// Deck
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#define SIZE 100000

int main() {
  long n;
  long double solves[SIZE], t = 2.0;
  solves[0] = 0.0;

  for (n = 1L; n < SIZE; n++, t += 2.0) {
    solves[n] = solves[n - 1] + (1.0 / t);
  }

  printf("# Cards Overhang\n");
  while (scanf("%ld", &n) > 0) {
    printf("%5ld%10.3Lf\n", n, solves[n]);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
