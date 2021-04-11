/* @JUDGE_ID: 19899RK 326 C++ "By Anadan" */
// Extrapolation Using a Difference Table
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, j, n;
	long nums[10], arr[10], k;

	while (scanf("%d", &n) > 0){
		if (n == 0) break;
		for (i = 0; i < n; i++){
			scanf("%ld", &nums[i]);
			arr[n-1-i] = nums[i];
		}
		scanf("%ld", &k);
		printf("Term %ld of the sequence is ", k + (long)n);

		if (n == 1){
			printf("%ld\n", nums[0]);
			continue;
		}

		for (i = 0; i < n-1; i++){
			for (j = 0; j < n-1-i; j++) arr[j] -= arr[j+1];
			nums[n-2-i] = arr[0];
		}
		while(k--){
			for (i = 1; i < n; i++) nums[i] += nums[i-1];
		}
		printf("%ld\n", nums[n-1]);

	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
