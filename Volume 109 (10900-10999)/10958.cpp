/* @JUDGE_ID: 19899RK 10958 C++ "By Anadan" */
// How Many Solutions?
// Accepted (0.021 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define MAX 1100

int primes[1000], powers[1100], sp;

void init() {
	int i, j;
	sp = 0;
	primes[sp++] = 2;
	for (i = 3; i < MAX; i += 2) {
		for (j = 0; j < sp && primes[j]*primes[j] <= i; ++j) {
			if (!(i % primes[j])) { j = -1; break; }
		}
		if (j != -1) primes[sp++] = i;
	}
}

void add(int x) {
	int i;
	if (x < 0) x = -x;
	for (i = 0; x > 1 && i < sp; ++i) {
		if (!(x % primes[i])) {
			while (!(x % primes[i])) {
				x /= primes[i];
				++powers[i];
			}
		}
	}
}

int main() {
	int set = 0, m, n, p, i, res;

	init();

	while (scanf("%d%d%d", &m, &n, &p) == 3 && p) {
		memset(powers, 0, sizeof(powers));
		add(n);
		add(m);
		add(p);
		add(p);

		res = 1;
		for (i = 0; i < 1000; ++i) {
			if (powers[i]) res *= (powers[i]+1);
		}
		res += res-1;
		printf("Case %d: %d\n", ++set, res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
