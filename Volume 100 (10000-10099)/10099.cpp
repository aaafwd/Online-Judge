/* @JUDGE_ID: 19899RK 10099 C++ "By Anadan" */ 
// The Tourist Guide
// Accepted (0.025 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 100

int N, src, dst;
int map[SZ][SZ];

int maxpath(){
 	int path[SZ], mask[SZ], i, j, k, cur = 1, max = 0;
 	char changed;

	for (i = 0; i < N; ++i) path[i] = mask[i] = 0;
	mask[src] = 1;

	changed = 1;
	while (changed){
		changed = 0;
	 	for (i = 0; i < N; ++i){
	 		if (i == dst) continue;
	 	 	if (mask[i] == cur){
	 	 		if (i != src && path[i] <= max) continue;
				for (j = 0; j < N; ++j){
				  	if (map[i][j] == 0 || j == src) continue;
				  	k = map[i][j];
				  	if (i != src && k > path[i]) k = path[i];
					if (path[j] >= k) continue;
					path[j] = k;
					mask[j] = cur + 1;
					changed = 1;
				}

				max = path[dst];
	 	 	}
	 	}

		++cur;
	}

	return max;
}

int main(){
	int i, j, k, R, set = 0;

	while (scanf("%d%d\n", &N, &R) == 2){
		if (N == 0 && R == 0) break;
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j) map[i][j] = 0;
		while (R--){
			scanf("%d%d%d\n", &i, &j, &k);
			--i; --j;
			map[i][j] = map[j][i] = k;
		}

		scanf("%d%d%d\n", &src, &dst, &R);
		--src; --dst;

		if (src == dst) R = 0;
		else{
			k = maxpath() - 1;
			R = (R + k - 1) / k;
		}

		printf("Scenario #%d\n", ++set);
		printf("Minimum Number of Trips = %d\n\n", R);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
