/* @JUDGE_ID: 19899RK 10105 C++ "By Anadan" */
// Polynomial coefficients
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, n, k, tmp;
	long denom, factors[13];

	factors[0] = 1L;
	for (i = 1; i < 13; i++) factors[i] = factors[i - 1] * i;
	while (scanf("%d%d", &n, &k) == 2){
		denom = 1L;
		for (i = 0; i < k; i++){
			scanf("%d", &tmp);
			denom *= factors[tmp];
		}
		printf("%ld\n", factors[n] / denom);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
