/* @JUDGE_ID: 19899RK 567 C++ "By Anadan" */
// Risk
// Accepted (0.570 seconds using as much as 392 kbytes)

#include <stdio.h>

int main(){
	int i, j, k, l, set = 0;
	int map[20][20];

	while (1){
		for (i = 0; i < 20; ++i) for (j = 0; j < 20; ++j){
			map[i][j] = 0;
		}

		for (i = 0; i < 19; ++i){
			if (scanf("%d", &j) < 1) return 0;
			for (k = 0; k < j; ++k){
				if (scanf("%d", &l) < 1) return 0;
				map[i][l - 1] = map[l - 1][i] = 1;
			}
		}

		for (k = 0; k < 20; ++k){
			for (i = 0; i < 20; ++i){
				if (i == k || map[i][k] == 0) continue;
				for (j = 0; j < 20; ++j){
					if (j == k || map[k][j] == 0) continue;
					if (map[i][j] == 0 || map[i][j] > map[i][k] + map[k][j])
						map[i][j] = map[i][k] + map[k][j];
				}
			}
		}

		printf("Test Set #%d\n", ++set);
		scanf("%d", &j);
		for (i = 0; i < j; ++i){
			scanf("%d%d", &k, &l);
			printf("%2d to %2d: %d\n", k, l, map[k - 1][l - 1]);
		}

		putchar('\n');
	}
}
/* @END_OF_SOURCE_CODE */
