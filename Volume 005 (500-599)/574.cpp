/* @JUDGE_ID: 19899RK 574 C++ "By Anadan" */
// Sum It Up
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

char solved, flags[12];
int n, nums[13];

void func(int i, int t){
	int j;
	for (; i < n; i++){
		if (t < nums[i]) continue;
		flags[i]++;
		if (t == nums[i]){
			for (j = 0; flags[j] == 0; j++);
			printf("%d", nums[j]);
			for (j++; j < n; j++){
				if (flags[j]) printf("+%d", nums[j]);
			}
			printf("\n");
			solved = 1;
		}else{
			func(i + 1, t - nums[i]);
		}
		flags[i]--;
		while (nums[i] == nums[i + 1]) i++;
	}
}

int main(){
	int i, t;
	nums[12] = -1;

	while (scanf("%d%d", &t, &n) == 2){
		if (n == 0) break;
		for (i = 0; i < n; i++){
			scanf("%d", nums + i);
			flags[i] = 0;
		}
		printf("Sums of %d:\n", t);
		solved = 0;
		func(0, t);
		if (!solved) printf("NONE\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
