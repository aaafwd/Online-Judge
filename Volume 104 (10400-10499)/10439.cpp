/* @JUDGE_ID: 19899RK 10439 C++ "By Anadan" */ 
// Temple of Dune
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

inline double sqr(double x) { return x * x; }

int isint(double a){
	a -= floor(a);
	if (a > 0.5) a = 1.0 - a;
	return (a < 1e-5);
}

int main(){
	int set, N;
	double xa, ya, xb, yb, xc, yc, x0, y0, det, s, t;
	const double pi_2 = acos(0.0) * 4.0, i_pi_2 = 1.0 / pi_2;

	scanf("%d\n", &set);
	while (set--){
		scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);
		det = (ya-yb)*(xc-xa) - (xa-xb)*(yc-ya);
		t = ((xc-xb)*(xc-xa) - (yb-yc)*(yc-ya)) * 0.5 / det;
		x0 = (xa+xb) * 0.5 + (ya-yb) * t;
		y0 = (ya+yb) * 0.5 + (xb-xa) * t;
		xa -= x0; ya -= y0; xb -= x0; yb -= y0; xc -= x0; yc -= y0;
		det = 1.0 / sqrt(xa*xa + ya*ya);
		s = acos((xa*xb + ya*yb) * det / sqrt(xb*xb + yb*yb));
		t = acos((xa*xc + ya*yc) * det / sqrt(xc*xc + yc*yc));
		if (s < 0.0) s += pi_2;
		if (t < 0.0) t += pi_2;
		s *= i_pi_2; t *= i_pi_2;

		for (N = 3; N < 201; ++N){
			if (isint(s * N) && isint(t * N)) break;
		}

		printf("%d\n", N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
