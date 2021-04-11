/* @JUDGE_ID: 19899RK 114 C++ "By Anadan" */
// Simulation Wizardry
// Accepted (0.010 seconds using as much as 420 kbytes)

#include <stdio.h>
#include <string.h>

int main() {
  int map[50][50];
  int i, j, p, m, n, ttl, sum, cur, index = 1, dx, dy, tmp;
  int bumper_value[2501];
  int bumper_cost[2501];

  bumper_value[0] = 0;
  scanf("%d%d%d%d", &m, &n, &bumper_cost[0], &p);
  for (i = 0; i < n; ++i) {
    memset(map[i], 0, m * sizeof(map[0][0]));
    map[i][0] = map[i][m - 1] = 1;
  }
  for (i = 0; i < m; ++i) map[0][i] = map[n - 1][i] = 1;

  while (p--) {
    scanf("%d%d%d%d", &i, &j, &bumper_value[index], &bumper_cost[index]);
    map[j - 1][i - 1] = ++index;
  }

  sum = 0;
  while (scanf("%d%d%d%d", &i, &j, &p, &ttl) == 4) {
    cur = 0;
    --i;
    --j;
    if (p == 0) {
      dx = 1;
      dy = 0;
    } else if (p == 1) {
      dx = 0;
      dy = 1;
    } else if (p == 2) {
      dx = -1;
      dy = 0;
    } else {
      dx = 0;
      dy = -1;
    }

    while (ttl-- > 1) {
      i += dx;
      j += dy;
      tmp = map[j][i];
      if (tmp) {
        cur += bumper_value[tmp - 1];
        ttl -= bumper_cost[tmp - 1];
        i -= dx;
        j -= dy;
        tmp = dx;
        dx = dy;
        dy = -tmp;
      }
    }

    printf("%d\n", cur);
    sum += cur;
  }

  printf("%d\n", sum);
  return 0;
}
/* @END_OF_SOURCE_CODE */
