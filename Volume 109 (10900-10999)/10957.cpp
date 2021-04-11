/* @JUDGE_ID: 19899RK 10957 C++ "By Anadan" */
// So Doku Checker
// Accepted (0.543 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

int map[9][9];
char rows[9][9], cols[9][9], sq[9][9], found;

int illegal() {
	int i, j;

	memset(rows, 0, sizeof(rows));
	memset(cols, 0, sizeof(cols));
	memset(sq, 0, sizeof(sq));

	for (i = 0; i < 9; ++i) {
		for (j = 0; j < 9; ++j) {
			if (map[i][j] == 0) continue;
			if (rows[i][map[i][j] - 1]) return 1;
			if (cols[j][map[i][j] - 1]) return 1;
			if (sq[(i/3)*3 + j/3][map[i][j] - 1]) return 1;
			rows[i][map[i][j] - 1] = 1;
			cols[j][map[i][j] - 1] = 1;
			sq[(i/3)*3 + j/3][map[i][j] - 1] = 1;
		}
	}
	return 0;
}

int generate(int i, int j) {
	int k;

	for (; i < 9; ++i) {
		for (; j < 9; ++j) {
			if (!map[i][j]) break;
		}
		if (j < 9) break;
		j = 0;
	}
	if (i >= 9) {
		++found;
		if (found > 1) return 1;
		return 0;
	}

	for (k = 0; k < 9; ++k) {
		if (rows[i][k] || cols[j][k] || sq[(i/3)*3 + j/3][k]) continue;

		rows[i][k] = cols[j][k] = sq[(i/3)*3 + j/3][k] = 1;
		map[i][j] = k + 1;
		if (generate(i, j+1)) return 1;
		map[i][j] = 0;
		rows[i][k] = cols[j][k] = sq[(i/3)*3 + j/3][k] = 0;
	}
	return 0;
}

int main() {
	int i, j, set = 0;

	while (1) {
		for (i = 0; i < 9; ++i) {
			for (j = 0; j < 9; ++j) {
				if (scanf("%d", &map[i][j]) != 1) return 0;
			}
		}

		printf("Case %d: ", ++set);
		if (illegal()) puts("Illegal.");
		else {
			found = 0;
			generate(0, 0);
			if (found == 0) puts("Impossible.");
			else if (found == 1) puts("Unique.");
			else puts("Ambiguous.");
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
