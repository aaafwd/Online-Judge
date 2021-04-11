/* @JUDGE_ID: 19899RK 10168 C++ "By Anadan" */ 
// Summation of Four Primes
// Accepted (0.031 seconds with low memory spent)

#include <stdio.h>
#define SZ 57

const int primes[SZ] = {
	9992777, 9955949, 9750001, 9500021, 9250009, 8999993, 8750011, 8500007,
	8250013, 7999993, 7750003, 7500013, 7250011, 6999989, 6750001, 6500003,
	6250009, 5999993, 5750057, 5500003, 5250029, 4999963, 4750001, 4500007,
	4250021, 3999971, 3750001, 3500017, 3250021, 2999957, 2750021, 2500009,
	2250013, 1999993, 1750009, 1500007, 1250003, 999983,  899981,  799993,
	699967,  599993,  499979,  399989,  299993,  199967,  99991,   89989,
	79987,   69991,   59981,   49993,   39989,   29989,   19993,   9973, 8971
};

int main(){
	int i, j, k, m, N;

	while (1){
		while ((N = getchar()) != EOF && (N < '0' || N > '9'));
		if (N == EOF) break;
		N -= '0';
		while ((j = getchar()) != EOF && '0' <= j && j <= '9') N = N * 10 + j - '0';

		if (N < 8) printf("Impossible.\n");
		else if (N < 10) printf("2 2 2 %d\n", N - 6);
		else{
			if (N & 1){
				for (i = 0; i < SZ; ++i){
					if (N >= primes[i] + 6){
						printf("2 %d", primes[i]);
						N -= primes[i] + 2;
						break;
					}
				}

				if (i == SZ){
					printf("2 3");
					N -= 5;
				}
			}else{
				for (i = 0; i < SZ; ++i){
					if (N >= primes[i] + 7){
						printf("3 %d", primes[i]);
						N -= primes[i] + 3;
						break;
					}
				}

				if (i == SZ){
					printf("3 3");
					N -= 6;
				}
			}

			if (N == 4) { printf(" 2 2\n"); continue; }

			for (i = 3; i + i <= N; i += 2){
				j = N - i;
				for (k = 3; k * k <= i; k += 2){
					if (!(i % k) || !(j % k)) { k = 0; break; }
				}
				if (!k) continue;

				for (; k * k <= j; k += 2){
					if (!(j % k)) { k = 0; break; }
				}
				if (!k) continue;

				printf(" %d %d\n", i, j);
				break;
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
