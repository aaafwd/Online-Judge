/* @JUDGE_ID: 19899RK 107 C++ "By Anadan" */
// The Cat in the Hat
// Accepted (0.080 seconds using as much as 396 kbytes)

#include <math.h>
#include <stdio.h>

int main() {
  const double EPS = 1e-12;
  double sum, cat, N, toN, H, cat1, k;

  while (scanf("%lf%lf", &H, &cat1) == 2) {
    if (H == 0.0) break;
    if (H == 1.0) {
      printf("0 1\n");
      continue;
    }

    if (cat1 == 1.0) {
      cat = log(H) / log(2.0);
      sum = 2.0 * H - 1.0;
      printf("%.0lf %.0lf\n", cat, sum);
      continue;
    }

    if (H - cat1 == 1.0) {
      printf("1 %.0lf\n", H + cat1);
      continue;
    }

    for (N = 2.0, toN = sqrt(cat1); N <= toN; N += 1.0) {
      sum = log(cat1) / log(N);
      if (fabs(sum - floor(sum + 0.5)) > EPS) continue;
      cat = log(H) / log(N + 1.0);
      if (fabs(cat - sum) > EPS) continue;
      sum = N * (H - cat1) + H;
      cat = (cat1 - 1.0) / (N - 1.0);
      printf("%.0lf %.0lf\n", cat, sum);
      break;
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
