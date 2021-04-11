/* @JUDGE_ID: 19899RK 108 C++ "By Anadan" */
// Maximum Sum
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main() {
  int accum_sums[128][128];

  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", &accum_sums[i][j]);
      if (j) accum_sums[i][j] += accum_sums[i][j - 1];
    }
  }

  int max_sum = accum_sums[0][0];
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      int running_sum = 0;
      for (int k = 0; k < N; ++k) {
        int value = accum_sums[k][j];
        if (i) value -= accum_sums[k][i - 1];
        if (running_sum < 0) running_sum = 0;
        running_sum += value;
        if (max_sum < running_sum) max_sum = running_sum;
      }
    }
  }
  printf("%d\n", max_sum);

  return 0;
}
/* @END_OF_SOURCE_CODE */

