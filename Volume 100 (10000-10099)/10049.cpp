/* @JUDGE_ID: 19899RK 10049 C++ "By Anadan" */
// Self-describing Sequence
// Accepted (0.068 seconds with low memory spent)

#include <stdio.h>
#define SZ 675000

int begin[SZ], len[SZ];

void init() {
	int i, j, k, next;

	begin[1] = 1; len[1] = 1;
	begin[2] = 2; len[2] = 2;
	begin[3] = 4; len[3] = 2;

	next = 6;
	for (i = 3; i < SZ; ++i) {
		for (j = 0; j < len[i]; ++j) {
			k = begin[i] + j;
			if (k >= SZ) break;
			begin[k] = next;
			len[k] = i;
			next += i;
		}
	}
}

int lfind(int N) {
	int i = 1, j = SZ - 1, k;
	while (i < j) {
		k = (i + j + 1) / 2;
		if (begin[k] > N) j = k - 1;
		else i = k;
	}
	return i;
}

int main() {
	int i, N;

	init();
	while (scanf("%d", &N) == 1 && N) {
		i = lfind(N);
		printf("%d\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
