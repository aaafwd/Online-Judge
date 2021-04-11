/* @JUDGE_ID: 19899RK 10702 C++ "By Anadan" */
// Travelling Salesman
// Accepted (1.441 seconds using as much as 432 kbytes)

#include <stdio.h>
#include <string.h>

int C, S, E, T, map[100][100], maxp[100];
char end[100];

void dowave() {
	int i, j, k, N = 1, M, curr[100], next[100], nmaxp[100];

	curr[0] = S;
	while (T--) {
		memcpy(nmaxp, maxp, sizeof(maxp));
		for (M = i = 0; i < N; ++i) {
			k = curr[i];
			for (j = 0; j < C; ++j) {
				if (j == k) continue;
				if (nmaxp[j] < maxp[k] + map[k][j]) {
					if (nmaxp[j] == maxp[j]) next[M++] = j;
					nmaxp[j] = maxp[k] + map[k][j];
				}
			}
		}
		N = M;
		memcpy(curr, next, sizeof(next));
		memcpy(maxp, nmaxp, sizeof(nmaxp));
	}
}

int main(){
	int i, j, res;

	while (scanf("%d%d%d%d", &C, &S, &E, &T) == 4 && C) {
		--S;
		for (i = 0; i < C; ++i) {
			for (j = 0; j < C; ++j) {
				scanf("%d", &map[i][j]);
			}
			maxp[i] = 0;
		}
		memset(end, 0, C);
		for (i = 0; i < E; ++i) {
			scanf("%d", &j);
			end[j-1] = 1;
		}
		dowave();
		for (res = i = 0; i < C; ++i) {
			if (end[i] && res < maxp[i]) res = maxp[i];
		}
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
