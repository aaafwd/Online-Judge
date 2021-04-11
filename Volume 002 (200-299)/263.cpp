/* @JUDGE_ID: 19899RK 263 C++ "By Anadan" */
// Number Chains
// Accepted (0.030 seconds using as much as 392 kbytes)

#include <stdio.h>

#include <unordered_set>

int chain[1010];

void getnums(int x, int &a, int &d) {
  int i, j;
  char str[10];

  for (i = 0; i < 10; ++i) str[i] = 0;
  while (x) {
    ++str[x % 10];
    x /= 10;
  }

  a = d = 0;
  for (i = 1; i < 10; ++i) {
    for (j = 0; j < str[i]; ++j) a = 10 * a + i;
  }
  for (i = 9; i >= 0; --i) {
    for (j = 0; j < str[i]; ++j) d = 10 * d + i;
  }
}

int main() {
  int i, j, a, d;
  std::unordered_set<int> mask;
  mask.reserve(1024);

  while (scanf("%d", &i) == 1 && i) {
    printf("Original number was %d\n", i);
    mask.clear();
    while (1) {
      getnums(i, a, d);
      i = d - a;
      printf("%d - %d = %d\n", d, a, i);
      if (mask.count(i)) break;
      mask.insert(i);
    }
    int size = mask.size() + 1;
    printf("Chain length %d\n\n", size);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

