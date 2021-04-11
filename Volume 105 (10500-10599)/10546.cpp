/* @JUDGE_ID: 19899RK 10546 C++ "By Anadan" */
// The Eagle's Nest
// Algorithm: LIS
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#define SZ 100

int arr[SZ], len[SZ], removeLen[SZ], N;

int binsearch(int sz, int elem) {
	int i = 0, j = sz - 1, k;

	while (i + 1 < j) {
		k = (i + j) >> 1;
		if (arr[len[k]] >= elem) j = k;
		else i = k;
	}
	while (j >= 0 && arr[len[j]] >= elem) --j;
	return j;
}

int getMaxLen() {
	int i, j, maxlen = 1;

	len[0] = 0;
	for (i = 1; i < N; ++i) {
		j = binsearch(maxlen, arr[i]);
		len[++j] = i;
		if (j == maxlen) ++maxlen;
	}
	return maxlen;
}

int remove(int maxmaxlen) {
	int i, j, k, maxlen = 1;

	if (N < maxmaxlen) return 0;

	len[0] = 0;
	removeLen[0] = 1;
	for (i = 1; i < N; ++i) {
		j = binsearch(maxlen, arr[i]);
		len[++j] = i;
		if (j == maxlen) {
			if (++maxlen == maxmaxlen) break;
		}
		removeLen[i] = maxlen;
	}

	if (maxlen != maxmaxlen) return 0;
	removeLen[i] = maxlen;

	len[maxlen-1] = i--;
	for (j = maxlen-1; j && i >= 0; --i) {
		if (removeLen[i] < j) --j;
		if (arr[i] < arr[len[j]]) len[j-1] = i;
	}

	for (i = j = k = 0; i < N; ++i) {
		if (j < maxlen && i == len[j]) ++j;
		else arr[k++] = arr[i];
	}
	N = k;

	return 1;
}

int main() {
	int set = 0, i, res;

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; ++i) scanf("%*s%d", arr+i);
		i = getMaxLen();
		if (i == 1) res = N;
		else {
			for (res = 0; remove(i); res += i);
		}
		printf("Case #%d: %d\n", ++set, res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
