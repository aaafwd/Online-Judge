/* @JUDGE_ID: 19899RK 10699 C++ "By Anadan" */
// Count the factors
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 1024

char mask[SZ];
void primeSieve() {
	int i, j;
	memset(mask, 1, sizeof(mask));
	mask[0] = mask[1] = 0;
	for (i = 2; i < SZ; ++i) {
		if (mask[i] == 0) continue;
		for (j = i + i; j < SZ; j += i) mask[j] = 0;
	}
}

int main() {
	int N, res, i;

	primeSieve();
	while (scanf("%d", &N) && N) {
		printf("%d : ", N);
		res = 0;
		for (i = 2; i*i <= N; ++i) {
			if (mask[i] == 0) continue;
			if (!(N%i)) {
				++res;
				while (!(N%i)) N /= i;
			}
		}
		if (N != 1) ++res;
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
