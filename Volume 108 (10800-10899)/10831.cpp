/* @JUDGE_ID: 19899RK 10831 C++ "By Anadan" */
// Gerg's Cake
// Theory: http://mathworld.wolfram.com/QuadraticResidue.html
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;

int intPowMod(int x, int power, int mod) {
	int res = 1, intermediate = x;
	qword tmp;

	if (power < 1) return 1;
	while (power) {
		if (power & 1) {
			tmp = res * qword(intermediate);
			res = int(tmp % mod);
			--power;
		} else {
			tmp = intermediate * qword(intermediate);
			intermediate = int(tmp % mod);
			power >>= 1;
		}
	}
	return res;
}

int main() {
	int a, p;

	while (scanf("%d%d", &a, &p) == 2 && a >= 0) {
		a %= p;
		if (p < 3 || a == 0 || intPowMod(a, p/2, p) == 1) puts("Yes");
		else puts("No");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
