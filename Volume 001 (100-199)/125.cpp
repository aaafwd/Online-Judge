/* @JUDGE_ID: 19899RK 125 C++ "By Anadan" */
// Numbering Paths
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int map[30][30], i, j, k, l, m, N, max, set = 0;

	while (scanf("%d", &N) == 1){
		for (i = 0; i < 30; ++i) for (j = 0; j < 30; ++j)
			map[i][j] = 0;

		for (max = i = 0; i < N; ++i){
			scanf("%d%d", &j, &k);
			if (max < j) max = j;
			if (max < k) max = k;

			for (l = 0; l <= max; ++l) if (l == j || map[l][j]){
				for (m = 0; m <= max; ++m)
					if (map[k][m] && (m == l || map[m][l])) break;
				if (m <= max) break;
			}

			if (l <= max){   //infinity
				map[j][k] = map[k][j] = -1;
				map[j][j] = map[k][k] = -1;
				for (l = 0; l <= max; ++l) if (l == j || map[l][j]){
					map[l][j] = map[l][k] = -1;
					for (m = 0; m <= max; ++m){
						if (map[k][m]){
							map[l][m] = map[k][m] = map[j][m] = -1;
							if (m == l || map[m][l]) map[m][l] = map[m][k] = map[m][j] = -1;
						}
					}

					for (m = 0; m <= max; ++m) if (map[m][m]){
						for (j = 0; j <= max; ++j) if (map[j][m]){
							for (k = 0; k <= max; ++k)
								if (map[m][k]) map[j][k] = -1;
						}
					}
				}
			}else{
				if (map[j][k] != -1) ++map[j][k];

				for (m = 0; m <= max; ++m){
					if (map[k][m] && map[j][m] != -1){
						if (map[j][k] == -1 || map[k][m] == -1) map[j][m] = -1;
						else map[j][m] += map[j][k]*map[k][m];
					}
				}

				for (l = 0; l <= max; ++l) if (l != j && map[l][j]){
					if (map[l][k] != -1){
						if (map[l][j] == -1 || map[j][k] == -1) map[l][k] = -1;
						else map[l][k] += map[l][j]*map[j][k];
					}
					for (m = 0; m <= max; ++m){
						if (m != k && map[k][m] && map[l][m] != -1){
							if (map[l][j] == -1 || map[j][k] == -1 || map[k][m] == -1) map[l][m] = -1;
							else map[l][m] += map[l][j]*map[j][k]*map[k][m];
						}
					}
				}
			}
		}

		printf("matrix for city %d\n", set++);
		for (i = 0; i <= max; ++i){
			for (j = 0; j < max; ++j) printf("%d ", map[i][j]);
			printf("%d\n", map[i][j]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
