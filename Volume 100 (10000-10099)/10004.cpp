/* @JUDGE_ID: 19899RK 10004 C++ "By Anadan" */
// Bicoloring
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int n;
char G[200][200];

int bicolorgraph(){
	int i = 0, j = 1, count, v, u, vertexes[200];
	char mask[200], color = 3;

	memset(mask, 0, n);
	vertexes[0] = 0;
	mask[0] = color;

	while (i < j){
		color ^= 1;
		count = 0;
		while (i < j){
			v = vertexes[i++];
			for (u = 0; u < n; ++u){
				if (G[u][v]){
					if (mask[u] == 0){
						mask[u] = color;
						vertexes[j + count] = u;
						++count;
					}
					else if (mask[u] != color) return 0;
				}
			}
		}
		j += count;
	}

	return 1;
}

int main(){
	int i, j, k, l;

	while (scanf("%d", &n) == 1){
		if (n == 0) break;
		scanf("%d", &l);
		for (i = 0; i < n; i++) memset(G[i], 0, n);
		for (i = 0; i < l; i++){
			scanf("%d%d", &j, &k);
			G[j][k] = G[k][j] = 1;
		}
		if (bicolorgraph()) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
