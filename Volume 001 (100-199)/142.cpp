/* @JUDGE_ID: 19899RK 142 C++ "By Anadan" */
// Mouse Clicks
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

struct Region {
  long l, r, t, b;
} rg[25];

struct Icon {
  long x, y;
  bool obscured;
} ic[50];

inline long sqr(long x) { return x * x; }

int inregion(long x, long y, int i) {
  if (x < rg[i].l || x > rg[i].r) return 0;
  if (y < rg[i].t || y > rg[i].b) return 0;
  return 1;
}

int main() {
  int regs = 0, icons = 0, i, j;
  long x, y, min, tmp;
  char cop[2];
  bool marked_obscured = false;

  while (scanf("%s", cop) == 1 && cop[0] != '#') {
    if (cop[0] == 'I') {
      scanf("%ld%ld", &ic[icons].x, &ic[icons].y);
      ic[icons].obscured = false;
      ++icons;
    } else if (cop[0] == 'R') {
      scanf("%ld%ld%ld%ld", &rg[regs].l, &rg[regs].t, &rg[regs].r, &rg[regs].b);
      ++regs;
    } else if (cop[0] == 'M') {
      if (!marked_obscured) {
        marked_obscured = true;
        for (i = 0; i < icons; ++i) {
          for (j = 0; j < regs; ++j) {
            if (inregion(ic[i].x, ic[i].y, j)) {
              ic[i].obscured = true;
              break;
            }
          }
        }
      }
      scanf("%ld%ld", &x, &y);
      for (i = regs - 1; i >= 0; --i) {
        if (inregion(x, y, i)) break;
      }
      if (i >= 0) {
        printf("%c\n", 'A' + i);
      } else {
        min = -1;
        for (i = 0; i < icons; ++i) {
          if (ic[i].obscured) continue;
          tmp = sqr(ic[i].x - x) + sqr(ic[i].y - y);
          if (min == -1 || min > tmp) min = tmp;
        }

        for (i = 0; i < icons; ++i) {
          if (ic[i].obscured) continue;
          tmp = sqr(ic[i].x - x) + sqr(ic[i].y - y);
          if (tmp == min) printf("%3d", i + 1);
        }

        putchar('\n');
      }
    } else {
      return 1;
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

