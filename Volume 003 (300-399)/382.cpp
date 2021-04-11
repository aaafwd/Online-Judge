/* @JUDGE_ID: 19899RK 382 C++ "By Anadan" */ 
// Perfection
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

void isPerfect(long N){
	long sum = 1L, i, toi = sqrt(N);

	if (toi * toi == N) sum -= toi;
	for (i = 2L; i <= toi; i++){
		if (!(N % i)){
			sum += i + N / i;
			if (sum > N) break;
		}
	}
	if (sum > N) printf("ABUNDANT\n");
	else if (sum < N) printf("DEFICIENT\n");
	else printf("PERFECT\n");
}

int main(){
	long N;
	printf("PERFECTION OUTPUT\n");
	while (scanf("%ld", &N) > 0){
		if (N == 0L) break;
		printf("%5ld  ", N);
		isPerfect(N);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
/* @END_OF_SOURCE_CODE */
