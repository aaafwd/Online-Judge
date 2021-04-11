/* @JUDGE_ID: 19899RK 10926 C++ "By Anadan" */
// How Many Dependencies?
// Accepted (0.148 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

int main() {
	int N, i, j, k, ndx, dep;
	char map[100][100];

	while (scanf("%d", &N) == 1 && N) {
		memset(map, 0, sizeof(map));
		for (i = 0; i < N; ++i) {
			scanf("%d", &k);
			while (k--) {
				scanf("%d", &j);
				map[i][j-1] = 1;
			}
		}
		for (k = 0; k < N; ++k) {
			for (i = 0; i < N; ++i) {
				if (i == k || !map[i][k]) continue;
				for (j = 0; j < N; ++j) {
					if (j == k || !map[k][j]) continue;
					map[i][j] = 1;
				}
			}
		}

		ndx = dep = 0;
		for (i = 0; i < N; ++i) {
			if (map[0][i]) ++dep;
		}
		for (i = 1; i < N; ++i) {
			k = 0;
			for (j = 0; j < N; ++j) {
				if (map[i][j]) ++k;
			}
			if (dep < k) {
				dep = k;
				ndx = i;
			}
		}
		printf("%d\n", ndx+1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
