/* @JUDGE_ID: 19899RK 10196 C++ "By Anadan" */ 
// Check The Check
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

char map[12][12];
const char figures[2][7] = { "pnbrqk", "PNBRQK" };

int incheck(int c){
	int i, j, k;

	for (i = 2; i <= 9; ++i){
		for (j = 2; j <= 9; ++j) if (map[i][j] == figures[c ^ 1][5]) break;
		if (j <= 9) break;
	}
	if (i > 9) return 0;

	for (k = 1; map[i - k][j] == '.'; ++k);
	if (map[i - k][j] == figures[c][3] || map[i - k][j] == figures[c][4]) return 1;
	for (k = 1; map[i + k][j] == '.'; ++k);
	if (map[i + k][j] == figures[c][3] || map[i + k][j] == figures[c][4]) return 1;
	for (k = 1; map[i][j - k] == '.'; ++k);
	if (map[i][j - k] == figures[c][3] || map[i][j - k] == figures[c][4]) return 1;
	for (k = 1; map[i][j + k] == '.'; ++k);
	if (map[i][j + k] == figures[c][3] || map[i][j + k] == figures[c][4]) return 1;

	if (map[i - 1][j - 1] == figures[c][5] || map[i - 1][j] == figures[c][5] || map[i - 1][j + 1] == figures[c][5]) return 1;
	if (map[i + 1][j - 1] == figures[c][5] || map[i + 1][j] == figures[c][5] || map[i + 1][j + 1] == figures[c][5]) return 1;
	if (map[i][j - 1] == figures[c][5] || map[i][j + 1] == figures[c][5]) return 1;

	if (map[i - 1][j - 2] == figures[c][1] || map[i - 1][j + 2] == figures[c][1]) return 1;
	if (map[i + 1][j - 2] == figures[c][1] || map[i + 1][j + 2] == figures[c][1]) return 1;
	if (map[i - 2][j - 1] == figures[c][1] || map[i - 2][j + 1] == figures[c][1]) return 1;
	if (map[i + 2][j - 1] == figures[c][1] || map[i + 2][j + 1] == figures[c][1]) return 1;

	for (k = 1; map[i - k][j - k] == '.'; ++k);
	if (map[i - k][j - k] == figures[c][2] || map[i - k][j - k] == figures[c][4]) return 1;
	for (k = 1; map[i - k][j + k] == '.'; ++k);
	if (map[i - k][j + k] == figures[c][2] || map[i - k][j + k] == figures[c][4]) return 1;
	for (k = 1; map[i + k][j - k] == '.'; ++k);
	if (map[i + k][j - k] == figures[c][2] || map[i + k][j - k] == figures[c][4]) return 1;
	for (k = 1; map[i + k][j + k] == '.'; ++k);
	if (map[i + k][j + k] == figures[c][2] || map[i + k][j + k] == figures[c][4]) return 1;

	if (c == 0){ // White
		if (map[i - 1][j - 1] == 'p' || map[i - 1][j + 1] == 'p') return 1;
	}else{ // Black
		if (map[i + 1][j - 1] == 'P' || map[i + 1][j + 1] == 'P') return 1;
	}

	return 0;
}

int main(){
	int set = 0, i, j;
	char empty;

	for (i = 0; i < 12; ++i){
		map[0][i] = map[i][0] = map[11][i] = map[i][11] = 0;
		map[1][i] = map[i][1] = map[10][i] = map[i][10] = 0;
	}

	while (1){
		empty = 1;
		for (i = 2; i <= 9; ++i){
			scanf("%s\n", map[i] + 2);
			for (j = 2; j <= 9; ++j) if (map[i][j] != '.') break;
			if (j <= 9) empty = 0;
		}
		if (empty) break;

		printf("Game #%d: ", ++set);
		if (incheck(0)) printf("white king is in check.\n");
		else if (incheck(1)) printf("black king is in check.\n");
		else printf("no king is in check.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
