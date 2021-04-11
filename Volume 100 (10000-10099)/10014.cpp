/* @JUDGE_ID: 19899RK 10014 C++ "By Anadan" */
// Simple calculations
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, n;
	double a0, a1, c, R, sum, rest;
	long set;
	scanf("%ld\n\n", &set);

	while(set--){
		scanf("%d %lf %lf", &n, &a0, &a1);
		if (n == 0){
			printf("%.2lf\n", a1);
			continue;
		}
		scanf("%lf", &c); c *= 2.0;
		sum = c;
		R = c - a0;
		rest = 2.0;
		for (i = 1; i < n; i++){
			scanf("%lf", &c); c *= 2.0;
			sum += c;
			R = c + R / rest;
			rest = 2.0 - 1.0 / rest;
		}
		rest = (R - a1) / rest + a0 + a1 - sum;
		printf("%.2lf\n", rest);
		if (set) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
