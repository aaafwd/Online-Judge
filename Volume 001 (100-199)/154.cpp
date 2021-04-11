/* @JUDGE_ID: 19899RK 154 C++ "By Anadan" */
// Recycling
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main() {
  int N, i, j, k, min, cur, res;
  char bins[] = "roygb";
  char recycle[100][5];
  char str[1024], in1[2], in2[2], *p;

  while (fgets(str, sizeof(str), stdin) && str[0] != '#') {
    N = 0;
    do {
      p = strtok(str, ",");
      while (p && sscanf(p, "%1s%*1s%1s", in1, in2) == 2) {
        recycle[N][int(strchr(bins, in1[0]) - bins)] = in2[0];
        p = strtok(NULL, ",");
      }
      ++N;
    } while (fgets(str, sizeof(str), stdin) && str[0] != 'e');

    for (min = 30000, i = 0; i < N; ++i) {
      cur = 0;
      for (j = 0; j < N; ++j) {
        for (k = 0; k < 5; ++k) {
          if (recycle[i][k] != recycle[j][k]) ++cur;
        }
        if (cur >= min) break;
      }

      if (min > cur) {
        min = cur;
        res = i;
      }
    }

    printf("%d\n", res + 1);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
