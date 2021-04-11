/* @JUDGE_ID: 19899RK 10586 C++ "By Anadan" */
// Polynomial Remains
// Accepted (0.078 seconds with low memory spent)

#include <stdio.h>

int main() {
	int arr[10010], i, k, N;

	while (scanf("%d%d", &N, &k) == 2 && N >= 0) {
		for (i = 0; i <= N; ++i) scanf("%d", arr+i);
		for (i = N; i >= k; --i) {
			arr[i-k] -= arr[i];
			arr[i] = 0;
		}
		if (--k > N) k = N;
		for (; k >= 0; --k) if (arr[k]) break;

		if (k < 0) puts("0");
		else {
			printf("%d", arr[0]);
			for (i = 1; i <= k; ++i) printf(" %d", arr[i]);
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
