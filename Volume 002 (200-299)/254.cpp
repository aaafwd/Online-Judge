/* @JUDGE_ID: 19899RK 254 C++ "By Anadan" */
// Towers of Hanoi
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main() {
  int N;
  char str[128];
  char binary[128];
  while (scanf("%d %s", &N, str) == 2) {
    if (N == 0) break;
    for (int k = 0; k < N; ++k) {
      int x = 0;
      for (int i = 0; str[i]; ++i) {
        x = 10 * x + (str[i] - '0');
        str[i] = '0' + (x >> 1);
        x &= 1;
      }
      binary[k] = x;
    }

    int a[3] = {0, 0, 0};
    int offset = 0;
    for (int k = N - 1; k >= 0; --k) {
      if (!binary[k]) {
        ++a[offset];
      } else if (k & 1) {
        ++a[(offset + 2) % 3];
        offset = (offset + 1) % 3;
      } else {
        ++a[(offset + 1) % 3];
        offset = (offset + 2) % 3;
      }
    }
    printf("%d %d %d\n", a[0], a[1], a[2]);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
