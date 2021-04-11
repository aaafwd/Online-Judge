/* @JUDGE_ID: 19899RK 10221 C++ "By Anadan" */
// Satellites
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	long s, a;
	char angle[4];
	double tmp;
	const double coeff = acos(0.0) / 5400.0;

	while (scanf("%ld %ld %s\n", &s, &a, angle) == 3){
		s += 6440;
		if (angle[0] == 'd') a *= 60;
		a %= 21600;
		if (a > 10800) a = 21600 - a;
		tmp = coeff * double(a);
		printf("%.6lf %.6lf\n", tmp * s, 2.0 * s * sin(tmp * 0.5));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
