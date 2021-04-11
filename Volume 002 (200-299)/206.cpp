/* @JUDGE_ID: 19899RK 206 C++ "By Anadan" */
// Meals on Wheels Routing System
// Accepted (0.030 seconds using as much as 660 kbytes)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 5000

struct Customer {
  char *name;
  int x, y;
  double f;
} pt[MAXN];
char names[MAXN][32];
int N;

const double pi = acos(0.0) * 2.0;
inline int _abs(int x) { return (x < 0) ? (-x) : (x); }

int sort_function(const void *a, const void *b) {
  Customer *ca = (Customer *)a, *cb = (Customer *)b;
  if (fabs(ca->f - cb->f) < 1e-12) {
    if (double(ca->x) * ca->x + double(ca->y) * ca->y <
        double(cb->x) * cb->x + double(cb->y) * cb->y) {
      return -1;
    }
    return 1;
  }
  if (ca->f < cb->f) return -1;
  return 1;
}

void consume_endline(char *p) {
  p += strlen(p) - 1;
  if (*p == '\n') *p = 0;
}

int main() {
  int routes, i, j, k, m, len, tot = -1;
  char str[128];

  while (fgets(str, sizeof(str), stdin)) {
    consume_endline(str);
    if (tot != -1) puts("***********************************");
    puts(str);
    scanf("%d%d", &routes, &N);
    while ((j = getchar()) != EOF && j != '\n');
    printf("Number of Customers: %-10d Number of Routes: %d\n\n", N, routes);
    for (i = 0; i < N; ++i) {
      fgets(names[i], sizeof(names[i]), stdin);
      consume_endline(names[i]);
      pt[i].name = names[i];
      scanf("%d%d", &pt[i].x, &pt[i].y);
      while ((j = getchar()) != EOF && j != '\n');
      if (pt[i].x >= 0) {
        pt[i].f = atan2(pt[i].y, pt[i].x);
        if (pt[i].y < 0) pt[i].f += pi + pi;
      } else {
        pt[i].f = pi - atan2(pt[i].y, -pt[i].x);
      }
    }

    qsort(pt, N, sizeof(Customer), sort_function);
    for (tot = j = i = 0; i < routes; ++i) {
      printf("Route ==> %d\n", i + 1);
      k = (N - j + routes - i - 1) / (routes - i);
      len = 0;
      for (m = 0; m < k; ++m) {
        printf("Customer: %s\n", pt[j].name);
        if (m == 0) {
          len += _abs(pt[j].x) + _abs(pt[j].y);
        } else {
          len += _abs(pt[j - 1].x - pt[j].x) + _abs(pt[j - 1].y - pt[j].y);
        }
        ++j;
      }
      if (k) len += _abs(pt[j - 1].x) + _abs(pt[j - 1].y);
      printf("Route Length ==> %d\n\n", len);
      tot += len;
    }

    printf("Total Route Length ==> %d\n", tot);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
