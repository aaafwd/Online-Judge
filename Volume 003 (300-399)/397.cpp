/* @JUDGE_ID: 19899RK 397 C++ "By Anadan" */
// Equation Elation
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int nums[22], N = 0;
char ops[22], varname[10];

void outprint(){
	int i;
	for (i = 0; i < N; ++i) printf("%d %c ", nums[i], ops[i]);
	printf("%s\n", varname);
}

int main(){
	int i;

	while (1){
		if (N) putchar('\n');

		N = 0;
		while (scanf("%d%1s", nums + N, ops + N) == 2 && ops[N++] != '=');
		if (N == 0) break;
		scanf("%s\n", varname);

		outprint();
		for (i = 0; i < N - 1; ++i){
			if (ops[i] == '*' || ops[i] == '/'){
				if (ops[i] == '*') nums[i] *= nums[i + 1];
				else nums[i] /= nums[i + 1];
				memcpy(nums + i + 1, nums + i + 2, sizeof(int) * (N - i - 2));
				memcpy(ops + i, ops + i + 1, N - i - 1);
				--N; --i;
				outprint();
			}
		}

		for (i = 0; i < N - 1; ++i){
			if (ops[i] == '+') nums[i] += nums[i + 1];
			else nums[i] -= nums[i + 1];
			memcpy(nums + i + 1, nums + i + 2, sizeof(int) * (N - i - 2));
			memcpy(ops + i, ops + i + 1, N - i - 1);
			--N; --i;
			outprint();
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
