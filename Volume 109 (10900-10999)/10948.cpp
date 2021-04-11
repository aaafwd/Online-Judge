/* @JUDGE_ID: 19899RK 10948 C++ "By Anadan" */
// The primary problem.
// Accepted (0.197 seconds using as much as 1360 kbytes)

#include <stdio.h>
#define SZ 1000001

char mask[SZ];

void init() {
	int i, j;
	mask[0] = mask[1] = 1;
	for (i = 2; i < SZ; ++i) {
		if (!mask[i]) {
			for (j = i*2; j < SZ; j += i) mask[j] = 1;
		}
	}
}

int main() {
	int N, i;

	init();
	while (scanf("%d", &N) == 1 && N) {
		printf("%d:\n", N);
		if (N & 1) {
			N -= 2;
			if (mask[N]) puts("NO WAY!");
			else printf("2+%d\n", N);
		} else if (N == 4) {
			puts("2+2");
		} else {
			for (i = 3 ;; i += 2) {
				if (!mask[i] && !mask[N-i]) {
					printf("%d+%d\n", i, N-i);
					break;
				}
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
