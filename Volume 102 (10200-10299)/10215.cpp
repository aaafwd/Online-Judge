/* @JUDGE_ID: 19899RK 10215 C++ "By Anadan" */
// The Largest/Smallest Box...
// Accepted (0.000 seconds using as much as 400 kbytes)

#include <math.h>
#include <stdio.h>

int main() {
  long double L, W, tmp, max, min;

  while (scanf("%Lf%Lf\n", &L, &W) == 2) {
    if (L > W) { tmp = L; L = W; W = tmp; }
    max = round((L + W - sqrt(L * L + W * W - L * W)) / 6.0 * 1000 + 1e-10) * 0.001;
    min = round(L * 500 + 1e-10) * 0.001;
    printf("%.3Lf 0.000 %.3Lf\n", max, min);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

