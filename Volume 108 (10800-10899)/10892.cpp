/* @JUDGE_ID: 19899RK 10892 C++ "By Anadan" */
// LCM Cardinality
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int primes[32], powers[32], sp, res;

void factorize(int N) {
	int i, toi;

	sp = 0;
	if (!(N & 1)) {
		primes[0] = 2;
		powers[0] = 0;
		while (!(N & 1)) {
			N >>= 1;
			++powers[0];
		}
		++sp;
	}

	toi = (int)sqrt(N);
	for (i = 3; i <= toi; i += 2) {
		if (!(N % i)) {
			primes[sp] = i;
			powers[sp] = 0;
			while (!(N % i)) {
				N /= i;
				++powers[sp];
			}
			++sp;
			if (i > N) break;
		}
	}
	if (N != 1) {
		primes[sp] = N;
		powers[sp] = 1;
		++sp;
	}
}

void solve(int i, int add) {
	int j;

	if (i >= sp) {
		res += add;
		return;
	}
	for (j = 0; j < powers[i]; ++j) {
		solve(i+1, add);
	}
	solve(i+1, add*(powers[i]+1));
}

int main() {
	int N;

	while (scanf("%d", &N) == 1 && N) {
		if (N == 1) puts("1 1");
		else if (N == 2) puts("2 2");
		else {
			factorize(N);
			res = 1;
			solve(0, 1);
			printf("%d %d\n", N, res/2);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
