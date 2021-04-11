/* @JUDGE_ID: 19899RK 104 C++ "By Anadan" */
// Arbitrage
// Accepted (0.187 seconds using as much as 460 kbytes)

#include <stdio.h>

int N;
double arbitrage[20][20];

int exist_arbitrage(){
	int b, k, i, j, stack[20];
	char path[20][20][20];
	double map[20][20][20], max, tmp;

	for (b = 0; b < N; ++b) for (i = 0; i < N; ++i)
		map[b][i][0] = arbitrage[b][i];

	for (k = 1; k < N; ++k){
		for (b = 0; b < N; ++b){
			for (i = 0; i < N; ++i){
				max = -1.0;
				for (j = 0; j < N; ++j){
					tmp = map[b][j][k - 1] * arbitrage[j][i];
					if (tmp > max){
						max = tmp;
						path[b][i][k] = j;
					}
				}
				map[b][i][k] = max;
			}

			if (map[b][b][k] > 1.01){
				for (i = 0, j = b; k > 0; --k)
					stack[i++] = j = (int)path[b][j][k];
				printf("%d ", b + 1);
				while (i--) printf("%d ", stack[i] + 1);
				printf("%d\n", b + 1);
				return 1;
			}
		}
	}

	return 0;
}

int main(){
	int i, j;
	double tmp;

	while (scanf("%d\n", &N) == 1){
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j){
			if (i == j) arbitrage[i][j] = 1.0;
			else{
				scanf("%lf", &tmp);
				arbitrage[i][j] = tmp;
			}
		}

		if (!exist_arbitrage()) printf("no arbitrage sequence exists\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
