/* @JUDGE_ID: 19899RK 132 C++ "By Anadan" */
// Bumpy Objects
// Accepted (0.000 seconds with low memory spent)

#include <math.h>
#include <stdio.h>
#include <string.h>
#define SZ 100

int N;
struct Point {
  int x, y;
  inline int operator==(Point &p) const { return (p.x == x && p.y == y); }
} pt[SZ];
int indexx[SZ];

void simplify(Point &p) {
  int x = p.x, y = p.y, gcd = 1;

  if (x < 0) x = -x;
  if (y < 0) y = -y;

  while (x && y) {
    while (!(x & 1) && !(y & 1)) {
      x >>= 1;
      y >>= 1;
      gcd <<= 1;
    }

    while (!(x & 1)) x >>= 1;
    while (!(y & 1)) y >>= 1;
    if (y > x) {
      y -= x;
    } else {
      x -= y;
    }
  }

  if (x) {
    gcd *= x;
  } else {
    gcd *= y;
  }
  if (gcd) {
    p.x /= gcd;
    p.y /= gcd;
    if (p.y < 0) p.x = -p.x, p.y = -p.y;
  }
}

void sort_interval(Point &b, Point &e) {
  if (b.x > e.x || b.y > e.y) {
    Point tmp = b;
    b = e;
    e = tmp;
  }
}

void insert_point(Point &b, Point &e, Point &p1) {
  if (p1.x < b.x || (p1.x == b.x && p1.y < b.y)) b = p1;
  if (p1.x > e.x || (p1.x > e.x && p1.y > e.y)) e = p1;
}

inline double sqr(double x) { return x * x; }

int check_cm(Point &b, Point &e, int xcm, int ycm) {
  double cs = double(xcm - b.x) * double(e.x - b.x) +
              double(ycm - b.y) * double(e.y - b.y);
  double tmp = sqrt(sqr(xcm - b.x) + sqr(ycm - b.y));
  double q = sqrt(sqr(e.x - b.x) + sqr(e.y - b.y));

  if (cs <= 1e-12) return 0;
  cs /= tmp;
  if (cs >= q - 1e-12) return 0;

  return 1;
}

void getconvexhull() {
  int i, j, k;

  for (i = 0; i < N; ++i) indexx[i] = i;
  for (i = 0; i < N; ++i) {
    if (i == N - 1)
      j = 0;
    else
      j = i + 1;
    if (j == N - 1)
      k = 0;
    else
      k = j + 1;
    if ((pt[j].x - pt[i].x) * (pt[k].y - pt[j].y) <
        (pt[k].x - pt[j].x) * (pt[j].y - pt[i].y)) {
      memcpy(pt + j, pt + j + 1, (N - j - 1) * sizeof(Point));
      memcpy(indexx + j, indexx + j + 1, (N - j - 1) * sizeof(int));
      --N;
      --i;
    }
  }
}

int main() {
  char str[32];
  int xcm, ycm, i, j, k, min, cur;
  Point p0, p1, b, e;

  while (scanf("%s\n", str) == 1) {
    if (str[0] == '#' && str[1] == 0) break;
    scanf("%d%d", &xcm, &ycm);
    N = 0;
    while (scanf("%d%d", &i, &j) == 2) {
      if (i == 0 && j == 0) break;
      pt[N].x = i;
      pt[N].y = j;
      ++N;
    }

    min = SZ + 1;
    getconvexhull();
    for (i = 0; i < N; ++i) {
      if (i == N - 1) {
        j = 0;
        cur = indexx[i];
      } else
        j = i + 1, cur = indexx[j];

      b = pt[i];
      e = pt[j];
      sort_interval(b, e);
      p0.x = pt[j].x - pt[i].x;
      p0.y = pt[j].y - pt[i].y;
      simplify(p0);
      for (k = 0; k < N; ++k) {
        p1.x = pt[k].x - pt[i].x;
        p1.y = pt[k].y - pt[i].y;
        simplify(p1);
        if (p0 == p1) {
          insert_point(b, e, pt[k]);
          if (indexx[k] > cur) cur = indexx[k];
          if (cur >= min) break;
        }
      }

      if (cur < min && check_cm(b, e, xcm, ycm)) {
        min = cur;
      }
    }

    printf("%-20s %d\n", str, min + 1);
  }

  return 0;
}

/* @END_OF_SOURCE_CODE */
