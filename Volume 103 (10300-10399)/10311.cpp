/* @JUDGE_ID: 19899RK 10311 C++ "By Anadan" */ 
// Goldbach and Euler
// Accepted (6.873 seconds using as much as 392 kbytes)

#include <stdio.h>
#define SZ 1750

int main(){
	int i, j, k, N, primes[SZ];

	for (N = 0, i = 3; N < SZ; i += 2){
		for (j = 1; j < N && primes[j] * primes[j] <= i; ++j){
			if (!(i % primes[j])){
				j = 0;
				break;
			}
		}

		if (j) primes[N++] = i;
	}

	while (scanf("%d\n", &N) == 1){
		if (N <= 4 || N == 6) printf("%d is not the sum of two primes!\n", N);
		else if (N & 1){
			N -= 2;
			for (i = 0; primes[i] * primes[i] <= N; ++i) if (!(N % primes[i])) { i = -1; break; }
			if (i >= 0) printf("%d is the sum of 2 and %d.\n", N + 2, N);
			else printf("%d is not the sum of two primes!\n", N + 2);
		}else{
			j = (N >> 1) - 1;
			if (!(j & 1)) --j;
			while (1){
				k = N - j;
				for (i = 0; primes[i] * primes[i] <= j; ++i){
					if (!(k % primes[i]) || !(j % primes[i])) { i = -1; break; }
				}
				if (i != -1){
					for (; primes[i] * primes[i] <= k; ++i){
						if (!(k % primes[i])) { i = -1; break; }
					}
					if (i >= 0) break;
				}
				j -= 2;
			}

			printf("%d is the sum of %d and %d.\n", N, j, k);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
