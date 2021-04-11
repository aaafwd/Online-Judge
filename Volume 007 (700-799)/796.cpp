/* @JUDGE_ID: 19899RK 796 C++ "By Anadan" */ 
// Critical Links
// Accepted (0.074 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 100

int N;
char map[SZ][SZ];

int connected(int v, int u){
	int i = 0, j = 1, k, vertexes[SZ];
	char mask[SZ];

	memset(mask, 0, N);
	mask[v] = 1;
	vertexes[0] = v;

	while (i < j){
		v = vertexes[i++];
		for (k = 0; k < N; ++k){
			if (map[v][k] && mask[k] == 0){
				if (k == u) return 1;
				mask[k] = 1;
				vertexes[j++] = k;
			}
		}
	}

	return 0;
}

int main(){
	int i, j, k, m;
	char result[2048], *p;

	while (scanf("%d\n", &N) == 1){
		for (k = 0; k < N; ++k){
			scanf("%d%*1s%d%*1s", &i, &m);
			memset(map[i], 0, N);
			while (m--){
				scanf("%d", &j);
				map[i][j] = 1;
			}
		}

		result[0] = 0; p = result;
		for (m = i = 0; i < N; ++i){
			for (j = i + 1; j < N; ++j){
				if (!map[i][j]) continue;
				map[i][j] = map[j][i] = 0;
				if (!connected(i, j)){
					++m;
					sprintf(p, "%d - %d\n%n", i, j, &k);
					p += k;
				}
				map[i][j] = map[j][i] = 1;
			}
		}

		printf("%d critical links\n%s\n", m, result);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
