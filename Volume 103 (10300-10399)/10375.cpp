/* @JUDGE_ID: 19899RK 10375 C++ "By Anadan" */
// Choose and divide
// Accepted (1.121 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 1230

int primes[SZ], powers[SZ];

void mulfact(int n){
	int i, j, k;

	for (i = 2; i <= n; ++i){
		j = i;
		for (k = 0; primes[k] * primes[k] <= j; ++k){
			if (!(j % primes[k])){
				while (!(j % primes[k])){
					j /= primes[k];
					++powers[k];
				}
			}
		}

		if (j != 1){
			for (k = 0; primes[k] != j; ++k);
			++powers[k];
		}
	}
}

void divfact(int n){
	int i, j, k;

	for (i = 2; i <= n; ++i){
		j = i;
		for (k = 0; primes[k] * primes[k] <= j; ++k){
			if (!(j % primes[k])){
				while (!(j % primes[k])){
					j /= primes[k];
					--powers[k];
				}
			}
		}

		if (j != 1){
			for (k = 0; primes[k] != j; ++k);
			--powers[k];
		}
	}
}

int main(){
	int i, j, k, l;
	double res;

	primes[0] = 2;
	for (i = 1, j = 3; i < SZ; j += 2){
		for (k = 0; k < i; ++k){
			if (!(j % primes[k])) break;
		}

		if (k == i) primes[i++] = j;
	}

	memset(powers, 0, SZ * sizeof(int));
	while (scanf("%d%d%d%d", &i, &j, &k, &l) == 4){
		mulfact(i);
		divfact(j); divfact(i - j);
		divfact(k);
		mulfact(l); mulfact(k - l);
		res = 1.0;
		for (i = 0; i < SZ; ++i){
			while (powers[i] > 0){
				res *= primes[i];
				--powers[i];
			}

			while (powers[i] < 0){
				res /= primes[i];
				++powers[i];
			}
		}

		printf("%.5lf\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
