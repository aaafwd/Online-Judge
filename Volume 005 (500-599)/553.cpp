/* @JUDGE_ID: 19899RK 553 C++ "By Anadan" */
// Simply proportion
// Accepted (0.010 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

int x, y;

void solveit(int a, int b, int N) {
  int max = -1;

  y = 3 * N / (a + 3 * b);
  if (y < 10) y = 10;

  while (1) {
    x = (N - b * y) / a;
    if (x <= max) break;

    if (x > y / 3) x = y / 3;
    if (max < x) max = x;
    ++y;
  }

  x = max;
}

int main() {
  int N, W, k, a, i;
  char str[128], *words[41], *p;

  while (scanf("%d", &N) == 1 && N) {
    fgets(str, sizeof(str), stdin);
    fgets(str, sizeof(str), stdin);

    W = k = a = 0;
    p = strtok(str, " \n");
    while (p) {
      words[W++] = p;
      while (*p) {
        if (*p == 'A') k += 18;
        else if (*p == 'B') k += 17;
        else if (*p == 'I') k += 10;
        else if (*p == 'M') k += 20;
        else if (*p == 'S') k += 16;
        else if (*p == 'Y') k += 13;
        ++p;
        ++a;
      }
      --a;

      p = strtok(NULL, " \n");
    }

    solveit(a, W - 1, N - k);
    N -= k + x * a;
    for (i = 0; i < W; ++i) {
      p = words[i];
      putchar(*p++);
      while (*p) {
        printf("/(%d)%c", x, *p++);
      }

      if (i < W - 1) {
        y = N / (W - i - 1);
        printf("/(%d)", y);
        N -= y;
      }
    }
    putchar('\n');
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

