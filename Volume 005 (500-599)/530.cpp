/* @JUDGE_ID: 19899RK 530 C++ "By Anadan" */
// Binomial Showdown
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

long C(long n, long k){
	register long *ptr, res;
	long i, j;

	if (n < 0) return (long)-1;
	if ( (k < 0) || (k > n) ) return (long)-1;
	if (k > n - k) k = n - k;	// C(n, k) = C(n, n - k)
	if (k == 0) return (long)1;	// C(n, 0) = C(n, n) = 1
	if (k == 1) return n;

	// needed ( k * sizeof(long) ) baits of memory
	ptr = (long *)malloc(k * sizeof(long));
	if (ptr == NULL) return (long)-1;

	for (j = 0; j < k; j++)	ptr[j] = j + 2;

	for (i = 0; i < n - k - 1; i++){
		ptr[0]++;
		for (j = 1; j < k; j++)	ptr[j] += ptr[j - 1];
	}

	res = ptr[k - 1];
	free(ptr);
	return res;
}

int main(){
	long n, k;
	while (scanf("%ld%ld", &n, &k) == 2){
		if (n == 0 && k == 0) break;
		printf("%ld\n", C(n, k));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
