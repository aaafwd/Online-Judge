/* @JUDGE_ID: 19899RK 10803 C++ "By Anadan" */
// Thunder Mountain
// Accepted (0.883 seconds using as much as 476 kbytes)

#include <stdio.h>
#include <math.h>

struct Point{
	int x, y;
} pt[100];
double map[100][100];

inline int sqr(int x) { return x * x; }

int main() {
	int set, cs = 0, i, j, k, N, tmp;
	double max;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i) {
			scanf("%d%d", &pt[i].x, &pt[i].y);
			map[i][i] = -1;
			for (j = 0; j < i; ++j) {
				tmp = sqr(pt[i].x - pt[j].x) + sqr(pt[i].y - pt[j].y);
				if (tmp <= 100) map[i][j] = map[j][i] = sqrt(tmp);
				else map[i][j] = map[j][i] = -1;
			}
		}

		for (k = 0; k < N; ++k) {
			for (i = 0; i < N; ++i) {
				if (i == k || map[i][k] < 0) continue;
				for (j = 0; j < N; ++j) {
					if (j == k || map[k][j] < 0) continue;
					if (map[i][j] < 0 || map[i][j] > map[i][k] + map[k][j]) {
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}

		max = -1;
		for (i = 0; i < N; ++i) {
			for (j = i + 1; j < N; ++j) {
				if (map[i][j] < 0) { max = -1; break; }
				if (max < map[i][j]) max = map[i][j];
			}
			if (j < N) break;
		}

		printf("Case #%d:\n", ++cs);
		if (max < 0) puts("Send Kurdy\n");
		else printf("%.4lf\n\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
