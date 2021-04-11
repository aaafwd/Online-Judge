/* @JUDGE_ID: 19899RK 113 C++ "By Anadan" */
// Power of Cryptography
// Accepted (0.010 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
	int n;
	long double p, res;

	while (scanf("%d%Lf", &n, &p) == 2){
		res = log(p) / double(n);
		res = floor(exp(res) + 0.5);
		printf("%.0Lf\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
