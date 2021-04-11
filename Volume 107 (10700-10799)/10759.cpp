/* @JUDGE_ID: 19899RK 10759 C++ "By Anadan" */
// Dice Throwing
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

typedef unsigned long long qword;
qword res[25][150], a, b;

void calcResult(int n, int x) {
	int p2 = n, p3 = n;
	a = res[n][x];
	while (!(a&1) && p2 > 0) {
		a >>= 1;
		--p2;
	}
	while (!(a%3) && p3 > 0) {
		a /= 3;
		--p3;
	}
	b = 1;
	while (p2--) b <<= 1;
	while (p3--) b *= 3;
}

int main() {
	int i, j, k;

	for (i = 1; i < 150; ++i) res[0][i] = 0;
	res[0][0] = 1;

	for (i = 1; i < 25; ++i) {
		res[i][0] = res[i-1][0] * 6;
		for (j = 1; j <= i; ++j) res[i][j] = res[i][0];
		for (; j < 150; ++j) {
			res[i][j] = 0;
			for (k = 1; k <= 6; ++k) {
				if (j >= k) res[i][j] += res[i-1][j-k];
				else res[i][j] += res[i-1][0];
			}
		}
	}

	while (scanf("%d%d", &i, &j) == 2 && i) {
		calcResult(i, j);
		if (a == 0 || b == 1) printf("%llu\n", a);
		else printf("%llu/%llu\n", a, b);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
