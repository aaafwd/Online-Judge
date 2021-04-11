/* @JUDGE_ID: 19899RK 255 C++ "By Anadan" */
// Correct Move
// Accepted (0.020 seconds using as much as 384 kbytes)

#include <stdio.h>

#include <algorithm>

int k1, q1, q2, x0, y0;

int legal() {
  int x1, y1, x2, y2;

  x0 = k1 >> 3;
  y0 = k1 & 7;
  x1 = q1 >> 3;
  y1 = q1 & 7;
  x2 = q2 >> 3;
  y2 = q2 & 7;

  if (x1 == x2) {
    if (y1 == y2) return 0;
    if (y1 > y2) std::swap(y1, y2);
    if (x0 == x1 && y1 <= y0 && y0 <= y2) return 0;
  } else if (y1 == y2) {
    if (x1 > x2) std::swap(x1, x2);
    if (y0 == y1 && x1 <= x0 && x0 <= x2) return 0;
  } else {
    return 0;
  }
  return 1;
}

int allowed() {
  int x2 = q2 >> 3;
  int y2 = q2 & 7;

  if (x2 == x0) {
    if (y2 == y0 - 1 || y2 == y0 + 1) return 0;
  } else if (y2 == y0) {
    if (x2 == x0 - 1 || x2 == x0 + 1) return 0;
  }

  return 1;
}

int blocked() {
  int x = x0, y = y0;

  x0 = x + 1;
  y0 = y;
  if (x0 <= 7 && allowed()) return 0;

  x0 = x - 1;
  y0 = y;
  if (x0 >= 0 && allowed()) return 0;

  x0 = x;
  y0 = y + 1;
  if (y0 <= 7 && allowed()) return 0;

  x0 = x;
  y0 = y - 1;
  if (y0 >= 0 && allowed()) return 0;

  return 1;
}

int main() {
  while (scanf("%d%d%d\n", &k1, &q1, &q2) == 3) {
    if (k1 == q1) {
      puts("Illegal state");
    } else if (!legal()) {
      puts("Illegal move");
    } else if (!allowed()) {
      puts("Move not allowed");
    } else if (blocked()) {
      puts("Stop");
    } else {
      puts("Continue");
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

