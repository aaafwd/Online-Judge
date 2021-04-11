/* @JUDGE_ID: 19899RK 10852 C++ "By Anadan" */
// Less Prime
// Accepted (0.422 seconds using as much as 468 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 10001

int res[SZ], primes[SZ], sp;
char mask[SZ];

void precalc() {
	int i, j, tmp, rest;

	sp = 0;
	memset(mask, 1, sizeof(mask));
	for (i = 2; i < SZ; ++i) {
		if (!mask[i]) continue;
		primes[sp++] = i;
		for (j = i + i; j < SZ; j += i) mask[j] = 0;
	}

	for (i = 2; i < SZ; ++i) {
		res[i] = 2;
		rest = i % res[i];
		for (j = 0; j < sp && primes[j] < i; ++j) {
			tmp = i % primes[j];
			if (rest <= tmp) {
				rest = tmp;
				res[i] = primes[j];
			}
		}
	}
}

int main() {
	int set, i;

	precalc();

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &i);
		printf("%d\n", res[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
