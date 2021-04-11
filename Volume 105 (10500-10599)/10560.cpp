/* @JUDGE_ID: 19899RK 10560 C++ "By Anadan" */
// Minimum Weight
// Accepted (0.062 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

typedef unsigned long long qword;

// 18446744073709551615 = 2n-1 = 2^64 - 1
// 18236498188585393201 = (3^41-1)/2
// 12157665459056928801 = 3^40
void printAllWeights(qword N) {
	int i;
	qword power3 = 1;

	N = (N << 1) | 1;
	for (i = 0; i <= 40 && power3 < N; ++i, power3 *= 3);

	power3 = 1;
	printf("%d", i);
	while (i--) {
		printf(" %llu", power3);
		power3 *= 3;
	}
	putchar('\n');
}

void printWeight(qword N) {
	int i, tmp;
	char sgns[41];
	qword power3 = 1;

	memset(sgns, 0, sizeof(sgns));
	for (i = 0; i <= 40 && N; ++i, power3 *= 3) {
		tmp = int(N % 3);
		if (tmp == 1) {
			sgns[i] = 1;
			N = (N-1) / 3;
		} else if (tmp == 2) {
			sgns[i] = -1;
			N = (N+1) / 3;
		} else {
			sgns[i] = 0;
			N /= 3;
		}
	}

	--i;
	power3 /= 3;
	printf("%llu", power3);
	while (i--) {
		power3 /= 3;
		if (sgns[i]) {
			putchar(sgns[i] > 0 ? '+' : '-');
			printf("%llu", power3);
		}
	}
	putchar('\n');
}

int main() {
	qword N;
	int K;

	while (scanf("%llu%d", &N, &K) == 2 && (N || K)) {
		printAllWeights(N);
		while (K--) {
			scanf("%llu", &N);
			printWeight(N);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
