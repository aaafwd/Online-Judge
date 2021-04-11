/* @JUDGE_ID: 19899RK 10569 C++ "By Anadan" */
// Number Theory
// Accepted (0.635 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SEED_33 1117686076 // for N = 33
#define SEED_65 1117686185 // for N = 65,76
#define SEED_0 0x56741234u // not good for N = 8,73,97
#define SEED_1 0x12345678u // not good for N = 8,33,65

void solve(int N) {
//fprintf(stderr, "N = %d\n", N);

	if (N == 8) {
		puts(" 1477 1 2 3 4 5 9 187 1476");
		return;
	} else if (N == 97) {
		srand(SEED_1);
	} else if (N == 65 || N == 81) {
		srand(SEED_0);
	} else {
		srand(SEED_0 ^ N);
	}

	int arr[100], i, sum;

	while (1) {
		sum = 0;
		for (i = 0; i < N-1; ++i) {
			arr[i] = i+i+1;
			if (rand() & 1) ++arr[i];
			sum += arr[i] * arr[i] * arr[i];
		}
		while ((sum-1)%3) {
			i = arr[N-2]++;
			sum += 3*i*(i+1) + 1;
		}
		sum += (sum-1)/3;
		i = (int)sqrt(sum);
		if (i*i < sum) ++i;
		if (i*i != sum) continue;
		if (i&1) {
			arr[N-1] = (i-1)/2;
			break;
		}
	}

	printf(" %d", arr[N-1]+1);
	for (i = 0; i < N; ++i) printf(" %d", arr[i]);
	putchar('\n');
}

int main() {
	int set, cs = 0, N;

//**/for (N = 3; N <= 100; ++N) solve(N); return 0;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		printf("Case %d:", ++cs);
		if (N == 1) puts(" 1 1");
		else if (N == 2) puts(" -1 0 0");
		else solve(N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
