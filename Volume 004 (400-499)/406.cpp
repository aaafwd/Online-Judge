/* @JUDGE_ID: 19899RK 406 C++ "By Anadan" */
// Prime Cuts
// Accepted (0.380 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int isprime(int N){
	int i, toi = (int)sqrt(N);
	for (i = 3; i <= toi; i += 2) if (!(N % i)) return 0;
	return 1;
}

int main(){
	int primes[170], i, j, N, C;

	primes[0] = 1; primes[1] = 2;
	for (i = 2, N = 3; N < 1010; N += 2){
		if (isprime(N)) primes[i++] = N;
	}

	while (scanf("%d%d", &N, &C) == 2){
		printf("%d %d:", N, C);
		for (i = 0; ; i++) if (primes[i] > N) break;
		j = (i >> 1) - C;
		C <<= 1;
		if (i & 1) { j++; C--; }
		if (j < 0) { j = 0; C = i; }
		while (C--) printf(" %d", primes[j++]);
		printf("\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
