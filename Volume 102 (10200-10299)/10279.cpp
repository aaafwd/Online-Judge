/* @JUDGE_ID: 19899RK 10279 C++ "By Anadan" */ 
// Mine Sweeper
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int set, N, i, j, k;
	char mines[12][12], map[12][12], boom;

	for (i = 0; i < 12; ++i) mines[0][i] = mines[i][0] = 0;
	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 1; i <= N; ++i) scanf("%s\n", mines[i] + 1);
		memset(mines[i], 0, 12);

		boom = 0;
		for (i = 1; i <= N; ++i){
			scanf("%s\n", map[i] + 1);
			for (j = 1; j <= N; ++j){
				if (map[i][j] == '.') continue;
				if (mines[i][j] == '*') { boom = 1; continue; }
				if (mines[i - 1][j - 1] == '*') k = 1; else k = 0;
				if (mines[i - 1][j] == '*') ++k;
				if (mines[i - 1][j + 1] == '*') ++k;
				if (mines[i + 1][j - 1] == '*') ++k;
				if (mines[i + 1][j] == '*') ++k;
				if (mines[i + 1][j + 1] == '*') ++k;
				if (mines[i][j - 1] == '*') ++k;
				if (mines[i][j + 1] == '*') ++k;
				map[i][j] = '0' + k;
			}
		}

		if (boom){
			for (i = 1; i <= N; ++i) for (j = 1; j <= N; ++j){
				if (mines[i][j] == '*') map[i][j] = '*';
			}
		}
		for (i = 1; i <= N; ++i){
			printf("%s\n", map[i] + 1);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
