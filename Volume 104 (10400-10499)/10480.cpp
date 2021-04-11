/* @JUDGE_ID: 19899RK 10480 C++ "By Anadan" */ 
// Sabotage
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, map[50][50];
char edges[50][50];

void ford_falkerson(int src, int dst){
	int i, j, vertexes[50], prev[50], flow[50], u, v, maxflow = 0;

	while (1){
		memset(prev, -1, sizeof(prev));
		i = 0; j = 1; vertexes[0] = src; prev[0] = 0; flow[0] = -1;
		while (i < j){
			u = vertexes[i++];
			if (u == dst){ // Reduction
				i = flow[u];
				maxflow += flow[u];
				while (prev[u] != u){
					map[prev[u]][u] -= i;
					map[u][prev[u]] += i;
					u = prev[u];
				}

				i = -1;
				break;
			}

			for (v = 0; v < N; ++v){
				if (map[u][v] && prev[v] == -1){
					vertexes[j++] = v;
					prev[v] = u;
					flow[v] = map[u][v];
					if (flow[u] != -1 && flow[v] > flow[u]){
						flow[v] = flow[u];
					}
				}
			}
		}

		if (i != -1) break;
	}

	for (i = 0; i < N; ++i){
		if (prev[i] == -1) continue;
		for (j = 0; j < N; ++j){
			if (edges[i][j] && prev[j] == -1){
				printf("%d %d\n", i + 1, j + 1);
			}
		}
	}
}

int main(){
	int M, i, j, k;

	while (scanf("%d%d\n", &N, &M) == 2 && (N || M)){
		memset(map, 0, sizeof(map));
		memset(edges, 0, sizeof(edges));
		while (M--){
			scanf("%d%d%d\n", &i, &j, &k); --i; --j;
			map[i][j] = map[j][i] = k;
			edges[i][j] =  edges[j][i] = 1;
		}

		ford_falkerson(0, 1);

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
