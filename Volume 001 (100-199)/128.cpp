/* @JUDGE_ID: 19899RK 128 C++ "By Anadan" */
// Software CRC
// Accepted (0.030 seconds using as much as 396 kbytes)

#include <stdio.h>
#define G 34943

int main() {
  long rest;
  char str[1280], *p;

  while (fgets(str, sizeof(str), stdin)) {
    if (str[0] == '#') break;
    rest = 0L;
    for (p = str; *p != '\n'; p++) {
      rest <<= 8;
      rest += *p;
      rest %= G;
    }
    rest <<= 8;
    rest %= G;
    rest <<= 8;
    rest %= G;
    if (rest) rest = G - rest;
    printf("%.2X %.2X\n", int(rest >> 8), int(rest & 0xFF));
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
