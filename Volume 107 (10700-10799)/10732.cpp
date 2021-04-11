/* @JUDGE_ID: 19899RK 10732 C++ "By Anadan" */
// Strange Project
// Accepted (0.344 seconds using as much as 556 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
double arr[10000];
const double eps = 1e-15;

inline double f(double a, double b) { return (a+b) * (1-a*b); }

int sort_function(const void *a, const void *b) {
	if (*(double*)a < *(double*)b) return -1;
	return 1;
}

int findgt(double x, double b) {
	int i = 0, j = N - 1, k;

	while (i + 1 < j) {
		k = (i + j) >> 1;

		if (arr[k] >= x + 1) j = k;
		else if (arr[k] <= x) i = k;
		else if (f(arr[k], b) > eps) j = k;
		else i = k;
	}
	for (; i < N; ++i) if (arr[i] >= x && f(arr[i], b) > eps) break;
	return i;
}

int findls(double x, double b) {
	int i = 0, j = N - 1, k;

	while (i + 1 < j) {
		k = (i + j) >> 1;

		if (arr[k] <= x - 1) i = k;
		else if (arr[k] >= x) j = k;
		else if (f(arr[k], b) > eps) i = k;
		else j = k;
	}
	for (; j >= 0; --j) if (arr[j] <= x && f(arr[j], b) > eps) break;
	return j;
}

int main() {
	int set = 0, i, j, k, res;

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; ++i) scanf("%lf", arr+i);
		qsort(arr, N, sizeof(double), sort_function);

		res = 0;
		for (i = 0; i < N; ++i) {
			if (fabs(arr[i]) < eps) {
				j = findgt(0, arr[i]);
				res += N - j;
			} else if (arr[i] > 0) {
				j = findgt(-arr[i], arr[i]);
				k = findls(1/arr[i], arr[i]);
				if (j <= k) res += k - j + 1;
			} else {
				j = findls(1/arr[i], arr[i]);
				k = findgt(-arr[i], arr[i]);
				res += N-k + j+1;

			}
			if (f(arr[i], arr[i]) > eps) --res;
		}

		printf("Case %d: %d\n", ++set, res/2);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
