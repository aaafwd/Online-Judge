/* @JUDGE_ID: 19899RK 267 C++ "By Anadan" */
// Of(f) Course!
// Accepted (0.030 seconds with low memory spent)

#include <math.h>
#include <stdio.h>

int main() {
  double w, a, b, v, r, c, sin_ab, cos_ab;
  const double pi_180 = acos(0.0) / 90.0;

  while (scanf("%lf%lf%lf%lf", &w, &a, &b, &v) == 4) {
    printf("WIND SPEED %.2lf\n", w);
    printf("WIND DIRECTION %.2lf\n", a);
    printf("DESIRED COURSE %.2lf\n", b);
    printf("TRUE AIRSPEED %.2lf\n", v);
    a *= pi_180;
    b *= pi_180;

    // Slower implementation (0.060 seconds):
    //   r = v * v - sqr(w * sin(a - b));
    //   if (r < 0.0) r = 0.0;
    //   r = sqrt(r) - w * cos(a - b);
    //   c = atan2(r * sin(b) + w * sin(a), r * cos(b) + w * cos(a));

    if (w < 1e-9) {
      r = v;
      c = b;
    } else {
      sin_ab = sin(a - b);
      cos_ab = cos(a - b);
      v /= w;
      if (v < sin_ab) {
        r = -w * cos_ab;
        c = atan2(sin(a) - cos_ab * sin(b), cos(a) - cos_ab * cos(b));
      } else {
        r = sqrt(v * v - sin_ab * sin_ab) - cos_ab;
        c = atan2(r * sin(b) + sin(a), r * cos(b) + cos(a));
        r *= w;
      }
    }
    c /= pi_180;
    if (c < 0) c += 360.0;
    printf("AIRCRAFT HEADING %.2lf\n", c);
    printf("GROUND SPEED %.2lf\n\n", r);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

