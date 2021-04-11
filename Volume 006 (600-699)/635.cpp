/* @JUDGE_ID: 19899RK 635 C++ "By Anadan" */
// Clock solitaire
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main() {
  int i, j, k, pos, res, sp[13];
  char cards[52], piles[13][4], names[] = "J23456789TAQK";

  while (1) {
    for (i = 0; i < 52; ++i) {
      while ((j = getchar()) == ' ' || j == '\n' || j == '\t');
      if (j == '0') break;
      cards[i] = int(strchr(names, j) - names);
    }
    if (i < 52) break;

    res = 0;
    for (k = 0; k < 52; ++k) {
      pos = k;
      for (i = 0; i < 13; ++i) {
        for (j = 3; j >= 0; --j) {
          piles[i][j] = cards[pos++];
          if (pos == 52) pos = 0;
        }
      }

      for (i = 0; i < 13; ++i) sp[i] = 4;
      i = piles[12][--sp[12]];
      while (sp[i]) i = piles[i][--sp[i]];
      for (i = 0; i < 13; ++i) {
        if (sp[i]) break;
      }
      if (i == 13) ++res;
    }

    printf("%d\n", res);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
