/* @JUDGE_ID: 19899RK 10326 C++ "By Anadan" */
// The Polynomial Equation
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;

int main(){
	int N, i, j;
	qword nums[51], q;

	while (scanf("%d\n", &N) == 1){
		nums[0] = 1;
		for (i = 1; i <= N; ++i){
			nums[i] = 0;
			scanf("%lld", &q);
			for (j = i; j > 0; --j) nums[j] -= q * nums[j - 1];
		}

		putchar('x');
		if (N != 1) printf("^%d", N);
		for (i = 1; i < N; ++i){
			if (nums[i] == 0) continue;
			if (nums[i] > 0) printf(" + ");
			else printf(" - "), nums[i] = -nums[i];
			if (nums[i] != 1) printf("%lld", nums[i]);
			putchar('x');
			if (N - i != 1) printf("^%d", N - i);
		}

		if (nums[i] >= 0) printf(" + ");
		else printf(" - "), nums[i] = -nums[i];
		printf("%lld = 0\n", nums[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
