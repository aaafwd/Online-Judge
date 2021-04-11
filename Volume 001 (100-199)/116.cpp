/* @JUDGE_ID: 19899RK 116 C++ "By Anadan" */
// Unidirectional TSP
// Accepted (0.600 seconds using as much as 404 kbytes)

#include <stdio.h>

int main(){
	int N, M, map[10][100], path[10][100], i, j, k, rest;

	while (scanf("%d%d", &N, &M) == 2){
		for (i = 0; i < N; ++i) for (j = 0; j < M; ++j){
			scanf("%d", map[i] + j);
		}

		for (i = 0; i < N; ++i) path[i][M - 1] = map[i][M - 1];
		for (j = M - 1; j > 0; --j){
			k = path[0][j];
			if (k > path[N - 1][j]) k = path[N - 1][j];
			if (N > 1 && k > path[1][j]) k = path[1][j];
			path[0][j - 1] = k + map[0][j - 1];

			for (i = 1; i < N - 1; ++i){
				k = path[i - 1][j];
				if (k > path[i][j]) k = path[i][j];
				if (k > path[i + 1][j]) k = path[i + 1][j];
				path[i][j - 1] = k + map[i][j - 1];
			}

			if (N > 1){
				k = path[i][j];
				if (k > path[0][j]) k = path[0][j];
				if (k > path[i - 1][j]) k = path[i - 1][j];
				path[i][j - 1] = k + map[i][j - 1];
			}
		}

		k = path[0][0];
		for (i = 1; i < N; ++i) if (k > path[i][0]) k = path[i][0];
		for (i = 0; i < N; ++i) if (path[i][0] == k) break;
		printf("%d", i + 1);
		rest = k - map[i][0];
		for (j = 1; j < M; ++j){
			if (i == N - 1 && path[0][j] == rest){
				printf(" 1");
				i = 0;
				rest -= map[0][j];
				continue;
			}

			if (i){
				if (path[i - 1][j] == rest){
					printf(" %d", i);
					rest -= map[--i][j];
					continue;
				}
			}

			if (path[i][j] == rest){
				printf(" %d", i + 1);
				rest -= map[i][j];
				continue;
			}

			if (i < N - 1 && path[i + 1][j] == rest){
				rest -= map[++i][j];
				printf(" %d", i + 1);
				continue;
			}

			i = N - 1;
			rest -= map[i][j];
			printf(" %d", N);
		}

		printf("\n%d\n", k);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
