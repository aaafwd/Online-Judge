/* @JUDGE_ID: 19899RK 677 C++ "By Anadan" */ 
// All Walks of length n from the first node
// Accepted (0.256 seconds using as much as 384 kbytes)

#include <stdio.h>

int N, P, curr[10];
char map[10][10], mask[10], solved;

void findpath(int n, int v){
	int i;
	
	curr[n] = v;
	if (n == P){
		printf("(1");
		for (i = 1; i <= n; ++i) printf(",%d", curr[i] + 1);
		printf(")\n");
		solved = 1;
		return;
	}

	for (i = 0; i < N; ++i){
		if (mask[i] == 0 && map[v][i]){
			mask[i] = 1;
			findpath(n + 1, i);
			mask[i] = 0;
		}
	}
}

int main(){
	int i, j, k;

	while (scanf("%d%d\n", &N, &P) == 2){
		for (i = 0; i < N; ++i){
			mask[i] = 0;
			for (j = 0; j < N; ++j){
				scanf("%d", &k);
				map[i][j] = k;
			}
		}

		solved = 0;
		mask[0] = 1;
		findpath(0, 0);
		if (!solved) printf("no walk of length %d\n", P);
		if (scanf("%d", &k) == 1) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
