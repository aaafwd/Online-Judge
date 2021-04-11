/* @JUDGE_ID: 19899RK 143 C++ "By Anadan" */
// Orchard Trees
// Accepted (0.080 seconds using as much as 396 kbytes)

#include <math.h>
#include <stdio.h>
#define EPS 10e-12

int inTriangle(double x, double y, const double& x1, const double& y1,
               const double& x2, const double& y2, const double& x3,
               const double& y3, const double& s02) {
  double s12 = fabs((y3 - y) * (x2 - x) - (y2 - y) * (x3 - x));
  double s22 = fabs((y3 - y1) * (x - x1) - (y - y1) * (x3 - x1));
  double s32 = fabs((y - y1) * (x2 - x1) - (y2 - y1) * (x - x1));

  if (s02) {
    s12 += s22;
    s12 += s32;
    if (fabs(s12 - s02) < EPS) return 1;
    return 0;
  } else {
    double min, max;
    if (s12 || s22 || s32) return 0;
    min = x1;
    if (x2 < min) min = x2;
    if (x3 < min) min = x3;
    max = x1;
    if (x2 > max) max = x2;
    if (x3 > max) max = x3;
    if (fabs(min - max) < EPS) {
      x = y;
      min = y1;
      if (y2 < min) min = y2;
      if (y3 < min) min = y3;
      max = y1;
      if (y2 > max) max = y2;
      if (y3 > max) max = y3;
    }
    if ((x < min) || (x > max)) return 0;
    return 1;
  }
}

int main() {
  int res;
  double xmin, xmax, ymin, ymax, x, y;
  double x1, y1, x2, y2, x3, y3, s02;

  while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
    if ((!x1) && (!y1) && (!x2) && (!y2) && (!x3) && (!y3)) break;
    xmin = x1;
    xmax = x1;
    if (x2 < xmin) xmin = x2;
    if (x2 > xmax) xmax = x2;
    if (x3 < xmin) xmin = x3;
    if (x3 > xmax) xmax = x3;

    ymin = y1;
    ymax = y1;
    if (y2 < ymin) ymin = y2;
    if (y2 > ymax) ymax = y2;
    if (y3 < ymin) ymin = y3;
    if (y3 > ymax) ymax = y3;

    xmin = ceil(xmin);
    ymin = ceil(ymin);
    xmax = floor(xmax);
    ymax = floor(ymax);
    if (xmin < 1.0) xmin = 1.0;
    if (ymin < 1.0) ymin = 1.0;
    if (xmax > 99.0) xmax = 99.0;
    if (ymax > 99.0) ymax = 99.0;

    s02 = fabs((y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1));
    res = 0;
    for (x = xmin; x <= xmax; x++) {
      for (y = ymin; y <= ymax; y++) {
        if (inTriangle(x, y, x1, y1, x2, y2, x3, y3, s02)) res++;
      }
    }
    printf("%4d\n", res);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
