/* @JUDGE_ID: 19899RK 10041 C++ "By Anadan" */
// Vito's family
// Accepted (0.129 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <stdlib.h>

int sort_function(const void *a, const void *b){
	if (*((int *)a) < *((int *)b)) return -1;
	return 1;
}

int main(){
	int set, ptr[500], i, j, N, res;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) scanf("%d", ptr + i);
		qsort(ptr, N, sizeof(int), sort_function);
		j = N >> 1;
		res = 0;
		for (i = 0; i < j; ++i) res += ptr[j] - ptr[i];
		for (i = j + 1; i < N; ++i) res += ptr[i] - ptr[j];
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
