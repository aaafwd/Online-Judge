/* @JUDGE_ID: 19899RK 10690 C++ "By Anadan" */
// Expression Again
// Accepted (3.336 seconds using as much as 668 kbytes)
// Too much time !

#include <stdio.h>
#include <string.h>
#define SZ 2500

char count[SZ+SZ+1][51];
char mask[SZ+SZ+1];
int que[SZ+SZ+1], sp;

int main() {
	int nums[100], N, M, i, j, k, tmp, min, max, sum;

	while (scanf("%d%d", &N, &M) == 2) {
		memset(mask, 0, sizeof(mask));
		memset(count, 0, sizeof(count));
		count[SZ][0] = 1;

		mask[SZ] = 1;
		sp = 1;
		que[0] = 0;

		if (N > M) { i = N; N = M; M = i; }

		for (sum = i = 0; i < N+M; ++i) {
			scanf("%d", nums+i);
			for (j = sp-1; j >= 0; --j) {
				tmp = que[j] + nums[i];
				if (mask[tmp+SZ] == 0) {
					mask[tmp+SZ] = 1;
					que[sp++] = tmp;
				}
				for (k = 0; k < N; ++k) {
					if (count[que[j]+SZ][k] && count[que[j]+SZ][k] < i+2) {
						if (count[tmp+SZ][k+1] == 0) count[tmp+SZ][k+1] = i+2;
					}
				}
			}
			sum += nums[i];
		}

		min = +2147483647;
		max = -2147483647;
		for (i = 0; i < sp; ++i) {
			if (count[que[i]+SZ][N] == 0) continue;
			tmp = que[i] * (sum - que[i]);
			if (max < tmp) max = tmp;
			if (min > tmp) min = tmp;
		}

		printf("%d %d\n", max, min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
