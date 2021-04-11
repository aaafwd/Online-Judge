/* @JUDGE_ID: 19899RK 260 C++ "By Anadan" */
// Il Gioco dell'X
// Accepted (0.059 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N;
char map[202][202];

int whitewin(int i, int j){
	map[i][j] = 0;

	if (j == N) return 1;
	if (map[i - 1][j - 1] == 'w' && whitewin(i - 1, j - 1)) return 1;
	if (map[i - 1][j] == 'w' && whitewin(i - 1, j)) return 1;
	if (map[i][j - 1] == 'w' && whitewin(i, j - 1)) return 1;
	if (map[i][j + 1] == 'w' && whitewin(i, j + 1)) return 1;
	if (map[i + 1][j] == 'w' && whitewin(i + 1, j)) return 1;
	if (map[i + 1][j + 1] == 'w' && whitewin(i + 1, j + 1)) return 1;

	return 0;
}

int main(){
	int i, set = 0;

	for (i = 0; i < 202; ++i) map[0][i] = map[i][0] = 0;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 1; i <= N; ++i) scanf("%s\n", map[i] + 1);
		memset(map[i], 0, N + 2);

		for (i = 1; i <= N; ++i){
			if (map[i][1] == 'w' && whitewin(i, 1)) break;
		}

		printf("%d %c\n", ++set, (i <= N) ? ('W') : ('B'));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
