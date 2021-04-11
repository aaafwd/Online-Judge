/* @JUDGE_ID: 19899RK 336 C++ "By Anadan" */
// A Node Too Far
// Accepted (0.623 seconds using as much as 388 kbytes)

#include <stdio.h>
#define SZ 30

int vertexes[SZ], index;

int getindex(int v){
	int i;
	for (i = 0; i < index; ++i) if (vertexes[i] == v) return i;
	vertexes[i] = v;
	return index++;
}

int main(){
	int i, j, k, l, N, set = 0;
	char map[SZ][SZ];

	while (scanf("%d\n", &N) == 1 && N){
		index = 0;
		for (i = 0; i < SZ; ++i) for (j = 0; j < SZ; ++j){
			map[i][j] = -1;
		}

		while (N--){
			scanf("%d%d", &i, &j);
			i = getindex(i);
			j = getindex(j);
			map[i][j] = map[j][i] = 1;
		}

		for (k = 0; k < index; ++k){
			for (i = 0; i < index; ++i){
				if (i == k || map[i][k] == -1) continue;
				for (j = 0; j < index; ++j){
					if (j == k || map[k][j] == -1) continue;
					if (map[i][j] == -1 || map[i][j] > map[i][k] + map[k][j])
						map[i][j] = map[i][k] + map[k][j];
				}
			}
		}

		while (scanf("%d%d", &l, &j) == 2){
			if (l == 0 && j == 0) break;
			i = getindex(l);
			for (N = k = 0; k < index; ++k){
				if (i == k) ++N;
				else if (map[i][k] != -1 && map[i][k] <= j) ++N;
			}

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++set, index - N, l, j);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
