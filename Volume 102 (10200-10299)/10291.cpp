/* @JUDGE_ID: 19899RK 10291 C++ "By Anadan" */
// Cut the Legs
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N;
char mask[50];

int solution() {
	int i, j, k, half = (N+1)/2;

	for (i = 0; i < N; ++i) if (mask[i]) break;
	if (i >= N) return 0;

	for (j = i + 1; j < N; ++j) if (mask[j]) break;
	if (j >= N || j >= i + half) return 0;

	for (k = j + 1; k < N; ++k) if (mask[k]) break;
	if (k >= N || k >= j + half) return 0;

	for (j = k++; k < N; ++k) {
		if (!mask[k]) continue;
		if (k >= j + half) return 0;
		j = k;
	}
	if (i + N >= j + half) return 0;

	return 1;
}

int main() {
	int arr[50], i = -1, j, res, sum;

	while (scanf("%d", &N) == 1 && N) {
		if (i != -1) putchar('\n');
		for (i = 0; i < N; ++i) scanf("%d", arr+i);
		res = 0x7FFFFFFF;
		for (i = 0; i < N; ++i) {
			sum = 0;
			memset(mask, 0, sizeof(mask));
			for (j = 0; j < N; ++j) {
				if (arr[j] >= arr[i]) {
					sum += arr[j] - arr[i];
					mask[j] = 1;
				}
			}
			if (res > sum && solution()) res = sum;
		}
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
