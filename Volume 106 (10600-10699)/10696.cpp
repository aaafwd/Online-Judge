/* @JUDGE_ID: 19899RK 10696 C++ "By Anadan" */
// f91
// Accepted (0.510 seconds using as much as 392 kbytes)

#include <stdio.h>

int f91(int N) {
	if (N >= 101) return N-10;
	return f91(f91(N+11));
}

int main() {
	int N, i, res[101];

	for (i = 1; i <= 100; ++i) res[i] = f91(i);
	while (scanf("%d", &N) == 1 && N) {
		if (N <= 100) printf("f91(%d) = %d\n", N, res[N]);
		else printf("f91(%d) = %d\n", N, N - 10);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
