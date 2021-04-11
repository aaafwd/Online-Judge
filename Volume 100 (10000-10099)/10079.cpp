/* @JUDGE_ID: 19899RK 10079 C++ "By Anadan" */
// Pizza Cutting
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	long double N;

	while (scanf("%Lf", &N) > 0){
		if (N < 0) break;
		printf("%.0Lf\n", 0.5 * N * (N + 1.0) + 1.0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
