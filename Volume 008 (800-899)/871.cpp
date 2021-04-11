/* @JUDGE_ID: 19899RK 871 C++ "By Anadan" */
// Counting Cells in a Blob
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int rows, cols, count;
char map[32][32];

void fill(int i, int j) {
	++count;
	map[i][j] = '0';
	if (i) {
		if (map[i-1][j] == '1') fill(i-1,j);
		if (j && map[i-1][j-1] == '1') fill(i-1,j-1);
		if (j+1 < cols && map[i-1][j+1] == '1') fill(i-1,j+1);
	}
	if (i+1 < rows) {
		if (map[i+1][j] == '1') fill(i+1,j);
		if (j && map[i+1][j-1] == '1') fill(i+1,j-1);
		if (j+1 < cols && map[i+1][j+1] == '1') fill(i+1,j+1);
	}
	if (j && map[i][j-1] == '1') fill(i,j-1);
	if (j+1 < cols && map[i][j+1] == '1') fill(i,j+1);
}

int main() {
	int set, i, j, res;

	scanf("%d\n", &set);
	while (set--) {
		rows = 0;
		while (gets(map[rows]) && map[rows][0]) ++rows;
		cols = strlen(map[0]);
		res = 0;
		for (i = 0; i < rows; ++i) {
			for (j = 0; j < cols; ++j) {
				if (map[i][j] == '1') {
					count = 0;
					fill(i, j);
					if (res < count) res = count;
				}
			}
		}

		printf("%d\n", res);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
