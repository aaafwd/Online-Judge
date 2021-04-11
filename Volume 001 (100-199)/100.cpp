/* @JUDGE_ID: 19899RK 100 C++ "By Anadan" */
// The 3n + 1 problem
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>

constexpr int kCacheSize = 32768;
int cache[kCacheSize] = {0};

int cyclelen(int num) {
  int res = 0;
  while (num >= kCacheSize) {
    if (num & 1) {
      num += ((num + 1) >> 1);
      res += 2;
    } else {
      num >>= 1;
      ++res;
    }
  }
  if (cache[num] == 0) {
    if (num == 1) {
      cache[num] = 1;
    } else if (num & 1) {
      cache[num] = 2 + cyclelen(num + ((num + 1) >> 1));
    } else {
      cache[num] = 1 + cyclelen(num >> 1);
    }
  }
  return res + cache[num];
}

int solve(int i, int j) {
  int max, tmp;

  max = cyclelen(i++);
  for (; i <= j; i++) {
    tmp = cyclelen(i);
    if (tmp > max) max = tmp;
  }

  return max;
}

int main() {
  int i, j;
  while (scanf("%d%d", &i, &j) > 0) {
    if (i < j) {
      printf("%d %d %d\n", i, j, solve(i, j));
    } else {
      printf("%d %d %d\n", i, j, solve(j, i));
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
