/* @JUDGE_ID: 19899RK 529 C++ "By Anadan" */ 
// Addition Chains
// Accepted (0.047 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 10001

int low[SZ], cur[SZ], N, best, a[SZ], mask[SZ], count;

void generate(int n){
	int i, j, k = ++count;

	if (n + low[cur[n]] >= best) return;
	if (cur[n] == N){
		for (i = 0; i <= n; ++i) a[i] = cur[i];
		best = n;
		return;
	}

	for (i = n; i >= 0; --i){
		for (j = n; j >= i; --j){
			cur[n + 1] = cur[i] + cur[j];

			if (cur[n] < cur[n + 1] && cur[n + 1] <= N){
				if (mask[cur[n + 1]] != k){
					mask[cur[n + 1]] = k;
					generate(n + 1);
				}
			}
		}
	}
}

int main(){
	int i, j;

	cur[0] = 1;
	while (scanf("%d\n", &N) == 1 && N){
		low[N] = mask[N] = count = 0;
		for (i = N - 1; i > 0; --i){
			low[i] = 1;
			j = i + i;
			if (j < N) low[i] += low[j];
			mask[i] = -1;
		}

		best = SZ;
		generate(0);
		
		printf("1");
		for (i = 1; i <= best; ++i) printf(" %d", a[i]);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
