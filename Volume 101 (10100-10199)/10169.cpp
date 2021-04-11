/* @JUDGE_ID: 19899RK 10169 C++ "By Anadan" */
// Urn-ball Probabilities!
// Accepted (0.220 seconds using as much as 8208 kbytes)

#include <stdio.h>
#include <math.h>
#define MAX 1000000

const double pi2 = acos(0.0) * 4.0;
double log_factorial(double N){
	if (N < 40.0){
		int i;
		double f;
		for (i = 1, f = 1.0; i <= (int)N; ++i) f *= i;
		return log(f);
	}else{
		return log(pi2) * 0.5 + ((N + 0.5) * (log(N * N + N + 1.0 / 6.0) * 0.5 - 1.0));
	}
}

int main(){
	long k;
	double solves[MAX], tmp;

	solves[0] = 0.0;
	for (k = 1, tmp = 1.0; k < MAX; ++k){
		tmp *= 1.0 - 1.0 / double(k) / double(k + 1);
		solves[k] = 1.0 - tmp;
	}

	while (scanf("%ld", &k) > 0){
		tmp = (2.0 * log_factorial(k) + log(k + 1)) / log(10.0);
		printf("%.6lf %.0lf\n", solves[k], floor(tmp));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
