/* @JUDGE_ID: 19899RK 601 C++ "By Anadan" */
// The PATH
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Point { int x, y; };
int N;
char map[80][81], path[2][80][81];

void setwave(int r, int c, int p, char ch) {
	int i = 0, j = 1, k;
	Point pt[1600];
	path[p][r][c] = 1;
	pt[0].x = r; pt[0].y = c;

	while (i < j) {
		r = pt[i].x; c = pt[i].y; ++i;
		if (r) {
			if (path[p][r - 1][c] == 0 && map[r - 1][c] == ch) {
				pt[j].x = r - 1; pt[j].y = c;
				path[p][r - 1][c] = 1;
				++j;
			}

			if (map[r - 1][c] == 'U') path[p][r - 1][c] = -1;
		}

		if (r < N - 1) {
			if (path[p][r + 1][c] == 0 && map[r + 1][c] == ch) {
				pt[j].x = r + 1; pt[j].y = c;
				path[p][r + 1][c] = 1;
				++j;
			}

			if (map[r + 1][c] == 'U') path[p][r + 1][c] = -1;
		}

		if (c) {
			if (path[p][r][c - 1] == 0 && map[r][c - 1] == ch) {
				pt[j].x = r; pt[j].y = c - 1;
				path[p][r][c - 1] = 1;
				++j;
			}

			if (map[r][c - 1] == 'U') path[p][r][c - 1] = -1;
		}

		if (c < N - 1) {
			if (path[p][r][c + 1] == 0 && map[r][c + 1] == ch) {
				pt[j].x = r; pt[j].y = c + 1;
				path[p][r][c + 1] = 1;
				++j;
			}

			if (map[r][c + 1] == 'U') path[p][r][c + 1] = -1;
		}
	}
}

int main() {
	int i, j;
	char win_in_move;

	while (scanf("%d", &N) == 1) {
		if (N == 0) break;
		for (i = 0; i < N; ++i) {
			scanf("%s\n", map[i]);
			memset(path[0][i], 0, N);
			memset(path[1][i], 0, N);
		}

		for (i = 0; i < N; ++i) {
			if (map[i][0] == 'W') setwave(i, 0, 0, 'W');
			else if (map[i][0] == 'U') path[0][i][0] = -1;
			if (map[i][N - 1] == 'W') setwave(i, N - 1, 1, 'W');
			else if (map[i][N - 1] == 'U') path[1][i][N - 1] = -1;
		}
		for (win_in_move = 0, i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (path[0][i][j] == 1 && path[1][i][j] == 1) {
					printf("White has a winning path.\n");
					goto next_set;
				}
				if (path[0][i][j] == -1 && path[1][i][j] == -1)
					win_in_move = 1;
			}
		}
		if (win_in_move) {
			printf("White can win in one move.\n");
			goto next_set;
		}

		for (i = 0; i < N; ++i) {
			memset(path[0][i], 0, N);
			memset(path[1][i], 0, N);
		}
		for (i = 0; i < N; ++i) {
			if (map[0][i] == 'B') setwave(0, i, 0, 'B');
			else if (map[0][i] == 'U') path[0][0][i] = -1;
			if (map[N - 1][i] == 'B') setwave(N - 1, i, 1, 'B');
			else if (map[N - 1][i] == 'U') path[1][N - 1][i] = -1;
		}
		for (win_in_move = 0, i = 0; i < N; ++i) {
			for (j = 0; j < N; ++j) {
				if (path[0][i][j] == 1 && path[1][i][j] == 1) {
					printf("Black has a winning path.\n");
					goto next_set;
				}
				if (path[0][i][j] == -1 && path[1][i][j] == -1)
					win_in_move = 1;
			}
		}
		if (win_in_move) printf("Black can win in one move.\n");
		else printf("There is no winning path.\n");

		next_set: continue;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
