/* @JUDGE_ID: 19899RK 497 C++ "By Anadan" */ 
// Strategic Defense Initiative
// Accepted (0.021 seconds with low memory spent)

#include <stdio.h>
#define SZ 8001

int main(){
	static int set, N, i, j, k, nums[SZ], res[SZ], prev[SZ];
	char str[81];

	scanf("%d\n\n", &set);
	while (set--){
		N = 0;
		while (gets(str) && sscanf(str, "%d", nums + N) == 1){
			res[N] = 1; prev[N] = -1;
			for (i = 0; i < N; ++i){
				if (nums[i] < nums[N] && res[N] < res[i] + 1){
					res[N] = res[i] + 1;
					prev[N] = i;
				}
			}
			++N;
		}

		for (i = j = 0; i < N; ++i){
			if (j < res[i]){
				j = res[i];
				k = i;
			}
		}

		printf("Max hits: %d\n", j);
		for (i = 0; j; --j){
			res[i++] = nums[k];
			k = prev[k];
		}

		while (i--) printf("%d\n", res[i]);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
