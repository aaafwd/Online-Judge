/* @JUDGE_ID: 19899RK 10495 C++ "By Anadan" */ 
// Conic Distance
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

inline double sqr(double x) { return x * x; }

int main(){
	double r, h, d1, a1, d2, a2;
	const double coeff = acos(0.0) / 90.0;

	while (scanf("%lf%lf%lf%lf%lf%lf", &r, &h, &d1, &a1, &d2, &a2) == 6){
		a1 -= a2;
		if (a1 < 0) a1 = -a1;
		if (a1 > 180) a1 = 360 - a1;
		a1 *= coeff * r / sqrt(r * r + h * h);
		a2 = sqrt(sqr(d2 * cos(a1) - d1) + sqr(d2 * sin(a1)));
		printf("%.2lf\n", a2);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
