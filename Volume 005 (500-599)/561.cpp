/* @JUDGE_ID: 19899RK 561 C++ "By Anadan" */
// Jackpot
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main() {
  int set, i, j, sum, count[3][26], N[3];
  char str[3][256];

  scanf("%d", &set);
  while (set--) {
    scanf("%d%d%d\n", &N[0], &N[1], &N[2]);
    for (i = 0; i < 3; ++i) {
      fgets(str[i], sizeof(str[i]), stdin);
      for (j = 0; j < 26; ++j) count[i][j] = 0;
      for (j = 0; j < N[i]; ++j) ++count[i][str[i][j] - 'A'];
    }

    sum = 0;
    for (i = 0; i < 26; ++i) sum += count[0][i] * count[1][i] * count[2][i];
    sum *= 34;

    printf("%.4lf\n", double(sum) / N[0] / N[1] / N[2]);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

