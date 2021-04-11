/* @JUDGE_ID: 19899RK 653 C++ "By Anadan" */
// Gizilch
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int n, m;
char mask[101];

int possible(int i, int a) {
  if (a == 1) {
    if (mask[0]) return 1;
    mask[0] = 1;
    mask[0] = possible(2, m);
    if (mask[0]) return 1;
    mask[0] = 0;
    return 0;
  }

  if (i > a) return 0;
  for (; i <= 100; ++i) {
    if (mask[i]) continue;
    if (!(a % i)) {
      mask[i] = 1;
      if (possible(i + 1, a / i)) return 1;
      mask[i] = 0;
      if (a == i) break;
    }
  }

  return 0;
}

int main() {
  while (scanf("%d%d\n", &n, &m) == 2) {
    if (n < m) n ^= m ^= n ^= m;
    memset(mask, 0, 101);
    if (possible(2, n)) {
      printf("%d\n", n);
    } else {
      mask[0] = 1;
      if (!possible(2, m)) {
        printf("%d\n", n);
      } else {
        printf("%d\n", m);
      }
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
