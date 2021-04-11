/* @JUDGE_ID: 19899RK 10879 C++ "By Anadan" */
// Code Refactoring
// Accepted (0.146 seconds using as much as 404 kbytes)

#include <stdio.h>
#define MAX 3200

int primes[MAX], sp;

void init() {
	int i, j;

	sp = 1;
	primes[0] = 2;
	for (i = 3; i < MAX; i += 2) {
		for (j = 1; j < sp && primes[j]*primes[j] <= i; ++j) {
			if (!(i % primes[j])) { j = -1; break; }
		}
		if (j > 0) {
			primes[sp++] = i;
		}
	}
}

int main() {
	int set, cs = 0, N, sN, A, B, i;

	init();

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		printf("Case #%d: %d = ", ++cs, N);
		sN = N;

		B = -1;
		for (i = 0 ;; ++i) {
			if (!(N % primes[i])) {
				A = primes[i];
				N /= primes[i];
				if (!(N % primes[i])) {
					B = A*A;
				}
				break;
			}
		}
		if (B == -1) {
			for (++i ;; ++i) {
				if (!(N % primes[i])) {
					B = primes[i];
					break;
				}
			}
		}
		printf("%d * %d = %d * %d\n", A, sN/A, B, sN/B);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
