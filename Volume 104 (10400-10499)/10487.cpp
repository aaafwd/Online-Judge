/* @JUDGE_ID: 19899RK 10487 C++ "By Anadan" */ 
// Closest Sums
// Accepted (1.318 seconds using as much as 4308 kbytes)

#include <stdio.h>
#include <stdlib.h>

int sums[500000], M;

int sort_function(const void *a, const void *b){
	if (*(int *)a < *(int *)b) return -1;
	return 1;
}

int getclosestsum(int x){
	int i = 0, j = M - 1, k;

	while (j > i + 1){
		k = (i + j) >> 1;
		if (sums[k] > x) j = k; else i = k;
	}

	if (x <= sums[i]) return sums[i];
	else if (x >= sums[j]) return sums[j];

	if (x - sums[i] < sums[j] - x) return sums[i];
	return sums[j];
}

int main(){
	int N, i, j, set = 0;
	int arr[1000], k, m;

	while (scanf("%d", &N) == 1 && N){
		M = 0;
		for (i = 0; i < N; ++i){
			scanf("%d", arr + i);
			for (j = 0; j < i; ++j){
				sums[M++] = arr[i] + arr[j];
			}
		}

		qsort(sums, M, sizeof(int), sort_function);

		scanf("%d", &N);
		printf("Case %d:\n", ++set);
		while (N--){
			scanf("%d", &k);
			m = getclosestsum(k);
			printf("Closest sum to %d is %d.\n", k, m);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
