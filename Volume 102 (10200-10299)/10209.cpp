/* @JUDGE_ID: 19899RK 10209 C++ "By Anadan" */
// Is This Integration ?
// Accepted (0.200 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
	double a;
	const double pi_3 = acos(0.5);
	const double c1 = pi_3 - sqrt(3.0) + 1.0;
	const double c2 = pi_3 + 2.0 * sqrt(3.0) - 4.0;
	const double c3 = 4.0 - sqrt(3.0) - 2.0 * pi_3;

	while (scanf("%lf", &a) > 0){
		a *= a;
		printf("%.3lf %.3lf %.3lf\n", a * c1, a * c2, a * c3);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
