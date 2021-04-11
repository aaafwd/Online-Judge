/* @JUDGE_ID: 19899RK 10611 C++ "By Anadan" */
// The Playboy Chimp
// Accepted (0.164 seconds using as much as 588 kbytes)

#include <stdio.h>

int N, arr[50000];

int bsearchLess(int x) {
	int i = 0, j = N - 1, k;
	while (i < j - 1) {
		k = (i + j) >> 1;
		if (arr[k] >= x) j = k; else i = k;
	}
	while (j >= 0 && arr[j] >= x) --j;
	return j;
}

int bsearchMore(int x) {
	int i = 0, j = N - 1, k;
	while (i < j - 1) {
		k = (i + j) >> 1;
		if (arr[k] <= x) i = k; else j = k;
	}
	while (i < N && arr[i] <= x) ++i;
	return i;
}

int main() {
	int i, j, k, Q;

	scanf("%d", &N);
	for (i = 0; i < N; ++i) scanf("%d", arr+i);
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d", &k);
		i = bsearchLess(k);
		j = bsearchMore(k);
		if (i < 0) printf("X "); else printf("%d ", arr[i]);
		if (j >= N) printf("X\n"); else printf("%d\n", arr[j]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
