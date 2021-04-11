/* @JUDGE_ID: 19899RK 232 C++ "By Anadan" */
// Crossword Answers
// Accepted (0.000 seconds using as much as 392 kbytes)

#include <stdio.h>

int main() {
  int r, c, i, j, k, nums[12][12], max, set = 0;
  char map[12][12];

  for (i = 0; i < 12; ++i) map[0][i] = map[i][0] = '*';
  while (scanf("%d%d\n", &r, &c) == 2 && r) {
    for (i = 1; i <= r; ++i) scanf("%s\n", map[i] + 1);
    for (j = 0; j <= c; ++j) map[i][j] = '*';

    max = 0;
    for (i = 1; i <= r; ++i) {
      for (j = 1; j <= c; ++j) {
        if (map[i][j] != '*' &&
            (map[i - 1][j] == '*' || map[i][j - 1] == '*')) {
          nums[i][j] = ++max;
        } else {
          nums[i][j] = 0;
        }
      }
    }

    if (set) putchar('\n');
    printf("puzzle #%d:\nAcross\n", ++set);
    for (i = 1; i <= r; ++i) {
      for (j = 1; j <= c; ++j) {
        if (nums[i][j] && map[i][j - 1] == '*') {
          printf("%3d.", nums[i][j]);
          for (k = j; map[i][k] && map[i][k] != '*'; ++k) putchar(map[i][k]);
          putchar('\n');
        }
      }
    }

    puts("Down");
    for (i = 1; i <= r; ++i) {
      for (j = 1; j <= c; ++j) {
        if (nums[i][j] && map[i - 1][j] == '*') {
          printf("%3d.", nums[i][j]);
          for (k = i; map[k][j] && map[k][j] != '*'; ++k) putchar(map[k][j]);
          putchar('\n');
        }
      }
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

