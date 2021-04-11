/* @JUDGE_ID: 19899RK 199 C++ "By Anadan" */
// Partial differential equations
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, V[3][3], G[3][3], B[4][32], F[32][32], res[900][900], resVec[900], currRow;

void solve() {
	int i, j, a, b, k;

	for (i = 0; i < 3; ++i) for (j = 0; j < 3; ++j) V[i][j] *= N * N;

	memset(res, 0, sizeof(res));
	memset(resVec, 0, sizeof(resVec));
	currRow = 0;

	for (i = 1; i < N; ++i) {
		for (j = 1; j < N; ++j) {
			for (a = -1; a <= 1; ++a) for (b = -1; b <= 1; ++b) {
				resVec[currRow] += G[a+1][b+1] * F[i+a][j+b];

				if (i + a == 0) resVec[currRow] -= V[a+1][b+1] * B[1][j+b];
				else if (j + b == 0) resVec[currRow] -= V[a+1][b+1] * B[2][N-i-a];
				else if (i + a == N) resVec[currRow] -= V[a+1][b+1] * B[0][j+b];
				else if (j + b == N) resVec[currRow] -= V[a+1][b+1] * B[3][N-i-a];
				else {
					k = (N-1) * (i+a-1) + j+b-1;
					res[currRow][k] += V[a+1][b+1];
				}
			}
			++currRow;
		}
	}
}

int main() {
	int set, i, j;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		for (i = 0; i < 3; ++i)  for (j = 0; j < 3; ++j)  scanf("%d", &V[i][j]);
		for (i = 0; i < 3; ++i)  for (j = 0; j < 3; ++j)  scanf("%d", &G[i][j]);
		for (i = 0; i < 4; ++i)  for (j = 0; j <= N; ++j) scanf("%d", &B[i][j]);
		for (i = 0; i <= N; ++i) for (j = 0; j <= N; ++j) scanf("%d", &F[i][j]);

		solve();

		for (i = 0; i < currRow; ++i) {
			for (j = 0; j < currRow; ++j) {
				if (j) putchar(' ');
				printf("%d", res[i][j]);
			}
			putchar('\n');
		}
		for (i = 0; i < currRow; ++i) {
			if (i) putchar(' ');
			printf("%d", resVec[i]);
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
