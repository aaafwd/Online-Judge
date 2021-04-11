/* @JUDGE_ID: 19899RK 650 C++ "By Anadan" */
// Bowl
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int getbonus(char *str, int n) {
  int i, j;

  if (n == 1) {
    if (sscanf(str, "%d", &i) == 1) return 10 - i;
    return -1;
  } else {
    if (sscanf(str, "%d%d", &i, &j) != 2) return -1;
    if (i == 0) return 20 - j;
    return 10 - j;
  }
}

int main() {
  int off, i;
  char tmp[4], str[81], *p, *q = NULL;
  int score[10], N, spaces;

  while (scanf("%s", str) == 1) {
    if (q) putchar('\n');
    printf("%s", str);
    spaces = 12 - strlen(str);

    N = 0;
    p = fgets(str, sizeof(str), stdin);
    while (sscanf(p, "%d%n", &i, &off) == 1) {
      for (; spaces > 0; --spaces) putchar(' ');
      q = tmp;
      p += off;
      if (i == 0) {
        *q++ = 'X';
        i = getbonus(p, 2);
        if (N == 9) {
          if (i != -1) score[N++] = i + 10;
          i = off = -1;
          sscanf(p, "%d%d", &i, &off);
          *p = 0;
          if (i != -1) {
            if (i == 0) {
              *q++ = 'X';
              if (off != -1) {
                if (off == 0) {
                  *q++ = 'X';
                } else {
                  *q++ = '0' + 10 - off;
                }
              }
            } else {
              if (i == 10) {
                *q++ = '-';
              } else {
                *q++ = '0' + 10 - i;
              }
              if (off != -1) {
                if (off == 0) {
                  *q++ = '/';
                } else if (i == off) {
                  *q++ = '-';
                } else {
                  *q++ = i - off;
                }
              }
            }
          }
        } else if (i != -1) {
          score[N++] = i + 10;
        }
      } else {
        if (i == 10) {
          *q++ = '-';
        } else {
          *q++ = '0' + 10 - i;
        }
        score[N] = i;
        if (sscanf(p, "%d%n", &i, &off) == 1) {
          p += off;
          if (i == 0) {
            *q++ = '/';
            i = getbonus(p, 1);
            if (N == 9) {
              off = -1;
              sscanf(p, "%d", &off);
              *p = 0;
              if (off == 0) {
                *q++ = 'X';
              } else if (off == 10) {
                *q++ = '-';
              } else if (off != -1) {
                *q++ = '0' + 10 - off;
              }
            }
            if (i != -1) score[N++] = i + 10;
          } else {
            if (score[N] == i) {
              *q++ = '-';
            } else {
              *q++ = '0' + score[N] - i;
            }
            score[N++] = 10 - i;
          }
        }
      }

      *q = 0;
      printf(" %s", tmp);
      spaces = 3 - strlen(tmp);
    }
    putchar('\n');

    if (N) printf("%-12s %3d", "", score[0]);
    for (i = 1; i < N; ++i) {
      score[i] += score[i - 1];
      printf(" %3d", score[i]);
    }
    putchar('\n');
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
