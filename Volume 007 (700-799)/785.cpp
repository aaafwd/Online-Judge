/* @JUDGE_ID: 19899RK 785 C++ "By Anadan" */
// Grid Colouring
// Accepted (0.084 seconds with low memory spent)

#include <stdio.h>

char map[35][85], c;

void fill(int i, int j){
	map[i][j] = c;
	if (map[i - 1][j] != c && map[i - 1][j] != 'X') fill(i - 1, j);
	if (map[i + 1][j] != c && map[i + 1][j] != 'X') fill(i + 1, j);
	if (map[i][j - 1] != c && map[i][j - 1] != 'X') fill(i, j - 1);
	if (map[i][j + 1] != c && map[i][j + 1] != 'X') fill(i, j + 1);
}

int main(){
	int N, i, j;

	while (1){
		N = 0;
		while (gets(map[N]) && map[N][0] != '_') ++N;
		if (N == 0) break;
		for (i = 0; i < N; ++i){
			for (j = 0; map[i][j]; ++j){
				if (map[i][j] != ' ' && map[i][j] != 'X'){
					c = map[i][j];
					fill(i, j);
				}
			}
		}

		for (i = 0; i <= N; ++i) printf("%s\n", map[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
