/* @JUDGE_ID: 19899RK 10287 C++ "By Anadan" */
// Gifts in a Hexagonal Box
// Accepted (0.523 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
	double a;
	const double f1 = sqrt(0.75);
	const double f2 = 1.0 / (sqrt(4.0 / 3.0) + 1.0);
	const double f3 = sqrt(0.1875);
	const double f4 = (sqrt(252.0) - sqrt(147.0)) * 0.1;

	while (scanf("%lf\n", &a) == 1){
		printf("%.10lf %.10lf %.10lf %.10lf\n",
			f1*a, f2*a, f3*a, f4*a);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
