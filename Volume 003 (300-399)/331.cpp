/* @JUDGE_ID: 19899RK 331 C++ "By Anadan" */
// Mapping the Swaps
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int nums[5], N, res;

inline void iswap(int &a, int &b) { a ^= b; b ^= a; a ^= b; }

void func(int swaps){
	int i;

	if (swaps == 0){
		++res;
		return;
	}

	for (i = 0; i < N - 1; i++){
		if (nums[i] > nums[i+1]){
			iswap(nums[i], nums[i+1]);
			func(swaps - 1);
			iswap(nums[i], nums[i+1]);
		}
	}
}

int main(){
	int i, j, swaps, set = 0;

	while (scanf("%d", &N) > 0){
		if (N == 0) break;
		for (i = swaps = 0; i < N; i++){
			scanf("%d", nums+i);
			for (j = 0; j < i; j++) if (nums[j] > nums[i]) ++swaps;
		}
		res = 0;
		if (swaps) func(swaps);
		printf("There are %d swap maps for input data set %d.\n", res, ++set);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
