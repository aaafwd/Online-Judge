/* @JUDGE_ID: 19899RK 10681 C++ "By Anadan" */
// Teobaldo's Trip
// Accepted (0.049 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, S, E, D;
char map[100][100], mask[100];

int solved() {
	int q1[100], q2[100], sp = 1, nsp, i, j;

	q1[0] = S;
	while (D--) {
		nsp = 0;
		memset(mask, 0, N);
		for (i = 0; i < sp; ++i) {
			for (j = 0; j < N; ++j) {
				if (mask[j] == 0 && map[q1[i]][j]) {
					mask[j] = 1;
					q2[nsp++] = j;
				}
			}
		}
		memcpy(q1, q2, sizeof(q2));
		sp = nsp;
	}

	for (i = 0; i < sp; ++i) if (q1[i] == E) return 1;
	return 0;
}

int main() {
	int L, i, x, y;

	while (scanf("%d%d", &N, &L) == 2 && N) {
		memset(map, 0, sizeof(map));
		for (i = 0; i < L; ++i) {
			scanf("%d%d", &x, &y);
			--x; --y;
			map[x][y] = map[y][x] = 1;
		}
		scanf("%d%d%d", &S, &E, &D); --S; --E;
		if (solved()) puts("Yes, Teobaldo can travel.");
		else puts("No, Teobaldo can not travel.");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
