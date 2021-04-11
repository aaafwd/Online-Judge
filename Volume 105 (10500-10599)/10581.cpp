/* @JUDGE_ID: 19899RK 10581 C++ "By Anadan" */
// Partitioning for fun and profit
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int P[221][11], res[11];

void precalc() {
	int i, j, m;

	memset(P, 0, sizeof(P));
	P[0][0] = 1;

	for (i = 1; i <= 220; ++i) {
		P[i][i] = P[i][1] = 1;
		for (m = 2; m < i && m < 11; ++m) {
			P[i][m] = 0;
			for (j = 1; j <= m; ++j) {
				P[i][m] += P[i-m][j];
			}
		}
	}
}

void calcPartition(int m, int n, int k, int offset) {
	int i, j;

	if (k == 1) {
		for (i = 0; i < n-1; ++i) res[offset+i] = 1;
		res[offset+i] = m-n+1;
		return;
	}

	for (i = 1; k > P[m-n][i]; ++i) k -= P[m-n][i];
	for (j = 0; j < n-i; ++j) res[offset+j] = 1;
	calcPartition(m-n, i, k, offset+n-i);
	for (; j < n; ++j) ++res[offset+j];
}

int main() {
	int set, m, n, k;

	precalc();

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d%d", &m, &n, &k);
		calcPartition(m, n, k, 0);
		for (m = 0; m < n; ++m) printf("%d\n", res[m]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
