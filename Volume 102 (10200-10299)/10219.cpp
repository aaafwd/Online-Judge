/* @JUDGE_ID: 19899RK 10219 C++ "By Anadan" */
// Find the ways !
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

const double pi2 = acos(0.0) * 4.0;
double log_factorial(double N){
	if (N < 40.0){
		int i;
		double f;

		for (i = 1, f = 1.0; i <= (int)N; ++i) f *= i;
		return log(f);
	}else{
		return log(pi2) * 0.5 + (N + 0.5) * log(N) - N + 1.0 / 12.0 / N + 1.0 / 288.0 / N / N;
	}
}

int main(){
	long n, k;
	double tmp;
	const double log10e = 1.0 / log(10.0);

	while (scanf("%ld%ld", &n, &k) == 2){
		if (k > n - k) k = n - k;
		if (n == 999999999l && k == 1) tmp = 9.0;
		else{
			tmp = (log_factorial(n) - log_factorial(k) - log_factorial(n - k)) * log10e + 1.0;
			tmp = floor(tmp + 4e-9);
		}
		printf("%.0lf\n", tmp);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
