/* @JUDGE_ID: 19899RK 339 C++ "By Anadan" */
// SameGame Simulation
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int row, col;
char map[10][40];

inline int isvalid(int i, int j) { return (i >= 0 && i < row && j >= 0 && j < col); }

void doremove(int i, int j) {
	int c = map[i][j];
	map[i][j] = 0;
	if (isvalid(i - 1, j) && map[i - 1][j] == c) doremove(i - 1, j);
	if (isvalid(i + 1, j) && map[i + 1][j] == c) doremove(i + 1, j);
	if (isvalid(i, j - 1) && map[i][j - 1] == c) doremove(i, j - 1);
	if (isvalid(i, j + 1) && map[i][j + 1] == c) doremove(i, j + 1);
}

void remove(int i, int j) {
	int k;

	if (!isvalid(i, j) || !map[i][j]) return;
	if (isvalid(i - 1, j) && map[i - 1][j] == map[i][j] ||
	    isvalid(i + 1, j) && map[i + 1][j] == map[i][j] ||
	    isvalid(i, j - 1) && map[i][j - 1] == map[i][j] ||
	    isvalid(i, j + 1) && map[i][j + 1] == map[i][j])
	{
		doremove(i, j);
		for (j = 0; j < col; ++j) {
			for (i = k = 0; i < row; ++i) {
				if (map[i][j]) map[k++][j] = map[i][j];
			}

			while (k < row) map[k++][j] = 0;
		}

		for (k = j = 0; j < col; ++j) {
			if (!map[0][j]) continue;
			for (i = 0; i < row; ++i) map[i][k] = map[i][j];
			++k;
		}

		for (; k < col; ++k) {
			for (i = 0; i < row; ++i) map[i][k] = 0;
		}
	}
}

int main() {
	int set = 0, i, j, k;

	while (scanf("%d%d", &row, &col) == 2 && row && col) {
		for (i = 0; i < row; ++i) for (j = 0; j < col; ++j) {
			while ((k = getchar()) < '0' || k > '9');
			map[i][j] = k;
		}

		while (scanf("%d%d", &i, &j) == 2 && i && j) {
			remove(i - 1, j - 1);
		}

		printf("Grid %d.\n", ++set);
		if (!map[0][0]) puts("    Game Won");
		else{
			for (i = row - 1; i >= 0; --i) {
				printf("    ");
				for (j = 0; j < col; ++j) {
					putchar(map[i][j] ? map[i][j] : ' ');
					putchar(' ');
				}
				putchar('\n');
			}
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
