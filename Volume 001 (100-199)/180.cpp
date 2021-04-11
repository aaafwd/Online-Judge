/* @JUDGE_ID: 19899RK 180 C++ "By Anadan" */
// Eeny Meeny
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

#define MAX 1000000

int main() {
  int chiefs[MAX + 1];
  chiefs[0] = chiefs[1] = 0;
  for (int i = 2; i <= MAX; ++i) {
    const int first = 14 % i;
    int index = (first + chiefs[i - 1]) % (i - 1);
    if (index >= first) ++index;
    chiefs[i] = index;
  }

  int a, b;
  char mask[MAX + 1];
  while (scanf("%d%d", &a, &b) == 2) {
    if (a == 0 && b == 0) break;
    const int max_pos = (a + 1) / 2;
    memset(mask, 0, max_pos);
    for (int i = a; i <= b; ++i) {
      int x = chiefs[i];
      if (x < max_pos) mask[x] = 1;
      x = i - x;
      if (x < max_pos) mask[x] = 1;
    }
    int pos = 1;
    while (pos < max_pos && mask[pos]) ++pos;
    if (pos < max_pos) {
      printf("%d\n", pos);
    } else {
      printf("Better estimate needed\n");
    }
  }
  return 0;
}

