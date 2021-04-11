/* @JUDGE_ID: 19899RK 369 C++ "By Anadan" */
// Combinations
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

int C(int n, int k){
	int i, j, ptr[100];

	if (k > n - k) k = n - k;	// C(n, k) = C(n, n - k)
	if (k == 0) return 1;

	for (j = 0; j < k; j++) ptr[j] = j + 2;
	for (i = 0; i < n - k - 1; i++){
		++ptr[0];
		for (j = 1; j < k; j++)	ptr[j] += ptr[j - 1];
	}

	return ptr[k - 1];
}

int main(){
	int n, k;

	while (scanf("%d%d", &n, &k) == 2){
		if ((n == 0) && (k == 0)) break;
		printf("%d things taken %d at a time is %d exactly.\n", n, k, C(n, k));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
