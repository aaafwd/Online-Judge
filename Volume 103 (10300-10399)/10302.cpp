/* @JUDGE_ID: 19899RK 10302 C++ "By Anadan" */
// Summation of Polynomials
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	long double x;

	while (scanf("%Lf\n", &x) == 1){
		x = x * (x + 1.0) * 0.5;
		printf("%.0Lf\n", x * x);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
