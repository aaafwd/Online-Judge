/* @JUDGE_ID: 19899RK 10125 C++ "By Anadan" */ 
// Sumsets
// Accepted (0.672 seconds using as much as 3604 kbytes)

#include <stdio.h>
#include <stdlib.h>

int sort_function(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

int main(){
	int N, nums[1000], i, j, k, m, p, tot, sums[499500], *ptr, *a, *b;

	while (scanf("%d", &N) == 1 && N){
		p = k = 0;
		while (N--){
			scanf("%d", nums + p);
			for (j = 0; j < p; ++j) if (nums[p] == nums[j]) break;
			if (j == p){
				for (j = 0; j < p; ++j) sums[k++] = nums[p] + nums[j];
				++p;
			}
		}

		tot = p;
		qsort(nums, p, sizeof(int), sort_function);
		qsort(sums, k, sizeof(int), sort_function);
		for (i = p - 1; i > 0; --i){
			for (j = 0; j < i; ++j){
				p = nums[i] - nums[j];
				if ((ptr = (int *)bsearch(&p, sums, k, sizeof(int), sort_function)) != NULL){
					for (a = ptr - 1; a >= sums && *a == *ptr; --a);
					for (b = ptr + 1; b < sums + k && *b == *ptr; ++b);
					m = int(b - a - 1);
					N = -nums[j];
					if (bsearch(&N, nums, tot, sizeof(int), sort_function)) --m;
					N = p - nums[j];
					if (bsearch(&N, nums, tot, sizeof(int), sort_function)) --m;
					if (m > 0) break;
				}
			}

			if (j < i) break;
		}

		if (i > 0) printf("%d\n", nums[i]);
		else printf("no solution\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
