/* @JUDGE_ID: 19899RK 10780 C++ "By Anadan" */
// Again Prime? No time.
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

int primes[64], powers[64], sp;

void factor(int N) {
	int i;

	sp = 0;
	if (!(N&1)) {
		++sp;
		primes[0] = 2;
		powers[0] = 0;
		while (!(N&1)) {
			N >>= 1;
			++powers[0];
		}
	}

	for (i = 3; i*i <= N; i += 2) {
		if (N%i) continue;
		primes[sp] = i;
		powers[sp] = 0;
		while (!(N%i)) {
			N /= i;
			++powers[sp];
		}
		++sp;
	}

	if (N != 1) {
		primes[sp] = N;
		powers[sp++] = 1;
	}
}

int getFactorialPower(int N, int prime) {
	int res = 0;

	while (N) {
		N /= prime;
		res += N;
	}
	
	return res;
}

int main() {
	int set, cs = 0, N, M, i, res, tmp;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &M, &N);
		factor(M);
		res = N << 1;
		for (i = 0; i < sp; ++i) {
			tmp = getFactorialPower(N, primes[i]);
			if (res > tmp / powers[i]) res = tmp / powers[i];
		}

		printf("Case %d:\n", ++cs);
		if (res) printf("%d\n", res);
		else puts("Impossible to divide");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
