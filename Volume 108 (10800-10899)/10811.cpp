/* @JUDGE_ID: 19899RK 10811 C++ "By Anadan" */
// Up the Ante
// Accepted (3.357 seconds using as much as 20864 kbytes)

#include <stdio.h>
#include <string.h>

#define SZ		8192
#define ZERO	(SZ/2)

int K, L, M;
double A[32][SZ][10];

const double p1 = 1.0 / 7;
const double p2 = 1.0 / 14;
const double p3 = 1.0 / 14;

void solve() {
	int i, j, k, bet;

	for (i = 0; i < 32; ++i) {
		for (j = 0; j < SZ; ++j) {
			for (k = 0; k < 10; ++k) {
				A[i][j][k] = 0;
			}
		}
	}

	A[0][ZERO][0] = 1;
	for (i = 0; i < K; ++i) {
		for (j = 0; j < SZ; ++j) {
			for (k = 0; k < 10; ++k) {
				bet = 1 << k;
				if (0 <= j+bet*1 && j+bet*1 < SZ) A[i+1][j+bet*1][0] += p1*A[i][j][k];
				if (0 <= j+bet*2 && j+bet*2 < SZ) A[i+1][j+bet*2][0] += p2*A[i][j][k];
				if (0 <= j+bet*3 && j+bet*3 < SZ) A[i+1][j+bet*3][0] += p3*A[i][j][k];
				if (0 <= j-bet && j-bet < SZ) {
					if ((1 << (k+1)) <= L) A[i+1][j-bet][k+1] += A[i][j][k] * (1-p1-p2-p3);
					else A[i+1][j-bet][0] += A[i][j][k] * (1-p1-p2-p3);
				}
			}
		}
	}

	for (; i < M; ++i) {
		for (j = 0; j <= ZERO; ++j) {
			for (k = 0; k < 10; ++k) {
				bet = 1 << k;
				if (0 <= j+bet*1 && j+bet*1 < SZ) A[i+1][j+bet*1][0] += p1*A[i][j][k];
				if (0 <= j+bet*2 && j+bet*2 < SZ) A[i+1][j+bet*2][0] += p2*A[i][j][k];
				if (0 <= j+bet*3 && j+bet*3 < SZ) A[i+1][j+bet*3][0] += p3*A[i][j][k];
				if (0 <= j-bet && j-bet < SZ) {
					if ((1 << (k+1)) <= L) A[i+1][j-bet][k+1] += A[i][j][k] * (1-p1-p2-p3);
					else A[i+1][j-bet][0] += A[i][j][k] * (1-p1-p2-p3);
				}
			}
		}
	}

	double res = 0;

	for (j = 0; j <= ZERO; ++j) {
		for (k = 0; k < 10; ++k) {
			res += A[i][j][k];
		}
	}

	printf("%.4lf\n", 1-res);
}

int main() {
	int set;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d%d", &K, &M, &L);
		solve();
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
