/* @JUDGE_ID: 19899RK 10459 C++ "By Anadan" */ 
// The Tree Root
// Accepted (0.674 seconds using as much as 772 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, dv[5000], *map[5000], dist[5000], diam[5000];
char mask[5000];

void getdist(int v){
	int i;

	mask[v] = 1;
	dist[v] = 1;

	for (i = 0; i < dv[v]; ++i){
		if (mask[map[v][i]] == 0){
			getdist(map[v][i]);
			if (dist[v] < dist[map[v][i]] + 1){
				dist[v] = dist[map[v][i]] + 1;
			}
		}
	}
}

void getdiam(int v){
	int i, j, max;

	mask[v] = 1;
	diam[v] = dist[v];

	for (i = 0; i < dv[v]; ++i){
		if (mask[map[v][i]] == 0){
			max = 0;
			for (j = 0; j < dv[v]; ++j){
				if (map[v][i] == map[v][j]) continue;
				if (max < dist[map[v][j]]) max = dist[map[v][j]];
			}
			++max;

			j = dist[map[v][i]];
			if (dist[map[v][i]] < max + 1) dist[map[v][i]] = max + 1;
			max ^= dist[v] ^= max ^= dist[v];
			getdiam(map[v][i]);
			max ^= dist[v] ^= max ^= dist[v];
			dist[map[v][i]] = j;
		}
	}
}

int main(){
	int i, j, min, max;

	while (scanf("%d\n", &N) == 1){
		for (i = 0; i < N; ++i){
			scanf("%d", dv + i);
			if (dv[i]){
				map[i] = (int *)malloc(sizeof(int) * dv[i]);
				for (j = 0; j < dv[i]; ++j){
					scanf("%d", &map[i][j]);
					--map[i][j];
				}
			}else map[i] = NULL;
		}

		memset(mask, 0, N);
		getdist(0);
		memset(mask, 0, N);
		getdiam(0);

		min = 7000; max = 0;
		for (i = 0; i < N; ++i){
			if (min > diam[i]) min = diam[i];
			if (max < diam[i]) max = diam[i];
		}

		printf("Best Roots  :");
		for (i = 0; i < N; ++i) if (diam[i] == min) printf(" %d", i + 1);
		printf("\nWorst Roots :");
		for (i = 0; i < N; ++i) if (diam[i] == max) printf(" %d", i + 1);
		putchar('\n');

		for (i = 0; i < N; ++i) if (map[i]) free(map[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
