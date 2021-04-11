/* @JUDGE_ID: 19899RK 10791 C++ "By Anadan" */
// Minimum Sum LCM
// Accepted (0.064 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main() {
	int set = 0, N, M, sav, i, res, sqrtN;

	while (scanf("%d", &N) == 1 && N) {
		if (N == 1) res = 2;
		else if (N == 2147483647) {
			printf("Case %d: 2147483648\n", ++set);
			continue;
		} else {
			res = 0;
			sav = N;
			sqrtN = (int)sqrt(N);
			for (i = 2; i <= sqrtN; ++i) {
				if (N%i) continue;
				M = 1;
				while (!(N%i)) {
					N /= i;
					M *= i;
				}
				res += M;
			}
			if (N > 1) res += N;
			if (sav == res) ++res;
		}

		printf("Case %d: %d\n", ++set, res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
