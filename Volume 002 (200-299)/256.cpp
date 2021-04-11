/* @JUDGE_ID: 19899RK 256 C++ "By Anadan" */
// Quirksome Squares
// Accepted (0.000 seconds using as much as 392 kbytes)

#include <stdio.h>

int main() {
  char format[16];
  int n;
  long i, j, k, max;

  while (scanf("%d", &n) > 0) {
    // Precalc.
    if (n == 2) {
      puts("00\n01\n81");
    } else if (n == 4) {
      puts("0000\n0001\n2025\n3025\n9801");
    } else if (n == 6) {
      puts("000000\n000001\n088209\n494209\n998001");
    } else if (n == 8) {
      puts(
          "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984"
          "\n60481729\n99980001");
    } else {
      n >>= 1;
      sprintf(format, "%%.%dld%%.%dld\n", n, n);
      for (max = 1, i = 0; i < n; i++, max *= 10);
      for (i = 0; i < max; i++) {
        for (j = 0, k = i; k < max; j++, k++) {
          if (k * k == i * max + j) {
            printf(format, i, j);
          }
        }
      }
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

