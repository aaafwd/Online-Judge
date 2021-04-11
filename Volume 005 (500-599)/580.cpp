/* @JUDGE_ID: 19899RK 580 C++ "By Anadan" */
// Critical Mass
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int main(){
	int solves[31], i, j;

	solves[0] = solves[1] = solves[2] = 0;
	solves[3] = 1; solves[4] = 3;
	for (i = 5, j = 8; i < 31; ++i, j <<= 1){
		solves[i] = solves[i - 3] * 4 + solves[i - 4] * 3 + solves[i - 5] * 2 + j;
	}

	while (scanf("%d\n", &j) == 1 && j){
		printf("%d\n", solves[j]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
