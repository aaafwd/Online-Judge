/* @JUDGE_ID: 19899RK 10930 C++ "By Anadan" */
// A-Sequence
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define MAXSZ 30010

char mask[MAXSZ];

int main() {
	int set = 0, N, K, i, j, x, prev, isAseq;

	while (scanf("%d", &N) == 1) {
		memset(mask, 0, N*1000+1);
		mask[0] = 1;
		K = prev = 0;
		isAseq = 1;

		printf("Case #%d:", ++set);
		for (i = 0; i < N; ++i) {
			scanf("%d", &x);
			printf(" %d", x);
			if (prev >= x || mask[x]) isAseq = 0;
			prev = x;
			if (isAseq) {
				for (j = K; j >= 0; --j) {
					if (mask[j]) mask[j+x] = 1;
				}
				K += x;
			}
		}
		if (isAseq) puts("\nThis is an A-sequence.");
		else puts("\nThis is not an A-sequence.");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
