/* @JUDGE_ID: 19899RK 10202 C++ "By Anadan" */
// Pairsumonious Numbers
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

int N, M, sums[36], a[9];
char mask[36];

int sort_function(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

int set(int k){
	int i, j;
	char tmp[36];

	for (i = 0; i < M; ++i) tmp[i] = mask[i];
	for (i = 0; i < k; ++i){
		for (j = 2; j < M; ++j) if (tmp[j] == 0 && sums[j] == a[i] + a[k]) break;
		if (j == M) break;
		tmp[j] = 1;
	}

	if (i < k) return 0;
	for (i = 0; i < M; ++i) mask[i] = tmp[i];
	return 1;
}

void unset(int k){
	int i, j;

	for (i = 0; i < k; ++i){
		for (j = 2; j < M; ++j) if (mask[j] && sums[j] == a[i] + a[k]) break;
		mask[j] = 0;
	}
}

int generate(int k){
	int i;

	if (k == N) return 1;
	for (i = 2; i < M; ++i){
		if (mask[i] || sums[i] - a[0] < a[k - 1]) continue;
		a[k] = sums[i] - a[0];
		if (!set(k)) continue;
		if (generate(k + 1)) return 1;
		unset(k);
	}

	return 0;
}

int solve(){
	int i;

	for (i = 0; i < M; ++i) mask[i] = 0;
	mask[0] = mask[1] = 1;

	for (i = 2; i < N; ++i){
		if ((sums[0] + sums[1] + sums[i]) & 1) continue;
		mask[i] = 1;
		a[0] = (sums[0] + sums[1] - sums[i]) >> 1;
		a[1] = (sums[0] - sums[1] + sums[i]) >> 1;
		a[2] = (-sums[0] + sums[1] + sums[i]) >> 1;
		if (generate(3)) return 1;
		mask[i] = 0;
	}

	return 0;
}

int main(){
	int i;

	while (scanf("%d", &N) == 1){
		M = N * (N - 1) / 2;
		for (i = 0; i < M; ++i) scanf("%d", sums + i);
		qsort(sums, M, sizeof(int), sort_function);
		if (solve()){
			printf("%d", a[0]);
			for (i = 1; i < N; ++i) printf(" %d", a[i]);
			putchar('\n');

		}else puts("Impossible");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
