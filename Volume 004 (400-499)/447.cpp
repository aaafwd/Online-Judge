/* @JUDGE_ID: 19899RK 447 C++ "By Anadan" */ 
// Population Explosion
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>

int main() {
	int set, yy, i, j, k, c;
	char map[2][22][22], str[256];

	for (i = 0; i < 22; ++i) {
		map[0][0][i] = map[0][i][0] = map[1][0][i] = map[1][i][0] = 0;
		map[0][21][i] = map[0][i][21] = map[1][21][i] = map[1][i][21] = 0;
	}

	scanf("%d\n\n", &set);
	while (set--) {
		c = 0;
		for (i = 1; i <= 20; ++i) for (j = 1; j <= 20; ++j) map[0][i][j] = 0;
		gets(str); sscanf(str, "%d", &yy);
		while (gets(str) && sscanf(str, "%d%d", &i, &j) == 2) {
			map[0][i][j] = 1;
		}

		puts("********************");
		while (1) {
			for (i = 1; i <= 20; ++i) {
				for (j = 1; j <= 20; ++j) {
					if (map[c][i][j]) putchar('O');
					else putchar(' ');
				}
				putchar('\n');
			}
			puts("********************");
			if (--yy == 0) break;

			for (i = 1; i <= 20; ++i) for (j = 1; j <= 20; ++j) {
				k  = map[c][i - 1][j - 1] + map[c][i - 1][j] + map[c][i - 1][j + 1];
				k += map[c][i + 1][j - 1] + map[c][i + 1][j] + map[c][i + 1][j + 1];
				k += map[c][i][j - 1] + map[c][i][j + 1];
				if (map[c][i][j]) {
					if (k == 2 || k == 3) map[c ^ 1][i][j] = 1;
					else map[c ^ 1][i][j] = 0;
				}else{
					if (k == 3) map[c ^ 1][i][j] = 1;
					else map[c ^ 1][i][j] = 0;
				}
			}

			c ^= 1;
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
