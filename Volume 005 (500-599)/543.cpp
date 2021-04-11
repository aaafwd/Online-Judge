/* @JUDGE_ID: 19899RK 543 C++ "By Anadan" */ 
// Goldbach's Conjecture
// Accepted (1.050 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int prime(long n){
	long i, toi = sqrt(n);
	for (i = 3L; i <= toi; i++){
		if (!(n % i)) return 0;
	}
	return 1;
}

void func(long N){
	long i, toi = (N >> 1);

	for (i = 3L; i <= toi; i += 2L){
		if (prime(i)){
			if (prime(N - i)){
				printf("%ld = %ld + %ld\n", N, i, N - i);
				return;
			}
		}
	}
	printf("Goldbach's conjecture is wrong.\n");
}

int main(){
	long N;

	while (scanf("%ld", &N) > 0){
		if (N == 0L) break;
		func(N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
