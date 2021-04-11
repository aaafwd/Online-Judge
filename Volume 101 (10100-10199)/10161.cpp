/* @JUDGE_ID: 19899RK 10161 C++ "By Anadan" */ 
// Ant on a Chessboard
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main(){
	int N, k, n, b;

	while (scanf("%d\n", &N) == 1 && N){
		n = int(sqrt((N - 1) * 0.25));
		k = n + n + 1;
		b = n * n * 4 + 1;

		if (N < b + k) printf("%d %d\n", k, N - b + 1);
		else if (N < b + 2*k - 1) printf("%d %d\n", b + 2*k - 1 - N, k);
		else if (N < b + 2*k + k) printf("%d %d\n", N - b - 2*k + 2, k + 1);
		else printf("%d %d\n", k + 1, b + 4*k - N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
