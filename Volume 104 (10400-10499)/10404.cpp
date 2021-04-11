/* @JUDGE_ID: 19899RK 10404 C++ "By Anadan" */
// Bachet's Game
// Accepted (3.574 seconds using as much as 1364 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SZ 1000001

int sort_function(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

int main(){
	int i, j, k, N, M, nums[10];
	char mask[SZ];

	while (scanf("%d%d", &M, &N) == 2){
		for (i = 0; i < N; ++i) scanf("%d", nums + i);
		qsort(nums, N, sizeof(int), sort_function);

		mask[0] = 0;
		j = i = 1;
		while (i <= M){
			if (j < N && i >= nums[j]) ++j;
			for (k = 0; k < j; ++k){
				if (mask[i - nums[k]] == 0) break;
			}
			if (k < j) mask[i] = 1;
			else mask[i] = 0;
			++i;
		}

		if (mask[M]) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
