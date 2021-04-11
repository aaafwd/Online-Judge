/* @JUDGE_ID: 19899RK 657 C++ "By Anadan" */
// The die is cast
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dice[500], N;
char map[52][52];

int sort_function(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

void markx(int i, int j) {
  map[i][j] = '.';
  if (map[i - 1][j] == 'X') markx(i - 1, j);
  if (map[i + 1][j] == 'X') markx(i + 1, j);
  if (map[i][j - 1] == 'X') markx(i, j - 1);
  if (map[i][j + 1] == 'X') markx(i, j + 1);
}

void mark(int i, int j) {
  if (map[i][j] == 'X') {
    markx(i, j);
    ++dice[N];
  }
  map[i][j] = '.';
  if (map[i - 1][j] != '.') mark(i - 1, j);
  if (map[i + 1][j] != '.') mark(i + 1, j);
  if (map[i][j - 1] != '.') mark(i, j - 1);
  if (map[i][j + 1] != '.') mark(i, j + 1);
}

int main() {
  int set = 0, i, j, r, c;

  for (i = 0; i < 52; ++i) map[0][i] = map[i][0] = '.';

  while (scanf("%d%d\n", &c, &r) == 2 && c) {
    for (i = 1; i <= r; ++i) {
      scanf("%s\n", map[i] + 1);
      map[i][c + 1] = '.';
    }
    memset(map[i], '.', c + 2);
    N = 0;
    for (i = 1; i <= r; ++i)
      for (j = 1; j <= c; ++j) {
        if (map[i][j] != '.') {
          dice[N] = 0;
          mark(i, j);
          ++N;
        }
      }

    printf("Throw %d\n", ++set);
    qsort(dice, N, sizeof(int), sort_function);
    for (i = 0; i < N; ++i) {
      if (dice[i]) break;
    }
    if (i != N) {
      printf("%d", dice[i]);
      for (++i; i < N; ++i) printf(" %d", dice[i]);
    }
    printf("\n\n");
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
