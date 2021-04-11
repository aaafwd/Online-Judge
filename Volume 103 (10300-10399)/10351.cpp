/* @JUDGE_ID: 19899RK 10351 C++ "By Anadan" */
// Cutting Diamonds
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

inline double sqr(double x) { return x * x; }

int main(){
	int a, b, c, x, y, z, set = 0;
	double S;
	const double pi_4 = acos(0.0) * 0.5;

	while (scanf("%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c) == 6){
		S = pi_4;
		if (x < a) S *= double(b) * c * (1.0 - sqr(2.0 * double(x) / double(a) - 1.0));
		else if (y < b) S *= double(a) * c * (1.0 - sqr(2.0 * double(y) / double(b) - 1.0));
		else if (z < c) S *= double(a) * b * (1.0 - sqr(2.0 * double(z) / double(c) - 1.0));
		else S = 0.0;
		printf("Set #%d\n%.6lf\n", ++set, S);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
