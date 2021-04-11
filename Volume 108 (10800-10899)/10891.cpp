/* @JUDGE_ID: 19899RK 10891 C++ "By Anadan" */
// Game of Sum
// Accepted (1.051 seconds using as much as 488 kbytes)

#include <stdio.h>
#include <string.h>

int N, nums[100], maxdiff[2][100][100];
char flag[2][100][100];

int getMaxDiff(int i, int j, int p) {
	int k, sum, tmp;

	if (flag[p][i][j]) return maxdiff[p][i][j];
	if (i > j) return 0;

	if (p == 0) {
		sum = 0;
		for (k = i; k <= j; ++k) {
			sum += nums[k];
			tmp = sum + getMaxDiff(k+1, j, 1);
			if (k == i || maxdiff[0][i][j] < tmp) maxdiff[0][i][j] = tmp;
		}
		sum = 0;
		for (k = j; k > i; --k) {
			sum += nums[k];
			tmp = sum + getMaxDiff(i, k-1, 1);
			if (maxdiff[0][i][j] < tmp) maxdiff[0][i][j] = tmp;
		}
	} else { // p == 1
		sum = 0;
		for (k = i; k <= j; ++k) {
			sum += nums[k];
			tmp = getMaxDiff(k+1, j, 0) - sum;
			if (k == i || maxdiff[1][i][j] > tmp) maxdiff[1][i][j] = tmp;
		}
		sum = 0;
		for (k = j; k > i; --k) {
			sum += nums[k];
			tmp = getMaxDiff(i, k-1, 0) - sum;
			if (maxdiff[1][i][j] > tmp) maxdiff[1][i][j] = tmp;
		}
	}

	flag[p][i][j] = 1;
	return maxdiff[p][i][j];
}

int main() {
	int i, j;

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; ++i) scanf("%d", nums+i);
		memset(flag, 0, sizeof(flag));
		printf("%d\n", getMaxDiff(0, N-1, 0));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
