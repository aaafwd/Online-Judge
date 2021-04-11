/* @JUDGE_ID: 19899RK 11000 C++ "By Anadan" */
// Bee
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#define SZ 64

int main() {
	int N, i;
	unsigned int m[SZ], f[SZ];

	// Precalc
	m[0] = f[0] = 0;
	for (i = 1; i < SZ; ++i) {
		m[i] = m[i-1] + f[i-1] + 1;
		f[i] = m[i-1];
	}

	while (scanf("%d", &N) == 1 && N >= 0) {
		printf("%u %u\n", m[N], m[N] + f[N] + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
