/* @JUDGE_ID: 19899RK 10943 C++ "By Anadan" */
// How do you add?
// Accepted (0.035 seconds with low memory spent)

#include <stdio.h>
#define SZ 100
#define MOD 1000000

int map[SZ+1][SZ+1];

void init() {
	int i, j, k;

	for (j = 0; j <= SZ; ++j) map[0][j] = 1;
	for (i = 1; i <= SZ; ++i) {
		map[i][0] = 0;
		for (j = 1; j <= SZ; ++j) {
			map[i][j] = 0;
			for (k = 0; k <= i; ++k) {
				map[i][j] += map[i-k][j-1];
				map[i][j] %= MOD;
			}
		}
	}
}

int main() {
	int N, K;

	init();
	while (scanf("%d%d", &N, &K) == 2 && N) {
		printf("%d\n", map[N][K]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
