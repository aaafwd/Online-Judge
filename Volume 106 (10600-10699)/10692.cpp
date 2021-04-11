/* @JUDGE_ID: 19899RK 10692 C++ "By Anadan" */
// Huge Mods
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int powersLess(int * powers, int N, int x) {
	int i, tmp = 1;
	if (N == 1 || powers[0] <= 1) return (powers[0] < x);
	for (i = 0 ;; ++i, tmp *= powers[0]) {
		if (tmp >= x) break;
	}
	return powersLess(powers+1, N-1, i);
}

/**
 * Calculates: <code>powers[] mod M</code>
 * where powers[] = p1^p2^p3^...^pN
 */
int hugeMod(int * powers, int N, int M) {
	int res, i, k, p, tmp, *rest;
	static char mask[10240];

	if (N == 1) return (powers[0] % M);
	rest = new int[M];
	memset(mask, 0, M);

	rest[0] = 1;
	mask[1] = 1;
	for (i = 1 ;; ++i) {
		tmp = (rest[i-1] * powers[0]) % M;
		if (mask[tmp]) break;
		rest[i] = tmp;
		mask[tmp] = 1;
	}

	for (k = 0; rest[k] != tmp; ++k);
	p = i - k;

	tmp = hugeMod(powers+1, N-1, p);
	if (powersLess(powers+1, N-1, k)) {
		res = rest[tmp];
	} else {
		tmp -= k;
		if (tmp < 0) tmp += ((-tmp + p - 1)/p) * p;
		res = rest[k + tmp%p];
	}

	delete [] rest;
	return res;
}

int main() {
	int set = 0, N, M, i, powers[16];

	while (scanf("%d%d", &M, &N) == 2) {
		for (i = 0; i < N; ++i) scanf("%d", powers+i);
		i = hugeMod(powers, N, M);
		printf("Case #%d: %d\n", ++set, i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
