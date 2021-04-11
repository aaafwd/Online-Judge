/* @JUDGE_ID: 19899RK 164 C++ "By Anadan" */
// String Computer
// Accepted (0.020 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

char str1[32], str2[32];
int map[32][32], N, M;

struct COP {
  int pos;
  char c1, c2;
};

int main() {
  int i, j, k;
  COP stck[64];

  while (scanf("%s%s", str1, str2) == 2 && str1[0] != '#') {
    N = strlen(str1) + 1;
    M = strlen(str2) + 1;
    for (i = 0; i < M; ++i) map[i][0] = i;
    for (j = 0; j < N; ++j) map[0][j] = j;

    for (j = 1; j < N; ++j) {
      for (i = 1; i < M; ++i) {
        k = map[i - 1][j];
        if (k > map[i][j - 1]) k = map[i][j - 1];
        if (k > map[i - 1][j - 1]) k = map[i - 1][j - 1];
        ++k;

        if (str1[j - 1] == str2[i - 1] && k > map[i - 1][j - 1]) {
          k = map[i - 1][j - 1];
        }

        map[i][j] = k;
      }
    }

    i = M - 1;
    j = N - 1;
    k = 0;
    while (i || j) {
      if (i && map[i - 1][j] + 1 == map[i][j]) {
        stck[k].c1 = 'I';
        stck[k].c2 = str2[i - 1];
        stck[k].pos = i;
        ++k;
        --i;
      } else if (j && map[i][j - 1] + 1 == map[i][j]) {
        stck[k].c1 = 'D';
        stck[k].c2 = str1[j - 1];
        stck[k].pos = i + 1;
        ++k;
        --j;
      } else if (map[i - 1][j - 1] + 1 == map[i][j]) {
        stck[k].c1 = 'C';
        stck[k].c2 = str2[i - 1];
        stck[k].pos = i;
        ++k;
        --i;
        --j;
      } else {
        --i;
        --j;
      }
    }

    while (k--) {
      printf("%c%c%.2d", stck[k].c1, stck[k].c2, stck[k].pos);
    }
    printf("E\n");
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
