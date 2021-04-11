/* @JUDGE_ID: 19899RK 686 C++ "By Anadan" */
// Goldbach's Conjecture (II)
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	long i, n, res;
	char primes[32768u];

	memset(primes, 0, 32768u); primes[32767] = 1;
	for (n = 2L; n < 16384L; n++){
		if (primes[n]) continue;
		for (i = (n << 1); i < 32767L; i += n){
			primes[i] = 1;
		}
	}

	while (scanf("%ld", &n) > 0){
		if (n == 0) break;
		if (n == 4) res = 1; else res = 0;
		for (i = 3; i <= (n >> 1); i += 2){
			if ((!primes[i]) && (!primes[n-i])) res++;
		}
		printf("%ld\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
