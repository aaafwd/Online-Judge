/* @JUDGE_ID: 19899RK 10738 C++ "By Anadan" */
// Riemann vs Mertens
// Accepted (0.514 seconds using as much as 6244 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 1000001

char mu[SZ], prime[SZ];
int M[SZ];

void precalc() {
	int i, j;

	memset(mu, 1, sizeof(mu));
	memset(prime, 1, sizeof(prime));

	M[1] = 1;
	for (i = 2; i < SZ; ++i) {
		if (prime[i]) {
			mu[i] = -1;
			for (j = i + i; j < SZ; j += i) {
				prime[j] = 0;
				if (mu[j]) {
					if (!((j/i)%i)) mu[j] = 0;
					else mu[j] = -mu[j];
				}
			}
		}
		M[i] = M[i-1] + mu[i];
	}
}

int main() {
	int N;

	precalc();

	while (scanf("%d", &N) == 1 && N) {
		printf("%8d%8d%8d\n", N, int(mu[N]), M[N]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
