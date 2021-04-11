/* @JUDGE_ID: 19899RK 10880 C++ "By Anadan" */
// Colin and Ryan
// Accepted (0.164 seconds using as much as 412 kbytes)

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int primes[32], powers[32], sp;
int factors[1024], size;

void factorize(int N) {
	int i, toi;

	sp = 0;
	if (!(N & 1)) {
		primes[0] = 2;
		powers[0] = 0;
		while (!(N & 1)) {
			N >>= 1;
			++powers[0];
		}
		++sp;
	}

	toi = (int)sqrt(N);
	for (i = 3; i <= toi; i += 2) {
		if (!(N % i)) {
			primes[sp] = i;
			powers[sp] = 0;
			while (!(N % i)) {
				N /= i;
				++powers[sp];
			}
			++sp;
			if (i > N) break;
		}
	}
	if (N != 1) {
		primes[sp] = N;
		powers[sp] = 1;
		++sp;
	}
}

void generate(int i, int curr) {
	int j;

	if (i >= sp) {
		factors[size++] = curr;
		return;
	}
	generate(i+1, curr);
	for (j = 0; j < powers[i]; ++j) {
		curr *= primes[i];
		generate(i+1, curr);
	}
}

int sort_function(const void *a, const void *b) {
	if (*(int*)a < *(int*)b) return -1;
	return 1;
}

int main() {
	int set, cs = 0, C, R, i;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &C, &R);
		C -= R;

		printf("Case #%d:", ++cs);
		if (C == 0) puts(" 0");
		else {
			factorize(C);
			size = 0;
			generate(0, 1);
			qsort(factors, size, sizeof(int), sort_function);
			for (i = 0; i < size; ++i) {
				if (factors[i] > R) printf(" %d", factors[i]);
			}
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
