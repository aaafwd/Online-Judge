/* @JUDGE_ID: 19899RK 10285 C++ "By Anadan" */ 
// Longest Run on a Snowboard
// Accepted (0.072 seconds with low memory spent)

#include <stdio.h>

int h[102][102], path[102][102];

int getpath(int i, int j){
	int max, k;

	if (path[i][j] != -1) return path[i][j];

	max = 1;
	if (h[i - 1][j] < h[i][j]){
		k = getpath(i - 1, j) + 1;
		if (max < k) max = k;
	}
	if (h[i + 1][j] < h[i][j]){
		k = getpath(i + 1, j) + 1;
		if (max < k) max = k;
	}
	if (h[i][j - 1] < h[i][j]){
		k = getpath(i, j - 1) + 1;
		if (max < k) max = k;
	}
	if (h[i][j + 1] < h[i][j]){
		k = getpath(i, j + 1) + 1;
		if (max < k) max = k;
	}

	path[i][j] = max;
	return max;
}

int main(){
	int set, R, C, i, j, k, max;

	for (i = 0; i < 102; ++i) h[0][i] = h[i][0] = 1000;

	scanf("%d\n", &set);
	while (set--){
		while ((i = getchar()) == ' ' || i == '\t' || i == '\n');
		putchar(i);
		while ((i = getchar()) != ' ' && i != '\t' && i != '\n') putchar(i);

		scanf("%d%d\n", &R, &C);
		for (i = 1; i <= R; ++i){
			for (j = 1; j <= C; ++j){
				scanf("%d", &h[i][j]);
				path[i][j] = -1;
			}
			h[i][j] = 1000;
		}
		for (j = 1; j <= C; ++j) h[i][j] = 1000;

		max = 0;
		for (i = 1; i <= R; ++i){
			for (j = 1; j <= C; ++j){
				k = getpath(i, j);
				if (max < k) max = k;
			}
		}

		printf(": %d\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
