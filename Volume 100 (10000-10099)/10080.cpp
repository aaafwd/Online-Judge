/* @JUDGE_ID: 19899RK 10080 C++ "By Anadan" */ 
// Gopher II
// Accepted (1.898 seconds using as much as 432 kbytes)
// Too much time !

#include <stdio.h>
#include <string.h>
#define SZ 202

int N, src, dst;
char map[SZ][SZ];

inline double sqr(double x) { return x * x; }

int maxflow(){
	int preflow[SZ], level[SZ], i, j, minl;
	char changed;

	for (i = 0; i < N; ++i) preflow[i] = level[i] = 0;
	level[src] = N;

	changed = 1;
	while (changed){
		changed = 0;
		for (i = 0; i < N; ++i){
			if (i == dst || (i != src && preflow[i] == 0)) continue;

		 	if (i != src){
			 	minl = 2 * N;
				for (j = 0; j < N; ++j){
					if (map[i][j] && minl > level[j]) minl = level[j];
				}

				if (minl >= level[i]) level[i] = minl + 1;
		 	}

		 	for (j = 0; j < N; ++j){
				if (map[i][j] == 0 || level[i] <= level[j]) continue;
		 	  	minl = map[i][j];
		 	  	if (i != src && minl > preflow[i]) minl = preflow[i];
		 	  	preflow[j] += minl;
		 	  	map[i][j] -= minl;
		 	  	map[j][i] += minl;
		 	  	changed = 1;
		 	  	if (i != src){
			 	  	preflow[i] -= minl;
			 	  	if (preflow[i] == 0) break;
		 	  	}
		 	}
		}
	}

	return preflow[dst];
}

int main(){
	int s, v, i, j, n, m;
	double xx[100], yy[100], x, y;

	while (scanf("%d%d%d%d\n", &n, &m, &s, &v) == 4){
		N = n + m + 2;
		for (i = 0; i < N; ++i) memset(map[i], 0, N);
		for (i = 0; i < n; ++i) scanf("%lf%lf\n", xx + i, yy + i);

		s *= v; s *= s;

		for (j = 0; j < m; ++j){
			scanf("%lf%lf", &x, &y);
			for (i = 0; i < n; ++i){
				if (sqr(xx[i] - x) + sqr(yy[i] - y) - 1e-10 <= s){
					map[i][n + j] = 1;
				}
			}
		}

		src = N - 2;
		dst = N - 1;

	 	for (i = 0; i < n; ++i) map[src][i] = 1;
	 	for (j = 0; j < m; ++j) map[n + j][dst] = 1;

	 	printf("%d\n", n - maxflow());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
