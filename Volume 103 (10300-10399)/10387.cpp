/* @JUDGE_ID: 19899RK 10387 C++ "By Anadan" */
// Billiard
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

inline double sqr(double x) { return x*x; }

int main(){
	int a, b, s, m, n;
	const double todeg = 90.0 / acos(0.0);
	double tmp;

	while (scanf("%d%d%d%d%d", &a, &b, &s, &m, &n) == 5 && a){
		m *= a; n *= b;
		if (m > n) tmp = sqrt(sqr(double(n) / double(m)) + 1.0) * double(m);
		else tmp = sqrt(sqr(double(m) / double(n)) + 1.0) * double(n);
		printf("%.2lf %.2lf\n", atan2(n, m) * todeg, tmp / s);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
