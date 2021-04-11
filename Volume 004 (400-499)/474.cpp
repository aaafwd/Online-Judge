/* @JUDGE_ID: 19899RK 474 C++ "By Anadan" */ 
// Heads / Tails Probability
// Accepted (0.130 seconds using as much as 404 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
	double r, integer;

	while (scanf("%lf", &r) > 0){
		printf("2^-%.0lf = ", r);
		if (r == 6.0) { printf("1.562e-2\n"); continue; }
		r *= log(2.0) / log(10.0);
		r = modf(r, &integer);
		r = pow(10.0, 1.0 - r);
		printf("%.3lfe-%.0lf\n", r, integer + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
