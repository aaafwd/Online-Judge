/* @JUDGE_ID: 19899RK 10360 C++ "By Anadan" */ 
// Rat Attack
// Accepted (1.650 seconds using as much as 4492 kbytes)

#include <stdio.h>
#define MAX 1025

int main(){
	int map[MAX][MAX];
	int set, d, i, j, n, x, y, max, sz;

	scanf("%d\n", &set);
	while (set--){
		for (i = 0; i < MAX; ++i) for (j = 0; j < MAX; ++j)
			map[i][j] = 0;
		scanf("%d%d", &d, &n);
		for (i = 0; i < n; ++i){
			scanf("%d%d%d", &x, &y, &j);
			map[x][y] = j;
		}

		for (i = 1; i < MAX; ++i){
			map[0][i] += map[0][i - 1];
		}

		for (i = 1; i < MAX; ++i){
			for (x = j = 0; j < MAX; ++j){
				x += map[i][j];
				map[i][j] = map[i - 1][j] + x;
			}
		}

		max = -1;
		sz = 2 * d + 1;
		for (i = 0; i < sz; ++i){
			for (j = 0; j < sz; ++j){
				if (max < map[i][j]){
					max = map[i][j];
					x = i; y = j;
				}
			}

			for (j = sz; j < MAX; ++j){
				if (max < map[i][j] - map[i][j - sz]){
					max = map[i][j] - map[i][j - sz];
					x = i; y = j;
				}
			}
		}

		for (i = sz; i < MAX; ++i){
			for (j = 0; j < sz; ++j){
				if (max < map[i][j] - map[i - sz][j]){
					max = map[i][j] - map[i - sz][j];
					x = i; y = j;
				}
			}

			for (j = sz; j < MAX; ++j){
				if (max < map[i][j] - map[i - sz][j] - map[i][j - sz] + map[i - sz][j - sz]){
					max = map[i][j] - map[i - sz][j] - map[i][j - sz] + map[i - sz][j - sz];
					x = i; y = j;
				}
			}
		}

		x -= d; y -= d;
		if (x < 0) x = 0; if (y < 0) y = 0;
		printf("%d %d %d\n", x, y, max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
