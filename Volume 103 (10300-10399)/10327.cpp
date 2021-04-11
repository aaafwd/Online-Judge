/* @JUDGE_ID: 19899RK 10327 C++ "By Anadan" */
// Flip Sort
// Accepted (0.340 seconds using as much as 392 kbytes)

#include <stdio.h>

int main(){
	int i, j, N, nums[1000], res;

	while (scanf("%d", &N) == 1){
		res = 0;
		for (i = 0; i < N; ++i) scanf("%d", nums + i);
		for (i = 0; i < N; ++i) for (j = i + 1; j < N; ++j){
			if (nums[i] > nums[j]) ++res;
		}
		printf("Minimum exchange operations : %d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
