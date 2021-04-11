/* @JUDGE_ID: 19899RK 10304 C++ "By Anadan" */
// Optimal Binary Search Tree
// Accepted (1.557 seconds using as much as 768 kbytes)

#include <stdio.h>
#include <string.h>

int N, arr[250], asum[250], cost[250][250];
short root[250][250];

int getCost(int i, int j) {
	int k, tmp;

	if (i >= j) {
		cost[i][j] = 0;
		root[i][j] = j;
		return 0;
	}

	if (root[i][j-1] == -1) getCost(i, j-1);
	if (root[i+1][j] == -1) getCost(i+1, j);

	int tok = root[i+1][j], min = 0x7FFFFFFF;

	for (k = root[i][j-1]; k <= tok; ++k) {
		if (root[i][k-1] == -1) getCost(i, k-1);
		if (root[k+1][j] == -1) getCost(k+1, j);
		tmp = cost[i][k-1] + cost[k+1][j] - arr[k];
		if (min > tmp) {
			min = tmp;
			root[i][j] = k;
		}
	}
	if (i) min += asum[j] - asum[i-1];
	else min += asum[j];
	return (cost[i][j] = min);
}

int main() {
	int i;
	while (scanf("%d", &N) == 1) {
		for (i = 0; i < N; ++i) {
			scanf("%d", arr+i);
			asum[i] = arr[i];
			if (i) asum[i] += asum[i-1];
		}
		memset(root, -1, sizeof(root));
		printf("%d\n", getCost(0, N-1));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
