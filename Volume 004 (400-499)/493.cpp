/* @JUDGE_ID: 19899RK 493 C++ "By Anadan" */
// Rational Spiral
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#define SZ 43010

int coprimes[SZ];

void precalc() {
	int i, j;

	for (i = 0; i < SZ; ++i) coprimes[i] = i;
	for (i = 2; i < SZ; ++i) {
		if (coprimes[i] == i) {
			for (j = i; j < SZ; j += i) {
				coprimes[j] = coprimes[j] / i * (i - 1);
			}
		}
		coprimes[i] <<= 2;
	}
}

int gcd(int a, int b) {
	while (a && b) if (a > b) a %= b; else b %= a;
	return a + b;
}

void printResult(int n) {
	int i, j, tmp, coprimeNum, flagNumerator = 0;

	for (i = 2; i < SZ; ++i) {
		if (n < coprimes[i]) break;
		n -= coprimes[i];
	}

	tmp = coprimes[i] >> 2;
	if (n < tmp) {
		putchar('-');
		coprimeNum = tmp - n - 1;
	} else {
		n -= tmp;
		if (n < tmp) {
			coprimeNum = n;
		} else {
			n -= tmp;
			flagNumerator = 1;
			if (n < tmp) {
				coprimeNum = tmp - n - 1;
			} else {
				putchar('-');
				coprimeNum = n - tmp;
			}
		}
	}

	for (j = 1 ;; ++j) {
		if (gcd(i, j) == 1) {
			if (coprimeNum-- == 0) break;
		}
	}

	if (flagNumerator) printf("%d / %d\n", j, i);
	else printf("%d / %d\n", i, j);
}

int main() {
	int i;

	precalc();
	while (scanf("%d", &i) == 1) {
		if (i == 0) puts("1 / 1");
		else if (i == 1) puts("0 / 1");
		else if (i == 2) puts("-1 / 1");
		else printResult(i - 3);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
