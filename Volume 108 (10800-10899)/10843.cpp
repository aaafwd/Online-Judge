/* @JUDGE_ID: 19899RK 10843 C++ "By Anadan" */
// Anne's game
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#define MOD 2000000011

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
	int set, cs = 0, N;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		printf("Case #%d: %d\n", ++cs, intPowMod(N, N-2, MOD));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
