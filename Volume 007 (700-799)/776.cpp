/* @JUDGE_ID: 19899RK 776 C++ "By Anadan" */
// Monkeys in a Regular Forest
// Accepted (0.273 seconds using as much as 908 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 102

int map[SZ][SZ], k;
char fmts[SZ][8];

void mark(int i, int j) {
	int c = map[i][j];
	map[i][j] = k;

	if (map[i - 1][j - 1] == c) mark(i - 1, j - 1);
	if (map[i - 1][j] == c) mark(i - 1, j);
	if (map[i - 1][j + 1] == c) mark(i - 1, j + 1);
	if (map[i][j - 1] == c) mark(i, j - 1);
	if (map[i][j + 1] == c) mark(i, j + 1);
	if (map[i + 1][j - 1] == c) mark(i + 1, j - 1);
	if (map[i + 1][j] == c) mark(i + 1, j);
	if (map[i + 1][j + 1] == c) mark(i + 1, j + 1);
}

int main() {
	int i, j, mx, N, M;
	char str[256], *p;

	for (i = 0; i < SZ; ++i) map[0][i] = map[i][0] = 0;
	while (1) {
		N = 1;
		while (gets(str) && str[0] != '%') {
			M = 1;
			p = strtok(str, " ");
			while (p) {
				map[N][M++] = 10000 + *p;
				p = strtok(NULL, " ");
			}

			map[N++][M] = 0;
		}

		if (N == 1) break;
		for (i = 0; i <= M; ++i) map[N][i] = 0;

		for (k = i = 1; i < N; ++i) {
			for (j = 1; j < M; ++j) {
				if (map[i][j] > 10000) {
					mark(i, j);
					k++;
				}
			}
		}

		for (j = 1; j < M; ++j) {
			mx = map[1][j];
			for (i = 2; i < N; ++i) {
				if (mx < map[i][j]) mx = map[i][j];
			}
			sprintf(str, "%d", mx);
			sprintf(fmts[j], "%%%dd", strlen(str));
		}

		for (i = 1; i < N; ++i) {
			printf(fmts[1], map[i][1]);
			for (j = 2; j < M; ++j) {
				putchar(' ');
				printf(fmts[j], map[i][j]);
			}
			putchar('\n');
		}
		puts("%");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
