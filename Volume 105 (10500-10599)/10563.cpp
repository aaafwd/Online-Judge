/* @JUDGE_ID: 19899RK 10563 C++ "By Anadan" */
// Least Squares
// Accepted (0.162 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <string.h>

char map[101][81];
int rows, cols;

inline int isletter(char ch) { return 'A' <= ch && ch <= 'Z'; }

char getMinColor(int r, int c) {
	char mask[4];
	mask[0] = mask[1] = mask[2] = mask[3] = 0;

	if (r && isletter(map[r-1][c])) mask[map[r-1][c] - 'A'] = 1;
	if (r < rows-1 && isletter(map[r+1][c])) mask[map[r+1][c] - 'A'] = 1;
	if (c && isletter(map[r][c-1])) mask[map[r][c-1] - 'A'] = 1;
	if (c < cols-1 && isletter(map[r][c+1])) mask[map[r][c+1] - 'A'] = 1;

	for (r = 0; r < 4; ++r) if (!mask[r]) break;
	return 'A'+r;
}

int acceptableLessColor(int r, int c, char color) {
	char i;
	for (i = 'A'; i < color; ++i) {
		if ((r == 0 || i != map[r-1][c]) && i != map[r][c+1]) return 1;
	}
	return 0;
}

void paintSquare(int r, int c, char color) {
	int i, j;

	map[r][c] = color;
	for (i = 1; r+i < rows && c+i < cols; ++i) {
		if (map[r+i][c+i] != '?' || map[r+i+1][c+i] == color || map[r+i][c+i+1] == color) break;
		if (r && map[r-1][c+i] == color) break;
		if (c && map[r+i][c-1] == color) break;
		if (color != 'A' && acceptableLessColor(r, c+i, color)) break;
		
		for (j = 0; j < i; ++j) {
			if (map[r+j][c+i] != '?' || map[r+j][c+i+1] == color) break;
		}
		if (j < i) break;

		for (j = 0; j < i; ++j) {
			if (map[r+i][c+j] != '?' || map[r+i+1][c+j] == color) break;
		}
		if (j < i) break;

		map[r+i][c+i] = color;
		for (j = 0; j < i; ++j) map[r+j][c+i] = map[r+i][c+j] = color;
	}
}

int main() {
	int i = -1, j;

	while (scanf("%d%d", &rows, &cols) == 2 && rows) {
		if (i != -1) putchar('\n');
		memset(map[rows], 0, sizeof(map[rows]));
		for (i = 0; i < rows; ++i) scanf("%s", map[i]);
		for (i = 0; i < rows; ++i) {
			for (j = 0; j < cols; ++j) {
				if (map[i][j] != '?') continue;
				paintSquare(i, j, getMinColor(i, j));
			}
		}
		for (i = 0; i < rows; ++i) puts(map[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
