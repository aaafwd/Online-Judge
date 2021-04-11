/* @JUDGE_ID: 19899RK 10804 C++ "By Anadan" */
// Gopher Strategy
// Accepted (0.430 seconds using as much as 432 kbytes)

#include <stdio.h>
#include <math.h>
#include <string.h>
#define SZ 50
#define EPS 1e-5

struct Point {
	double x, y;
} gopher[SZ], hole[SZ];
int N, M, loss, map[SZ][SZ], nv[SZ], pair[SZ];
double dist[SZ][SZ];
char was[SZ];

inline double sqr(double x) { return x * x; }

int findway(int u) {
	int i, v;
	for (i = 0; i < nv[u]; ++i) {
		v = map[u][i];
		if (was[v]) continue;
		was[v] = 1;
		if (pair[v] == -1 || findway(pair[v])) {
			pair[v] = u;
			return 1;
		}
	}
	return 0;
}

int maxpair(double threshold) {
	int res = 0, i, j;

	for (i = 0; i < N; ++i) {
		nv[i] = 0;
		for (j = 0; j < M; ++j) {
			if (dist[i][j] <= threshold - EPS) map[i][nv[i]++] = j;
		}
	}

	memset(pair, -1, sizeof(pair));
	for (i = 0; i < N; ++i) {
		memset(was, 0, N);
		res += findway(i);
	}
	return res;
}

int main() {
	int set, cs = 0, i, j;
	double min, max, threshold;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d%d", &N, &M, &loss);
		for (i = 0; i < N; ++i) scanf("%lf%lf", &gopher[i].x, &gopher[i].y);
		for (i = 0; i < M; ++i) scanf("%lf%lf", &hole[i].x, &hole[i].y);

		printf("Case #%d:\n", ++cs);
		if (N - loss > M) puts("Too bad.\n");
		else if (N == loss) puts("0.000\n");
		else {
			min = max = -1;
			for (i = 0; i < N; ++i) for (j = 0; j < M; ++j) {
				dist[i][j] = sqrt(sqr(gopher[i].x - hole[j].x) + sqr(gopher[i].y - hole[j].y));
				if (min < 0 || min > dist[i][j]) min = dist[i][j];
				if (max < dist[i][j]) max = dist[i][j];
			}

			while (min <= max - EPS) {
				threshold = (min + max) * 0.5;
				if (maxpair(threshold) >= N - loss) max = threshold;
				else min = threshold;
			}
			threshold = (min + max) * 0.5;
			printf("%.3lf\n\n", threshold);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
