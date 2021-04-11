/* @JUDGE_ID: 19899RK 10493 C++ "By Anadan" */ 
// Cats, with or without Hats
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>

int main(){
	int N, M;

	while (scanf("%d%d", &N, &M) == 2 && N){
		printf("%d %d ", N, M);
		if (N == 1) puts(M == 1 ? "Multiple" : "Impossible");
		else{
			if ((M - 1) % (N - 1)) puts("Impossible");
			else printf("%d\n", 1 + (M - 1) / (N - 1) * N);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
