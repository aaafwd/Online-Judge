/* @JUDGE_ID: 19899RK 423 C++ "By Anadan" */ 
// MPI Maelstrom
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int map[100][100], N;

int solve(){
	int ro[100], min, i, j;
	char mask[100];

	if (N == 1) return 0;
	memset(mask, 0, N);
	mask[0] = 1;
	for (i = 0; i < N; ++i) ro[i] = map[i][0];
	while (1){
		min = -1;
		for (i = 0; i < N; ++i){
			if (mask[i] || ro[i] == -1) continue;
			if (min == -1 || min > ro[i]){
				min = ro[i];
				j = i;
			}
		}

		if (min == -1) break;
		mask[j] = 1;
		for (i = 0; i < N; ++i){
			if (mask[i] || map[j][i] == -1) continue;
			if (ro[i] == -1 || ro[i] > ro[j] + map[j][i]) ro[i] = ro[j] + map[j][i];
		}
	}

	min = ro[1];
	for (i = 2; i < N; ++i){
		if (ro[i] == -1) return 0;
		if (min < ro[i]) min = ro[i];
	}

	return min;
}

int main(){
	int i, j, k;

	scanf("%d\n", &N);
	map[0][0] = 0;
	for (i = 1; i < N; ++i){
		map[i][i] = 0;
		for (j = 0; j < i; ++j){
			if (scanf("%d", &k) != 1){
				k = -1;
				scanf("%*1s");
			}
			map[i][j] = map[j][i] = k;
		}
	}

	printf("%d\n", solve());

	return 0;
}
/* @END_OF_SOURCE_CODE */
