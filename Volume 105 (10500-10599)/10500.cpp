/* @JUDGE_ID: 19899RK 10500 C++ "By Anadan" */ 
// Robot maps
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int row, col;
char map[12][12], mask[12][12], see[12][12];

const int dx[] = { -1, 0, 1,  0 };
const int dy[] = {  0, 1, 0, -1 };

int main(){
	int i, j, k, x, y, moves;

	for (i = 0; i < 12; ++i) map[0][i] = map[i][0] = 'X';

	while (scanf("%d%d", &row, &col) == 2 && row){
		scanf("%d%d", &x, &y);
		for (i = 1; i <= row; ++i){
			for (j = 1; j <= col; ++j){
				while ((k = getchar()) != 'X' && k != '0');
				map[i][j] = k;
			}

			map[i][j] = 'X';
		}

		for (j = 1; j <= col + 1; ++j) map[i][j] = 'X';
		memset(mask, 0, sizeof(mask));
		memset(see, 0, sizeof(see));
		map[x][y] = '0';
		moves = 0;

		while (1){
			mask[x][y] = 1;
			see[x][y] = see[x + 1][y] = see[x - 1][y] = see[x][y + 1] = see[x][y - 1] = 1;
			for (k = 0; k < 4; ++k){
				if (map[x + dx[k]][y + dy[k]] == '0' && mask[x + dx[k]][y + dy[k]] == 0) break;
			}

			if (k == 4) break;
			++moves;
			x += dx[k];
			y += dy[k];
		}

		putchar('\n');
		for (i = 1; i <= row; ++i){
			for (j = 1; j <= col; ++j) printf("|---");
			puts("|");
			for (j = 1; j <= col; ++j) printf("| %c ", (see[i][j] == 0) ? ('?') : (map[i][j]));
			puts("|");
		}

		for (j = 1; j <= col; ++j) printf("|---");
		printf("|\n\nNUMBER OF MOVEMENTS: %d\n", moves);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
