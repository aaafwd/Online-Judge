/* @JUDGE_ID: 19899RK 10668 C++ "By Anadan" */
// Expanding Rods
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

double L, N, C;

double solve() {
	double a1 = 0, a2 = 3.1415926535897932384626433832795, a, tmp;

	while (a2-a1>1e-12) {
		a=(a1+a2)*0.5;
		tmp = sin(a/2)/a - 0.5/(1+N*C);
		if (tmp > 0) a1 = a;
		else a2 = a;
	}

	return L*(1+N*C)/a*(1-cos(a/2));
}

int main() {
	double r;

	while (scanf("%lf%lf%lf", &L, &N, &C) == 3 && L >= 0) {
		r = solve();
		printf("%.3lf\n", r);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
