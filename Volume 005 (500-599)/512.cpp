/* @JUDGE_ID: 19899RK 512 C++ "By Anadan" */
// Spreadsheet Tracking
// Accepted (0.432 seconds using as much as 404 kbytes)

#include <stdio.h>
#define SZ 50

int map[SZ][SZ];
int rows, cols;

void deleteRows(int * nums, int N) {
	int i, j, n;

	for (j = 0; j < cols; ++j) {
		n = 0;
		for (i = 0; i < rows; ++i) {
			if (n < N && i == nums[n]) {
				++n;
				continue;
			}
			map[i - n][j] = map[i][j];
		}
	}
	rows -= N;
}

void deleteCols(int * nums, int N) {
	int i, j, n;

	for (i = 0; i < rows; ++i) {
		n = 0;
		for (j = 0; j < cols; ++j) {
			if (n < N && j == nums[n]) {
				++n;
				continue;
			}
			map[i][j - n] = map[i][j];
		}
	}
	cols -= N;
}

void insertRows(int * nums, int N) {
	int i, j, n;

	for (j = 0; j < cols; ++j) {
		n = N - 1;
		for (i = rows-1; i >= 0; --i) {
			map[i + n + 1][j] = map[i][j];
			if (n >= 0 && i == nums[n]) {
				map[i + n--][j] = -1;
			}
		}
	}
	rows += N;
}

void insertCols(int * nums, int N) {
	int i, j, n;

	for (i = 0; i < rows; ++i) {
		n = N - 1;
		for (j = cols-1; j >= 0; --j) {
			map[i][j + n + 1] = map[i][j];
			if (n >= 0 && j == nums[n]) {
				map[i][j + n--] = -1;
			}
		}
	}
	cols += N;
}

void solve(int N) {
	int i, j;
	for (i = 0; i < rows; ++i) {
		for (j = 0; j < cols; ++j) {
			if (map[i][j] == N) {
				printf("moved to (%d,%d)\n", i+1, j+1);
				return;
			}
		}
	}
	puts("GONE");
}

int main() {
	int set = 0, i, j, savCols, A, N, x[SZ];
	char cmd[4];

	while (scanf("%d%d%d", &rows, &cols, &N) == 3 && (rows || cols)) {
		savCols = cols;
		for (i = 0; i < rows; ++i) {
			for (j = 0; j < cols; ++j) map[i][j] = i*cols + j;
		}

		while (N--) {
			scanf("%s", cmd);
			if (cmd[0] == 'E') {
				int r1, c1, r2, c2;
				scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
				--r1; --c1; --r2; --c2;
				i = map[r1][c1]; map[r1][c1] = map[r2][c2]; map[r2][c2] = i;
			} else {
				scanf("%d", &A);
				for (i = 0; i < A; ++i) { scanf("%d", x+i); --x[i]; }
				for (i = 0; i < A-1; ++i) {
					if (x[i] > x[i+1]) {
						j = x[i]; x[i] = x[i+1]; x[i+1] = j;
						if (i) i -= 2;
					}
				} 

				if (cmd[0] =='D') {
					if (cmd[1] == 'R') deleteRows(x, A);
					else deleteCols(x, A);
				} else if (cmd[0] =='I') {
					if (cmd[1] == 'R') insertRows(x, A);
					else insertCols(x, A);
				}
			}
		}

		if (set) putchar('\n');
		printf("Spreadsheet #%d\n", ++set);
		scanf("%d", &N);
		while (N--) {
			scanf("%d%d", &i, &j);
			printf("Cell data in (%d,%d) ", i, j);
			solve((i-1)*savCols + j-1);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
