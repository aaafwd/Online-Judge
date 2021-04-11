/* @JUDGE_ID: 19899RK 190 C++ "By Anadan" */
// Circle Through Three Points
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

inline double sqr(double x) { return x * x; }

inline void doround(double &x){
	x = floor(x * 1000.0 + 0.5) * 0.001;
	if (fabs(x) < 1e-5) x = 0.0;
}

inline void putsign(double &x){
	if (x < 0.0){
		putchar('-');
		x = -x;
	}else putchar('+');
}

int main(){
	double xa, ya, xb, yb, xc, yc;
	double det, t, h, k, r, c, d, e;

	while (scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc) == 6){
		det = (ya-yb)*(xc-xa) - (xa-xb)*(yc-ya);
		t = ((xc-xb)*(xc-xa) - (yb-yc)*(yc-ya)) * 0.5 / det;
		h = -(xa+xb) * 0.5 - (ya-yb) * t;
		k = -(ya+yb) * 0.5 - (xb-xa) * t;
		e = sqr(h+xa) + sqr(k+ya);
		r = sqrt(e);
		c = h * 2.0;
		d = k * 2.0;
		e = h*h + k*k - e;
		doround(h);
		doround(k);
		doround(c);
		doround(d);
		doround(e);

		printf("(x ");
		putsign(h); printf(" %.3lf)^2 + (y ", h);
		putsign(k); printf(" %.3lf)^2 = %.3lf^2\n", k, r);
		printf("x^2 + y^2 ");
		putsign(c); printf(" %.3lfx ", c);
		putsign(d); printf(" %.3lfy ", d);
		putsign(e); printf(" %.3lf = 0\n\n", e);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
