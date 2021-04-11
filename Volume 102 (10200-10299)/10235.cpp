/* @JUDGE_ID: 19899RK 10235 C++ "By Anadan" */
// Simply Emirp
// Accepted (0.050 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int isprime(long N){
	long i, toi;
	if (N == 2L) return 1;
	if (!(N & 1L)) return 0;
	toi = (long)sqrt(N);
	for (i = 3L; i <= toi; i += 2L) if (!(N % i)) return 0;
	return 1;
}

long reverse(long N){
	long res = 0L;

	while (N){
		res *= 10;
		res += N % 10;
		N /= 10;
	}
	return res;
}

int main(){
	long N, R;

	while (scanf("%ld", &N) > 0){
		if (isprime(N)){
			R = reverse(N);
			if (R != N && isprime(R)) printf("%ld is emirp.\n", N);
			else printf("%ld is prime.\n", N);
		}else printf("%ld is not prime.\n", N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
