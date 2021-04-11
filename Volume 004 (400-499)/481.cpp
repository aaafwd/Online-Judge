/* @JUDGE_ID: 19899RK 481 C++ "By Anadan" */
// What Goes Up
// Accepted (0.174 seconds using as much as 1552 kbytes)

#include <stdio.h>
#define SZ 100000

int nums[SZ], minindex[SZ], prev[SZ], sp;

int getminindex(int x){
	int i = 0, j = sp - 1, k;

	if (x <= nums[minindex[0]]) return -1;
	if (nums[minindex[sp - 1]] < x) return sp - 1;

	while (i + 1 < j){
		k = (i + j) >> 1;
		if (nums[minindex[k]] >= x) j = k; else i = k;
	}

	for (; i < sp - 1; ++i) if (nums[minindex[i + 1]] >= x) break;
	return i;
}

void output(int x){
	if (prev[x] != x) output(prev[x]);
	printf("%d\n", nums[x]);
}

int main(){
	int i, N;

	scanf("%d", nums);
	minindex[0] = prev[0] = 0;

	for (N = sp = 1; scanf("%d", nums + N) == 1; ++N){
		i = getminindex(nums[N]);
		minindex[++i] = N;
		prev[N] = i ? minindex[i - 1] : N;
		if (i == sp) ++sp;
	}

	printf("%d\n-\n", sp);
	output(minindex[sp - 1]);

	return 0;
}

/* @END_OF_SOURCE_CODE */
