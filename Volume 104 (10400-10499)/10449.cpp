/* @JUDGE_ID: 19899RK 10449 C++ "By Anadan" */ 
// Traffic
// Accepted (0.697 seconds using as much as 588 kbytes)

#include <stdio.h>
#include <string.h>
#define MAX 1000000

int N, cost[200][200], earn[200];
char map[200][200];

inline int sqr3(int x) { return x * x * x; }

void findpath(){
	int i, j, k;

	for (i = 1; i < N; ++i) earn[i] = MAX;
	earn[0] = 0;

	for (i = 1; i < N; ++i){
		for (j = 0; j < N; ++j){
			if (earn[j] == MAX) continue;
			for (k = 0; k < N; ++k){
				if (map[j][k] == 0) continue;
				if (earn[k] == MAX || earn[k] > earn[j] + cost[j][k]){
					earn[k] = earn[j] + cost[j][k];
				}
			}
		}
	}

	for (j = 0; j < N; ++j){
		if (earn[j] == MAX) continue;
		for (k = 0; k < N; ++k){
			if (map[j][k] == 0) continue;
			if (earn[k] == MAX || earn[k] > earn[j] + cost[j][k]){
				earn[k] = -MAX;
			}
		}
	}

	for (i = 0; i < N; ++i) if (earn[i] == MAX) earn[i] = -1;
}

int main(){
	int set = 0, i, j, k, busyness[200];

	while (scanf("%d\n", &N) == 1){
		memset(map, 0, sizeof(map));
		for (i = 0; i < N; ++i) scanf("%d", busyness + i);
		scanf("%d\n", &k);
		while (k--){
			scanf("%d%d\n", &i, &j); --i; --j;
			map[i][j] = 1;
			cost[i][j] = sqr3(busyness[j] - busyness[i]);
		}

		findpath();
		earn[0] = 0;
		scanf("%d\n", &k);
		printf("Set #%d\n", ++set);
		while (k--){
			scanf("%d\n", &i); --i;
			if (earn[i] < 3) printf("?\n");
			else printf("%d\n", earn[i]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
