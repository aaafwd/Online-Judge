/* @JUDGE_ID: 19899RK 654 C++ "By Anadan" */
// Ratio
// Accepted (0.000 seconds with low memory spent)

#include <math.h>
#include <stdio.h>

int main() {
  double n, m, est_n, est_m, i, j;
  char flag = 0;

  while (scanf("%lf%lf", &n, &m) == 2) {
    if (flag) putchar('\n');
    est_n = floor(n / m + 0.5);
    est_m = 1.0;
    printf("%.0lf/1\n", est_n);
    for (j = 2.0; j <= m; ++j) {
      i = floor(n * j / m + 0.5);
      if (fabs((i * m - j * n) / j) < fabs((est_n * m - est_m * n) / est_m)) {
        est_n = i;
        est_m = j;
        printf("%.0lf/%.0lf\n", est_n, est_m);
      }
    }
    flag = 1;
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
