/* @JUDGE_ID: 19899RK 10650 C++ "By Anadan" */
// Determinate Prime
// Accepted (0.029 seconds with low memory spent)

#include <stdio.h>

int primes[4000], N;
int begin[200], count[200], d[200], sp;

void precalc(){
	int i, j, currcount, currd;

	sp = 0;
	for (i = 0; i < N - 2; ++i){
		currcount = 2;
		currd = primes[i + 1] - primes[i];
		for (j = i + 2; j < N; ++j){
			if (primes[j] - primes[j - 1] != currd) break;
			++currcount;
		}

		if (currcount > 2){
			begin[sp] = primes[i];
			count[sp] = currcount;
			d[sp++] = currd;
		}

		i = j - 2;
	}
}

int getbs(int x){
	int i = 0, j = sp - 1, k;

	while (i + 1 < j){
		k = (i + j) >> 1;
		if (begin[k] > x) j = k; else i = k;
	}

	while (i <= j && begin[j] >= x) --j;
	return j + 1;
}

void outprint(int x){
	int i;

	printf("%d", begin[x]);
	for (i = 1; i < count[x]; ++i){
		printf(" %d", begin[x] + i * d[x]);
	}
	putchar('\n');
}

int main(){
	int i, j, k, tmp;

	primes[0] = 2;
	for (N = 1, i = 3; N < 4000 && i < 32768; i += 2){
		for (j = 0; primes[j] * primes[j] <= i; ++j) if (!(i % primes[j])) break;
		if (primes[j] * primes[j] > i) primes[N++] = i;
	}

	precalc();

	while (scanf("%d%d", &i, &j) == 2 && (i || j)){
		if (i > j) i ^= j ^= i ^= j;
		k = getbs(i);
		while (k < sp && begin[k] < j){
			if (begin[k] >= i){
				tmp = begin[k] + d[k] * (count[k] - 1);
				if (tmp <= j) outprint(k);
			}
			++k;
		}
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
