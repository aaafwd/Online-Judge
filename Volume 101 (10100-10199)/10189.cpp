/* @JUDGE_ID: 19899RK 10189 C++ "By Anadan" */
// Minesweeper
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	char map[102][102];
	int i, j, n, m, tmp, set = 0;

	for (i = 0; i < 102; i++) map[i][0] = map[0][i] = 0;
	while (scanf("%d%d\n", &n, &m) == 2){
		if (n == 0) break;
		for (i = 0; i < n; i++) scanf("%s\n", map[i + 1] + 1);
		memset(map[n + 1], 0, m + 2);
		for (i = 1; i <= n; i++){
			for (j = 1; j <= m; j++){
				if (map[i][j] == '*') continue;
				tmp = 0;
				if (map[i-1][j-1] == '*') ++tmp;
				if (map[i-1][j] == '*') ++tmp;
				if (map[i-1][j+1] == '*') ++tmp;
				if (map[i+1][j-1] == '*') ++tmp;
				if (map[i+1][j] == '*') ++tmp;
				if (map[i+1][j+1] == '*') ++tmp;
				if (map[i][j-1] == '*') ++tmp;
				if (map[i][j+1] == '*') ++tmp;
				map[i][j] = '0' + tmp;
			}
		}

		if (set) putchar('\n');
		printf("Field #%d:\n", ++set);
		for (i = 1; i <= n; i++) printf("%s\n", map[i] + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
