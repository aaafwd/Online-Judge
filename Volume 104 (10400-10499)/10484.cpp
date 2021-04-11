/* @JUDGE_ID: 19899RK 10484 C++ "By Anadan" */ 
// Divisibility of Factors
// Accepted (0.063 seconds with low memory spent)

#include <stdio.h>
int primes[50], powers[50], M;

void setpowers(int N){
	int i, j;

	for (i = 0; i < M; ++i){
		powers[i] = 0;
		if (primes[i] <= N){
			j = N;
			while (j){
				j /= primes[i];
				powers[i] += j;
			}
		}
	}
}

int divide(int D){
	int i;

	for (i = 0; i < M; ++i){
		while (!(D % primes[i])){
			D /= primes[i];
			if (--powers[i] < 0) return 0;
		}
	}

	if (D != 1) return 0;
	return 1;
}

int myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	if (x == EOF) return 0;

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9') x = x * 10 + i - '0';
	return 1;
}

int main(){
	int N, D, i, j;
	long long res;

	primes[0] = 2;
	for (M = 1, i = 3; i < 100; i += 2){
		for (j = 0; j < M; ++j) if (!(i % primes[j])) break;
		if (j == M) primes[M++] = i;
	}

	while (myscanf(N) && myscanf(D) && D){
		setpowers(N);
		if (divide(D)){
			res = 1;
			for (i = 0; i < M; ++i) res *= powers[i] + 1;
			printf("%lld\n", res);

		}else puts("0");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
