/* @JUDGE_ID: 19899RK 10570 C++ "By Anadan" */
// Meeting with Aliens
// Accepted (0.672 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

int arr[500], N, min;
char mask[500];

int getex(int off){
	int i, j, k, res = 0;

	memset(mask, 0, N);
	for (i = 0; i < N; ++i){
		if (mask[i]) continue;
		mask[i] = 1;

		j = arr[i] - 1;
		while (1){
			k = off + j;
			if (k >= N) k -= N;
			if (mask[k]) break;
			mask[k] = 1;
			if (++res >= min) return min;
			j = arr[k] - 1;
		}
	}

	return res;
}

int main(){
	int i, j;

	while (scanf("%d", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%d", arr + i);

		min = 30000;
		min = getex(0);
		for (i = 1; i < N; ++i){
			j = getex(i);
			if (min > j) min = j;
		}

		for (i = 0, j = N - 1; i < j; arr[i++] ^= arr[j--] ^= arr[i] ^= arr[j]);
		for (i = 0; i < N; ++i){
			j = getex(i);
			if (min > j) min = j;
		}

		printf("%d\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
