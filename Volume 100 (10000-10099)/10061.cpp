/* @JUDGE_ID: 19899RK 10061 C++ "By Anadan" */
// How many zeros and how many digits?
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

double log_factorial(double N){
	const double pi2 = acos(0.0) * 4.0;

	if (N < 40.0){
		int i;
		double f;

		for (i = 1, f = 1.0; i <= (int)N; ++i) f *= i;
		return log(f);
	}else{
		return log(pi2) * 0.5 + ((N + 0.5) * (log(N * N + N + 1.0 / 6.0) * 0.5 - 1.0));
	}
}

int simplify(long N, long *primes, long *powers){
	int index;
	long i, toi;

	if (!(N & 1L)){
		primes[0] = 2L;
		powers[0] = 0L;
		while (!(N & 1L)){
			N >>= 1;
			++powers[0];
		}
		index = 1;
	}else index = 0;

	for (i = 3L, toi = (long)sqrt(N); i <= toi; i += 2L){
		if (!(N % i)){
			primes[index] = i;
			powers[index] = 0L;
			while (!(N % i)){
				N /= i;
				++powers[index];
			}
			++index;
			toi = (long)sqrt(N);
		}
	}

	if (N > 1){
		primes[index] = N;
		powers[index++] = 1L;
	}

	return index;
}

int main(){
	int i, index;
	double d;
	long primes[10], powers[10], tot_pows[10], N, B, tmp, zeros;

	while (scanf("%ld%ld", &N, &B) == 2){
		index = simplify(B, primes, powers);

		for (i = 0; i < index; i++){
			tmp = N;
			tot_pows[i] = 0L;
			while (tmp){
				tmp /= primes[i];
				tot_pows[i] += tmp;
			}
		}

		zeros = tot_pows[0] / powers[0];
		for (i = 1; i < index; i++){
			tmp = tot_pows[i] / powers[i];
			if (tmp < zeros) zeros = tmp;
		}

		d = log_factorial(N) / log(B);
		printf("%ld %.0lf\n", zeros, floor(d) + 1.0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
