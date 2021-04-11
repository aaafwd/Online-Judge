/* @JUDGE_ID: 19899RK 193 C++ "By Anadan" */
// Graph Coloring
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, maxblack;
char map[100][100], best[100];

void docoloring(int i, int curblack, int curwhite, char *cur){
	int j, k;
	char tmp[100];

	for (; i < N; ++i){
		if (cur[i] == 0){
			memcpy(tmp, cur, N);
			for (j = k = 0; j < N; ++j){
				if (map[i][j]){
					if (tmp[j] == 1) break;
					if (tmp[j] == 0){
						tmp[j] = 2;
						++k;
					}
					tmp[i] = 1;
				}
			}

			if (j == N){
				if (tmp[i] == 0){
					cur[i] = 1;
					++curblack;
					continue;
				}

				if (N - curwhite - k > maxblack){
					docoloring(i + 1, curblack + 1, curwhite + k, tmp);
				}
			}

			cur[i] = 2;
			++curwhite;
			if (N - curwhite <= maxblack) break;
		}
	}

	if (maxblack < curblack){
		maxblack = curblack;
		memcpy(best, cur, N);
	}
}

int main(){
	int set, i, u, v, K;
	char tmp[100];

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d", &N, &K);
		for (i = 0; i < N; ++i) memset(map[i], 0, N);
		for (i = 0; i < K; ++i){
			scanf("%d%d", &u, &v); --u; --v;
			map[u][v] = map[v][u] = 1;
		}

		maxblack = 0;
		memset(best, 0, N);
		memset(tmp, 0, N);
		docoloring(0, 0, 0, tmp);

		printf("%d\n", maxblack);
		if (maxblack){
			for (i = 0; i < N; ++i){
				if (best[i] == 1){
					printf("%d", i + 1);
					break;
				}
			}

			for (++i; i < N; ++i){
				if (best[i] == 1) printf(" %d", i + 1);
			}
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
