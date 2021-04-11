/* @JUDGE_ID: 19899RK 10394 C++ "By Anadan" */
// Twin Primes
// Accepted (4.662 seconds using as much as 6632 kbytes)
// Too much time !

#include <math.h>
#include <stdio.h>

#define MASKSZ	6000000
#define SZ	100000
#define PR	610

int main(){
	int primes[PR], i, j, k, solves[SZ + 4];
	static char mask[MASKSZ] = {0};

	primes[0] = 2;
	for (i = 1, j = 3; i < PR; j += 2){
		for (k = 0; k < i; ++k){
			if (!(j % primes[k])) break;
		}

		if (k == i) primes[i++] = j;
	}

	// Twin primes: (30k+11,30k+13), (30k+17,30k+19), (30k+29,30k+31)
	for (i = 3; i < PR; ++i){
		for (k = primes[i] * 2; k <= 20000000; k += primes[i]){
			j = k - 11;
			if (!(j % 30)){
				j = j / 5 + 0;
				if (j < MASKSZ) mask[j] = 1;
			}

			j = k - 13;
			if (!(j % 30)){
				j = j / 5 + 1;
				if (j < MASKSZ) mask[j] = 1;
			}

			j = k - 17;
			if (!(j % 30)){
				j = j / 5 + 2;
				if (j < MASKSZ) mask[j] = 1;
			}

			j = k - 19;
			if (!(j % 30)){
				j = j / 5 + 3;
				if (j < MASKSZ) mask[j] = 1;
			}

			j = k - 29;
			if (!(j % 30)){
				j = j / 5 + 4;
				if (j < MASKSZ) mask[j] = 1;
			}

			j = k - 31;
			if (!(j % 30)){
				j = j / 5 + 5;
				if (j < MASKSZ) mask[j] = 1;
			}
		}
	}

	solves[0] = 5;
	solves[1] = 7;
	for (j = 2, i = 0; j < SZ && i < MASKSZ - 1; i += 2){
		if (mask[i] == 0 && mask[i + 1] == 0){
			if (!(i % 6)) solves[j++] = i*5 + 13;
			else if (!((i - 2) % 6)) solves[j++] = (i - 2)*5 + 19;
			else if (!((i - 4) % 6)) solves[j++] = (i - 4)*5 + 31;
		}
	}

	while (scanf("%d", &i) == 1){
		printf("(%d, %d)\n", solves[i - 1] - 2, solves[i - 1]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
