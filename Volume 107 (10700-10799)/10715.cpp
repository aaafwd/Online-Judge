/* @JUDGE_ID: 19899RK 10715 C++ "By Anadan" */
// Cat
// Accepted (0.037 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N;
struct Number {
	double x;
	int i;
} arr[128];
double sum, res;
char mask[128];

int sort_function(const void *a, const void *b) {
	if (((Number*)a)->x > ((Number*)b)->x) return -1;
	return 1;
}

inline int isGood(double curr) {
	if (fabs(sum-curr-curr) <= 0.02 * curr) {
		return 1;
	}
	return 0;
}

int localSearch(double curr) {
	int i, j;
	double tmp;

	for (i = N-1; i >= 0; --i) if (!mask[i]) break;
	for (j = 0; j < N; ++j) {
		if (mask[j]) {
			tmp = curr - arr[j].x + arr[i].x;
			if (isGood(tmp)) {
				mask[j] = 0;
				mask[i] = 1;
				return 1;
			}
		}
	}
	return 0;
}

int generate(int i, double curr) {
	double tmp;
	if (isGood(curr)) return 1;

	if (i >= N) return 0;
	tmp = curr + (N-i)*arr[N-1].x;
	if (tmp < curr-tmp && !isGood(tmp)) return 0;

	if ((curr)*2 > sum+1e-12) {
//	if ((curr + arr[N-1].x)*2 > sum+1e-12) {
		if (localSearch(curr)) return 1;
		return 0;
	}

	if (i == 0) {
		mask[i] = 1;
		return generate(i+1, curr+arr[i].x);
	}

	if (rand() & 1) {
		if (generate(i+1, curr)) return 1;

		mask[i] = 1;
		if (generate(i+1, curr+arr[i].x)) return 1;
	} else {
		mask[i] = 1;
		if (generate(i+1, curr+arr[i].x)) return 1;

		mask[i] = 0;
		if (generate(i+1, curr)) return 1;
	}

	mask[i] = 0;
	return 0;
}

int main() {
	int i;

	while (scanf("%d", &N) == 1 && N) {
		// Accepted (0.281 seconds using as much as 392 kbytes)
		// srand(321);

		// Accepted (0.037 seconds with low memory spent)
		srand(2003);

		sum = 0;
		for (i = 0; i < N; ++i) {
			scanf("%lf", &arr[i].x);
			arr[i].i = i;
			sum += arr[i].x;
		}
		qsort(arr, N, sizeof(arr[0]), sort_function);

		res = -1;
		memset(mask, 0, sizeof(mask));
		generate(0, 0);

		int out = 0;
		for (i = 0; i < N; ++i) {
			if (mask[i]) {
				if (out) putchar(' ');
				printf("%d", arr[i].i + 1);
				out = 1;
			}
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
