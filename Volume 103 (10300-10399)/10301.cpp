/* @JUDGE_ID: 19899RK 10301 C++ "By Anadan" */
// Rings and Glue
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Ring{
	double x, y, r;
}pt[100];
int N;
char map[100][100];

inline double sqr(double x) { return x * x; }

int getrings(){
	int i, j, k, v, u, vertexes[100], res = 0;
	char mask[100];

	memset(mask, 0, N);
	for (k = 0; k < N; ++k){
		if (mask[k]) continue;
		i = 0; j = 1; vertexes[0] = k;
		mask[k] = 1;
		while (i < j){
			v = vertexes[i++];
			for (u = 0; u < N; ++ u){
				if (mask[u] == 0 && map[v][u]){
					mask[u] = 1;
					vertexes[j++] = u;
				}
			}
		}
		if (res < j) res = j;
	}

	return res;
}

int main(){
	int i, j;
	double tmp;

	while (scanf("%d\n", &N) == 1 && N != -1){
		for (i = 0; i < N; ++i){
			scanf("%lf", &tmp); pt[i].x = tmp;
			scanf("%lf", &tmp); pt[i].y = tmp;
			scanf("%lf", &tmp); pt[i].r = tmp;
			for (j = 0; j < N; ++j) map[i][j] = 0;
		}

		for (i = 0; i < N; ++i){
			for (j = i + 1; j < N; ++j){
				tmp = sqr(pt[j].x - pt[i].x) + sqr(pt[j].y - pt[i].y);
				if (tmp > sqr(pt[i].r + pt[j].r)) continue;
				if (tmp < sqr(pt[i].r - pt[j].r)) continue;
				map[i][j] = map[j][i] = 1;
			}
		}

		i = getrings();
		if (i == 1) printf("The largest component contains 1 ring.\n");
		else printf("The largest component contains %d rings.\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
