/* @JUDGE_ID: 19899RK 10259 C++ "By Anadan" */ 
// Hippity Hopscotch
// Accepted (0.234 seconds using as much as 464 kbytes)

#include <stdio.h>
#include <string.h>

int N, K, map[100][100], max[100][100];

int getmaxearn(int x, int y){
	int i, k;

	if (max[x][y] != -1) return max[x][y];

	max[x][y] = 0;
	for (k = 1; k <= K && x + k < N; ++k){
		if (map[x + k][y] > map[x][y]){
			i = getmaxearn(x + k, y);
			if (max[x][y] < i) max[x][y] = i;
		}
	}
	for (k = 1; k <= K && x - k >= 0; ++k){
		if (map[x - k][y] > map[x][y]){
			i = getmaxearn(x - k, y);
			if (max[x][y] < i) max[x][y] = i;
		}
	}
	for (k = 1; k <= K && y + k < N; ++k){
		if (map[x][y + k] > map[x][y]){
			i = getmaxearn(x, y + k);
			if (max[x][y] < i) max[x][y] = i;
		}
	}
	for (k = 1; k <= K && y - k >= 0; ++k){
		if (map[x][y - k] > map[x][y]){
			i = getmaxearn(x, y - k);
			if (max[x][y] < i) max[x][y] = i;
		}
	}

	max[x][y] += map[x][y];
	return max[x][y];
}

int main(){
	int set, i, j, k;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d%d\n", &N, &K);
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j){
			while ((k = getchar()) != EOF && (k < '0' || k > '9'));
			map[i][j] = k - '0';
			while ((k = getchar()) != EOF && '0' <= k && k <= '9'){
				map[i][j] = map[i][j] * 10 + k - '0';
			}
		}

		memset(max, -1, sizeof(max));
		printf("%d\n", getmaxearn(0, 0));
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
