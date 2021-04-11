/* @JUDGE_ID: 19899RK 10543 C++ "By Anadan" */
// Traveling Politician
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int N, M, K, i, j, k;
	char map[50][50], q1[50], q2[50];

	while (scanf("%d%d%d", &N, &M, &K) == 3 && N){
		for (i = 0; i < N; ++i) memset(map[i], 0, N);
		while (M--){
			scanf("%d%d", &i, &j);
			map[i][j] = 1;
		}

		memset(q1, 0, N);
		q1[0] = 1;
		for (i = 1; i < 20; ++i){
			memset(q2, 0, N);
			for (j = 0; j < N; ++j){
				if (q1[j] == 0) continue;
				if (map[j][N - 1] && i + 1 >= K) break;
				for (k = 0; k < N; ++k) if (map[j][k]) q2[k] = 1;
			}

			if (j < N) break;
			memcpy(q1, q2, N);
		}

		if (i < 20) printf("%d\n", i + 1);
		else puts("LOSER");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
