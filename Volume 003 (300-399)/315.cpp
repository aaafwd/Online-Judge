/* @JUDGE_ID: 19899RK 315 C++ "By Anadan" */
// Network
// Accepted (0.960 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <string.h>

int N;
char G[100][100], mask[100];

int iscoherence(int n){
	int vertexes[100];
	int i = 0, j = 1, k;
	mask[n] = 1;
	vertexes[0] = n;

	while (i < j && j < N){
		n = vertexes[i++];
		for (k = 0; k < N; ++k){
			if (mask[k] || G[n][k] == 0) continue;
			mask[k] = 1;
			vertexes[j++] = k;
		}
	}

	if (j == N - 1) return 1;
	return 0;
}

int main(){
	int i, j, off, res;
	char str[256], *p;

	while (scanf("%d\n", &N) == 1){
		if (N == 0) break;
		for (i = 0; i < N; ++i) memset(G[i], 0, N);
		while (gets(str)){
			p = str;
			sscanf(p, "%d%n", &i, &off);
			if (i == 0) break;
			p += off;
			--i;
			while (sscanf(p, "%d%n", &j, &off) > 0){
				--j;
				G[i][j] = G[j][i] = 1;
				p += off;
			}
		}

		if (N == 1){
			printf("1\n");
			continue;
		}

		memset(mask, 0, N);
		mask[0] = 1;
		if (iscoherence(1)) res = 0; else res = 1;

		for (i = 1; i < N; ++i){
			memset(mask, 0, N);
			mask[i] = 1;
			if (!iscoherence(0)) ++res;
		}
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
