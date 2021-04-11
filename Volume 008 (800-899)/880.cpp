/* @JUDGE_ID: 19899RK 880 C++ "By Anadan" */
// Cantor Fractions
// Accepted (0.375 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>

int main() {
	long long M, N, i;

	while (scanf("%lld", &M) == 1) {
		N = (long long)((sqrt(1 + M*8) - 1) * 0.5);
		i = N*(N+1)/2;
		if (i >= M) i -= N--;
		printf("%lld/%lld\n", N+2-M+i, M-i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
