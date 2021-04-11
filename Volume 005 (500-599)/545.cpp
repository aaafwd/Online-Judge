/* @JUDGE_ID: 19899RK 545 C++ "By Anadan" */ 
// Heads
// Accepted (0.074 seconds using as much as 404 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
	int set, N;
	double r, integer;
	const double coeff = log(2.0) / log(10.0);

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		printf("2^-%d = ", N);
		r = modf(N * coeff, &integer);
		r = pow(10.0, 1.0 - r);
		printf("%.3lfE-%.0lf\n", r, integer + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
