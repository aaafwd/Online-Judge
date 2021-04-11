/* @JUDGE_ID: 19899RK 10140 C++ "By Anadan" */
// Prime Distance
// Accepted (0.213 seconds using as much as 1388 kbytes)

#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 4793
#define MAXDIFF 1000001

int index, primes[SIZE];
char mask[MAXDIFF];

void fillmask(int a, int b){
	int i, j;

	memset(mask, 0, b - a + 1);
	for (i = 0; i < index; ++i){
		j = (a / primes[i]) * primes[i];
		if (j == 0) j = primes[i] + primes[i];
		else if (j < a || j == primes[i]) j += primes[i];
		for (; a <= j && j <= b; j += primes[i]) mask[j - a] = 1;
	}
}

int main(){
	int L, U, C1, C2, D1, D2, last, cur, j, n, sqrt_n;

	primes[0] = 2;
	for (index = 1, n = 3; index < SIZE; n += 2){
		sqrt_n = (int)sqrt(n);
		for (j = 0; j < index && primes[j] <= sqrt_n; j++){
			if (!(n % primes[j])) goto next_n;
		}
		primes[index++] = n;
		next_n: continue;
	}

	while (scanf("%d%d", &L, &U) == 2){
		if (L < 2) L = 2;
		fillmask(L, U);
		--L; --U;
		for (C1 = L; C1 <= U; ++C1) if (mask[C1 - L] == 0) break;
		for (C2 = C1 + 1; C2 <= U; ++C2) if (mask[C2 - L] == 0) break;
		if (C2 > U) printf("There are no adjacent primes.\n");
		else{
			D1 = C1; last = D2 = C2;
			for (cur = last + 1; cur <= U; ++cur){
				if (mask[cur - L] == 0){
					if (cur - last < C2 - C1) C1 = last, C2 = cur;
					if (cur - last > D2 - D1) D1 = last, D2 = cur;
					last = cur;
				}
			}

			printf("%d,%d are closest, %d,%d are most distant.\n", C1 + 1, C2 + 1, D1 + 1, D2 + 1);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
