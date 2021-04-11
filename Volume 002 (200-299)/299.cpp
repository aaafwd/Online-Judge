/* @JUDGE_ID: 19899RK 299 C++ "By Anadan" */
// Train Swapping
// Accepted (0.010 seconds using as much as 392 kbytes)

#include <stdio.h>

int main(){
	int i, j, L, res, ptr[50];
	unsigned long ni, N;
	scanf("%lu", &N);

	for (ni = 0L; ni < N; ni++){
		scanf("%d", &L);
		for (i = 0; i < L; i++) scanf("%d", &ptr[i]);
		for (res = 0, i = 1; i <= L; i++){
			for (j = 0; j < L; j++){
				if (ptr[j] == i) break;
				if (ptr[j] > i) res++;
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
