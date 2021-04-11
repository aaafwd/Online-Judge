/* @JUDGE_ID: 19899RK 10370 C++ "By Anadan" */
// Above Average
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, i, N, arr[1000], sum, k;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (sum = i = 0; i < N; ++i){
			scanf("%d", arr + i);
			sum += arr[i];
		}

		for (k = i = 0; i < N; ++i) if (arr[i]*N > sum) ++k;
		printf("%.3lf%%\n", double(k) / N * 100.0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
