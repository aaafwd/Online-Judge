/* @JUDGE_ID: 19899RK 10331 C++ "By Anadan" */ 
// The Flyover Construction
// Accepted (9.680 seconds using as much as 548 kbytes)
// Too much time !!!

#include <stdio.h>
#include <string.h>

int map[100][100], smap[100][100], index[100][100], N, M;

int main(){
	int i, j, k, m, road[10000];

	while (scanf("%d%d", &N, &M) == 2){
		for (i = 0; i < N; ++i){
			memset(map[i], -1, sizeof(int) * N);
			memset(index[i], -1, sizeof(int) * N);
		}

		for (m = 0; m < M; ++m){
			road[m] = 0;
			scanf("%d%d%d", &i, &j, &k); --i; --j;
			if (map[i][j] == -1 || map[i][j] > k){
				map[i][j] = map[j][i] = k;
				smap[i][j] = smap[j][i] = k;
				index[i][j] = index[j][i] = m;
			}
		}

		for (k = 0; k < N; ++k){
			for (i = 0; i < N; ++i){
				if (i == k || map[i][k] == -1) continue;
				for (j = 0; j < N; ++j){
					if (j == k || map[k][j] == -1) continue;
					if (map[i][j] == -1 || map[i][j] > map[i][k] + map[k][j]){
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}

		for (i = 0; i < N; ++i) for (j = i + 1; j < N; ++j){
			if (index[i][j] == -1) continue;
			if (map[i][j] == smap[i][j]) ++road[index[i][j]];

			for (k = 0; k < N; ++k){
				if (k == i || k == j || map[k][i] == -1) continue;
				if (map[k][i] + map[i][j] == map[k][j]) ++road[index[i][j]];
				if (map[j][k] != -1 && map[i][j] + map[j][k] == map[i][k]) ++road[index[i][j]];

				for (m = 0; m < N; ++m){
					if (k != m && j != m && map[j][m] != -1 && map[k][m] == map[k][i] + map[i][j] + map[j][m]) ++road[index[i][j]];
				}
			}
		}

		m = 0;
		for (i = 0; i < M; ++i) if (m < road[i]) m = road[i];
		for (j = i = 0; i < M; ++i){
			if (road[i] == m){
				if (j) putchar(' '); else j = 1;
				printf("%d", i + 1);
			}
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
