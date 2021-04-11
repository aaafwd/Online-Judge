/* @JUDGE_ID: 19899RK 10565 C++ "By Anadan" */
// Matrix
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int main() {
	int set, arr[32], i, N;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i){
			scanf("%d", arr+i);
			if (arr[i]) arr[0] = arr[i];
		}
		if (arr[0]) {
			printf("2\n");
			printf("%d 0\n", -arr[0]);
			printf("0 %d\n", -arr[0]);
		} else {
			puts("-1");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
