/* @JUDGE_ID: 19899RK 539 C++ "By Anadan" */
// The Settlers of Catan
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int N, nodes[25][3], longest;

void findlongest(int n, int cur){
	int i, j, k;

	for (i = 0; i < 3; ++i){
		if (nodes[n][i] != -1){
			j = nodes[n][i];
			nodes[n][i] = -1;
			for (k = 0; nodes[j][k] != n; ++k);
			nodes[j][k] = -1;

			findlongest(j, cur + 1);

			nodes[n][i] = j;
			nodes[j][k] = n;
		}
	}

	if (longest < cur) longest = cur;
}

int main(){
	int i, j, a, b, M;

	while (scanf("%d%d\n", &N, &M) == 2 && N){
		for (i = 0; i < N; ++i) nodes[i][0] = nodes[i][1] = nodes[i][2] = -1;
		for (i = 0; i < M; ++i){
			scanf("%d%d\n", &a, &b);
			for (j = 0; nodes[a][j] != -1; ++j); nodes[a][j] = b;
			for (j = 0; nodes[b][j] != -1; ++j); nodes[b][j] = a;
		}

		longest = -1;
		for (i = 0; i < N; ++i){
			findlongest(i, 0);
		}

		printf("%d\n", longest);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
