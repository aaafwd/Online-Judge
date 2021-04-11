/* @JUDGE_ID: 19899RK 10330 C++ "By Anadan" */ 
// Power Transmission
// Accepted (0.135 seconds using as much as 548 kbytes)

#include <stdio.h>
#include <string.h>

int N, map[200][200];
char mask[200];

int maxflow(){
	int i, j, k, v, vertexes[200], prev[200], flow[200], maxflow = 0;

	while (1){
		memset(prev, -1, sizeof(int) * N);
		for (i = j = k = 0; k < N; ++k){
			if (mask[k] == 1){
				vertexes[j++] = k;
				prev[k] = k;
				flow[k] = -1;
			}
		}

		while (i < j){
			v = vertexes[i++];
			if (mask[v] == 2){ // Reduction
				i = flow[v];
				maxflow += flow[v];
				while (prev[v] != v){
					map[prev[v]][v] -= i;
					map[v][prev[v]] += i;
					v = prev[v];
				}

				i = -1;
				break;
			}

			for (k = 0; k < N; ++k){
				if (map[v][k] && prev[k] == -1){
					vertexes[j++] = k;
					prev[k] = v;
					flow[k] = map[v][k];
					if (flow[v] != -1 && flow[k] > flow[v]){
						flow[k] = flow[v];
					}
				}
			}
		}

		if (i != -1) break;
	}

	return maxflow;
}

int main(){
	int i, j, k, M;

	while (scanf("%d", &N) == 1){
		for (i = 0; i < N; ++i){
			memset(map[i], 0, sizeof(int) * (N + N));
			memset(map[N + i], 0, sizeof(int) * (N + N));
			scanf("%d", &map[i][N + i]);
		}

		scanf("%d", &M);
		while (M--){
			scanf("%d%d%d", &i, &j, &k); --i; --j;
			map[i + N][j] = k;
		}

		memset(mask, 0, N + N);
		scanf("%d%d", &i, &j);
		while (i--){
			scanf("%d", &k);
			mask[k - 1] = 1;
		}
		while (j--){
			scanf("%d", &k);
			mask[k - 1 + N] = 2;
		}

		N <<= 1;
		printf("%d\n", maxflow());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
