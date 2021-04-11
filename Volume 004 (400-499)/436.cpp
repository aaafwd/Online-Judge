/* @JUDGE_ID: 19899RK 436 C++ "By Anadan" */
// Arbitrage (II)
// Accepted (0.428 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

int N;
double map[30][30];

int arbitrage(){
	int i, j, k, l, c;
	double cur[2][30], tmp;

	for (i = 0; i < N; ++i){
		for (c = j = 0; j < N; ++j) cur[0][j] = map[i][j];
		if (cur[0][i] > 1.0) return 1;
		for (j = 1; j < N; ++j, c ^= 1){
			for (k = 0; k < N; ++k){
				tmp = -1.0;
				for (l = 0; l < N; ++l){
					if (cur[c][l] != -1.0 && map[l][k] != -1.0 && tmp < cur[c][l] * map[l][k]){
						tmp = cur[c][l] * map[l][k];
					}
				}

				cur[c ^ 1][k] = tmp;
			}

			if (cur[c ^ 1][i] > 1.0) return 1;
		}
	}

	return 0;
}

int main(){
	double tmp;
	int i, j, k, m, set = 0;
	char names[30][101], s1[101], s2[101];

	while (scanf("%d", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%s\n", names[i]);

		for (i = 0; i < N; ++i) for (m = 0; m < N; ++m){
			map[i][m] = -1.0;
		}

		scanf("%d", &m);
		for (i = 0; i < m; ++i){
			scanf("%s %lf %s\n", s1, &tmp, s2);
			for (j = 0; strcmp(names[j], s1); ++j);
			for (k = 0; strcmp(names[k], s2); ++k);
			map[j][k] = tmp;
		}

		printf("Case %d: %s\n", ++set, (arbitrage()) ? ("Yes") : ("No"));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
