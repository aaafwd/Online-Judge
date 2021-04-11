/* @JUDGE_ID: 19899RK 626 C++ "By Anadan" */ 
// Ecosystem
// Accepted (0.064 seconds with low memory spent)

#include <stdio.h>

int main(){
	int N, i, j, k, total;
	static char map[100][100];

	while (scanf("%d\n", &N) == 1){
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j){
			scanf("%d", &k);
			map[i][j] = k;
		}

		total = 0;
		for (i = 0; i < N; ++i){
			for (j = 0; j < i; ++j){
				if (!map[i][j]) continue;
				for (k = 0; k < j; ++k){
					if (map[j][k] && map[k][i]){
						printf("%d %d %d\n", i + 1, j + 1, k + 1); 
						++total;
					}
				}
			}

			for (j = i + 1; j < N; ++j){
				if (!map[i][j]) continue;
				for (k = j + 1; k < N; ++k){
					if (map[j][k] && map[k][i]){
						printf("%d %d %d\n", i + 1, j + 1, k + 1); 
						++total;
					}
				}
			}
		}

		printf("total:%d\n\n", total);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
