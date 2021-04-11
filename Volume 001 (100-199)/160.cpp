/* @JUDGE_ID: 19899RK 160 C++ "By Anadan" */
// Factors and Factorials
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int primes[25] = {   2,  3,  5,  7, 11,
						13, 17, 19, 23, 29,
						31, 37, 41, 43, 47,
						53, 59, 61, 67, 71,
						73, 79, 83, 89, 97  };
	int solves[101][25];
	int i, j, N;

	for (i = 0; i < 25; i++) solves[0][i] = solves[1][i] = 0;
	for (N = 2; N < 101; N++){
		for (i = 0; i < 25; i++) solves[N][i] = solves[N-1][i];
		for (j = N, i = 0; ((i < 25) && (j >= primes[i])); i++){
			while(!(j % primes[i])){
				j /= primes[i];
				solves[N][i]++;
			}
		}
	}

	while (scanf("%d", &N) > 0){
		if (N == 0) break;
		printf("%3d! =", N);
		for (i = 0; i < 15; i++){
			if (!solves[N][i]) break;
			printf("%3d", solves[N][i]);
		}
		if (solves[N][i]){
			printf("\n      ");
			for (; i < 25; i++){
				if (!solves[N][i]) break;
				printf("%3d", solves[N][i]);
			}
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
