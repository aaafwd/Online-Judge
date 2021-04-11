/* @JUDGE_ID: 19899RK 459 C++ "By Anadan" */
// Graph Connectivity
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N;
char G[26][26], mask[26];

void setwave(int v){
	int i = 0, j = 1, u, vertexes[26];
	vertexes[0] = v;
	mask[v] = 1;

	while (i < j){
		v = vertexes[i++];
		for (u = 0; u < N; ++u){
			if (G[v][u] && mask[u] == 0){
				mask[u] = 1;
				vertexes[j++] = u;
			}
		}
	}
}

int main(){
	int set, i, res;
	char str[3];

	scanf("%d\n\n", &set);
	scanf("%s\n", str);
	while (set--){
		N = str[0] - 'A' + 1;
		for (i = 0; i < N; ++i) memset(G[i], 0, N);
		while (scanf("%s\n", str) == 1 && str[1]){
			G[str[0] - 'A'][str[1] - 'A'] =
			G[str[1] - 'A'][str[0] - 'A'] = 1;
		}

		memset(mask, 0, N);
		for (res = i = 0; i < N; ++i){
			if (mask[i] == 0){
				setwave(i);
				++res;
			}
		}

		printf("%d\n", res);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
