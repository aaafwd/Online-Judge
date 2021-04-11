/* @JUDGE_ID: 19899RK 670 C++ "By Anadan" */
// The dog task
// Accepted (0.064 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <math.h>

struct Point{
	int x, y;
} pt[100], places[100];
int N, M, map[100][100], nv[100], pair[100], revPair[100];
char was[100];

int findway(int u) {
	int i, v;
	for (i = 0; i < nv[u]; ++i) {
		v = map[u][i];
		if (was[v]) continue;
		was[v] = 1;
		if (revPair[v] == -1 || findway(revPair[v])) {
			revPair[v] = u;
			pair[u] = v;
			return 1;
		}
	}
	return 0;
}

int maxpair() {
	int res = 0, i;
	memset(pair, -1, sizeof(pair));
	memset(revPair, -1, sizeof(revPair));
	for (i = 0; i < N; ++i) {
		memset(was, 0, sizeof(was));
		res += findway(i);
	}
	return res;
}

inline int sqr(int x) { return x * x; }

int reachable(int i, int pl) {
	int dist = (sqr(pt[i].x - pt[i+1].x) + sqr(pt[i].y - pt[i+1].y))*4;

	double t1 = sqrt(sqr(pt[i].x - places[pl].x) + sqr(pt[i].y - places[pl].y));
	double t2 = sqrt(sqr(pt[i+1].x - places[pl].x) + sqr(pt[i+1].y - places[pl].y));

	return ((t1+t2)*(t1+t2) <= dist);
}

int main() {
	int set, i, j;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &N, &M);
		for (i = 0; i < N; ++i) scanf("%d%d", &pt[i].x, &pt[i].y);
		for (i = 0; i < M; ++i) scanf("%d%d", &places[i].x, &places[i].y);

		for (i = 0; i < N - 1; ++i) {
			nv[i] = 0;
			for (j = 0; j < M; ++j) {
				if (reachable(i, j)) map[i][nv[i]++] = j;
			}
		}

		--N;
		printf("%d\n", N + 1 + maxpair());
		++N;

		printf("%d %d", pt[0].x, pt[0].y);
		for (i = 1; i < N; ++i) {
			j = pair[i - 1];
			if (j != -1) {
				printf(" %d %d", places[j].x, places[j].y);
			}
			printf(" %d %d", pt[i].x, pt[i].y);
		}
		putchar('\n');

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
