/* @JUDGE_ID: 19899RK 10247 C++ "By Anadan" */
// Complete Tree Labeling!
// Accepted (0.635 seconds using as much as 424 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 1500

int primes[SZ], powers[SZ];

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void mul(char *p, int a){
	int rest = 0;

	while (*p){
		rest += (*p - '0') * a;
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	while (rest){
		*p++ = '0' + (rest % 10);
		rest /= 10;
	}

	*p = 0;
}

void mulPowers(char *p, int a, int power) {
	int len = 1, pa = a, i;
	const int limit = 214748364;

	while (pa <= limit/a && len < power) {
		pa *= a;
		++len;
	}

	for (i = power/len; i > 0; --i) mul(p, pa);
	for (i = power%len; i > 0; --i) mul(p, a);
}

void precalc() {
	int i, j, sp = 1;
	primes[0] = 2;
	for (i = 3; sp < SZ; i += 2) {
		for (j = 1; j < sp && primes[j]*primes[j] <= i; ++j) {
			if (!(i % primes[j])) { j = -1; break; }
		}
		if (j != -1) primes[sp++] = i;
	}
}

void addPowers(int N, int power) {
	int i, M;
	for (i = 0; primes[i] <= N; ++i) {
		M = N;
		while (M) {
			M /= primes[i];
			powers[i] += M * power;
		}
	}
}

void subPowers(int N, int power) {
	int i, M;
	for (i = 0; primes[i] <= N; ++i) {
		M = N;
		while (M) {
			M /= primes[i];
			powers[i] -= M * power;
		}
	}
}

int main() {
	int k, d, N, i, power;
	char res[16384];

	precalc();

	while (scanf("%d%d", &k, &d) == 2) {
		if (k == 1) N = d;
		else {
			N = 1;
			for (i = 0; i < d; ++i) N *= k;
			N = (N - 1) / (k - 1);
		}
		memset(powers, 0, sizeof(powers));
		power = 1;
		for (i = 0; i < d; ++i) {
			addPowers(k*N, power);
			power *= k;
			subPowers(N, power);
			N = (N - 1) / k;
		}

		strcpy(res, "1");
		for (i = 0; i < SZ; ++i) {
			if (powers[i]){
				mulPowers(res, primes[i], powers[i]);
			}
		}

		_reverse(res);
		puts(res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
