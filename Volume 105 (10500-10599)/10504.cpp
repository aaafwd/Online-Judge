/* @JUDGE_ID: 19899RK 10504 C++ "By Anadan" */ 
// Hidden squares
// Accepted (0.305 seconds using as much as 404 kbytes)

#include <stdio.h>

char map[100][101];

int main() {
	int N, M, i = -1, j, x, y, res;
	char str[32];

	while (scanf("%d%d", &N, &M) == 2 && N) {
		if (i != -1) putchar('\n');
		for (i = 0; i < N; ++i) scanf("%s", map[i]);
		while (M--) {
			res = 0;
			scanf("%s", str);
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					if (map[i][j] != str[0]) continue;
					for (x = 1; x < N; ++x) {
						if (i + x >= N || j + x >= N) break;
						for (y = 0; y < N; ++y) {
							if (j + y >= N || i - y < 0) break;
							if (i + x - y < 0 || j + x + y >= N) break;
							if (map[i + x][j + y] != str[0]) continue;
							if (map[i + x - y][j + y + x] != str[0]) continue;
							if (map[i - y][j + x] == str[0]) ++res;
						}
					}
				}
			}
			printf("%c %d\n", str[0], res);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
