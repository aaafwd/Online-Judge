/* @JUDGE_ID: 19899RK 10354 C++ "By Anadan" */ 
// Avoiding Your Boss
// Accepted (0.529 seconds using as much as 468 kbytes)

#include <stdio.h>
#include <string.h>

int map[100][100], smap[100][100], N;
char mask[100];

void setpath(int i, int j){
	int k;

	mask[i] = mask[j] = 1;

	for (k = 0; k < N; ++k){
		if (k == i || k == j) continue;
		if (map[i][k] != -1 && map[k][j] != -1 && map[i][j] == map[i][k] + map[k][j]){
			mask[k] = 1;
		}
	}
}

int main(){
	int i, j, k, R, bh, of, yh, m;

	while (scanf("%d%d%d%d%d%d", &N, &R, &bh, &of, &yh, &m) == 6){
		for (i = 0; i < N; ++i){
			memset(map[i], -1, N * sizeof(int));
			memset(smap[i], -1, N * sizeof(int));
			map[i][i] = smap[i][i] = 0;
		}

		while (R--){
			scanf("%d%d%d", &i, &j, &k);
			--i; --j;
			map[i][j] = map[j][i] = smap[i][j] = smap[j][i] = k;
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

		memset(mask, 0, N);
		setpath(bh - 1, of - 1);

		for (k = 0; k < N; ++k){
			if (mask[k]) continue;
			for (i = 0; i < N; ++i){
				if (i == k || smap[i][k] == -1) continue;
				for (j = 0; j < N; ++j){
					if (j == k || smap[k][j] == -1) continue;
					if (smap[i][j] == -1 || smap[i][j] > smap[i][k] + smap[k][j]){
						smap[i][j] = smap[i][k] + smap[k][j];
					}
				}
			}
		}

		i = smap[yh - 1][m - 1];
		if (i == -1 || mask[yh - 1] || mask[m - 1]) puts("MISSION IMPOSSIBLE.");
		else printf("%d\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
