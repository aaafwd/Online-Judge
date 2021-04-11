/* @JUDGE_ID: 19899RK 10407 C++ "By Anadan" */
// Simple division
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int gcd(int a, int b){
	while (a && b) if (a > b) a %= b; else b %= a;
	if (a) return a; else return b;
}

int main(){
	int nums[1001], N, i, res, min;

	while (scanf("%d", nums) == 1 && nums[0]){
		N = 1;
		min = nums[0];
		while (scanf("%d", nums + N) && nums[N]){
			if (min > nums[N]) min = nums[N];
			++N;
		}

		for (i = 0; i < N; ++i) nums[i] -= min;

		for (res = nums[0], i = 1; i < N; ++i){
			res = gcd(res, nums[i]);
		}

		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
