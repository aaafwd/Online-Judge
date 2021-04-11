/* @JUDGE_ID: 19899RK 10956 C++ "By Anadan" */
// Prime Suspect
// Accepted (3.527 seconds using as much as 508 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 4096

typedef unsigned long long qword;

int primes[SZ];
char mask[100100];

void init() {
	int i, j, sp = 0;
	for (i = 3; sp < SZ; i += 2) {
		for (j = 0; j < sp && primes[j]*primes[j] <= i; ++j) {
			if (!(i % primes[j])) { j = -1; break; }
		}
		if (j != -1) primes[sp++] = i;
	}
}

void setMask(unsigned int min, unsigned int max) {
	int i, toi = max - min + 1;
	unsigned int j;

	for (i = 0; i < SZ; ++i) {
		j = (min / primes[i]) * primes[i];
		if (j <= primes[i]) j = primes[i]*2;
		if (j < min) j += primes[i];
		for (; min <= j && j <= max; j += primes[i]) {
			mask[j - min] = 1;
		}
	}
}

unsigned int powerMod(int a, unsigned int power, unsigned int mod) {
	unsigned int res = a, tmp = a;

	if (!--power) { if (res >= mod) res %= mod; }
	while (power) {
		if (power & 1) {
			if (res < 131072 && tmp < 131072 - res) {
				res *= tmp;
				if (res >= mod) res %= mod;
			} else {
				res = (qword(res)*tmp) % mod;
			}
			power ^= 1;
		} else {
			if (tmp < 65536) {
				tmp *= tmp;
				if (tmp >= mod) tmp %= mod;
			} else {
				tmp = (qword(tmp)*tmp) % mod;
			}
			power >>= 1;
		}
	}
	return res;
}

int suspect(int base, unsigned int n) {
	int t = 0;
	unsigned int s, u, x, x0;

	if (base == n) return 1;

	for (s = n-1; !(s&1); s >>= 1) ++t;

	u = (n-1) >> t;
	x0 = powerMod(base, u, n);

	while (t--) {
		if (x0 < 65536) {
			x = x0 * x0;
			if (x >= n) x %= n;
		} else {
			x = (qword(x0)*x0) % n;
		}
		if (x == 1 && x0 != 1 && x0 != n-1) return 0;
		x0 = x;
	}
	if (x != 1) return 0;
	return 1;
}

int main() {
	int count = -1, res, base;
	unsigned int i, j, max, min;
	unsigned int arr[1024];

	init();

	while (scanf("%d%u%u", &base, &min, &max) == 3 && base) {
		if (count != -1) puts("");

		count = res = 0;
		
		memset(mask, 0, max - min + 1);
		setMask(min, max);

		for (i = min | 1; min <= i && i <= max; i += 2) {
			if (!mask[i-min] && suspect(2,i) && suspect(7,i) && suspect(61,i)) continue;
			++count;
			if (suspect(base,i)) arr[res++] = i;
		}

		printf("There are %d odd non-prime numbers between %u and %u.\n", count, min, max);
		if (res == 0) printf("There are no failures in base %d.\n", base);
		else {
			printf("%d suspects fail in base %d:\n", res, base);
			for (i = 0; i < res; ++i) printf("%u\n", arr[i]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
