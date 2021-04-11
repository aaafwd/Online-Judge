/* @JUDGE_ID: 19899RK 519 C++ "By Anadan" */
// Puzzle (II)
// Accepted (0.172 seconds using as much as 388 kbytes)

#include <stdio.h>

int rows, cols, N;
char map[7][7], puzzle[36][5], mask[36];

int solved(int i, int j){
	int k;
	char ii = 0, io = 0, oi = 0, oo = 0, fi = 0, fo = 0;

	if (j > cols) { ++i; j = 1; }
	if (i > rows) return 1;

	for (k = 0; k < N; ++k){
		if (mask[k]) continue;

		if ((i == 1) ^ (puzzle[k][0] == 'F')) continue;
		if ((j == 1) ^ (puzzle[k][3] == 'F')) continue;
		if ((j == cols) ^ (puzzle[k][1] == 'F')) continue;
		if ((i == rows) ^ (puzzle[k][2] == 'F')) continue;

		if (puzzle[k][0] == 'O' && (map[i - 1][j] & 1)) continue;
		if (puzzle[k][0] == 'I' && !(map[i - 1][j] & 1)) continue;
		if (puzzle[k][3] == 'O' && (map[i][j - 1] & 2)) continue;
		if (puzzle[k][3] == 'I' && !(map[i][j - 1] & 2)) continue;

		if (puzzle[k][1] == 'I'){
			if (puzzle[k][2] == 'I'){
				if (ii++) continue;
			}else if (puzzle[k][2] == 'O'){
				if (io++) continue;
			}else{
				if (fi++) continue;
			}
		}else if (puzzle[k][1] == 'O'){
			if (puzzle[k][2] == 'I'){
				if (oi++) continue;
			}else if (puzzle[k][2] == 'O'){
				if (oo++) continue;
			}else{
				if (fo++) continue;
			}
		}else{
			if (puzzle[k][2] == 'I'){
				if (fi++) continue;
			}else if (puzzle[k][2] == 'O'){
				if (fo++) continue;
			}
		}

		mask[k] = 1;
		map[i][j] = 0;
		if (puzzle[k][2] == 'O') map[i][j] |= 1;
		if (puzzle[k][1] == 'O') map[i][j] |= 2;
		if (solved(i, j + 1)) return 1;
		mask[k] = 0;

	}

	return 0;
}

int main(){
	int i, j, ci, co, cf;

	for (i = 0; i < 7; ++i) map[0][i] = map[i][0] = 0;
	while (scanf("%d%d\n", &rows, &cols) == 2 && rows){
		N = rows * cols;
		ci = co = cf = 0;
		for (i = 0; i < N; ++i){
			scanf("%s\n", puzzle[i]);
			mask[i] = 0;
			for (j = 0; j < 4; ++j){
				if (puzzle[i][j] == 'F') ++cf;
				else if (puzzle[i][j] == 'O') ++co;
				else ++ci;
			}
		}

		if (cf != 2 * (rows + cols) || ci != co){
			printf("NO\n");
			continue;
		}

		if (solved(1, 1)) printf("YES\n"); else printf("NO\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
