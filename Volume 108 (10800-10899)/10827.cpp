/* @JUDGE_ID: 19899RK 10827 C++ "By Anadan" */
// Maximum sum on a torus
// Accepted (0.264 seconds using as much as 440 kbytes)

#include <stdio.h>
#define SZ 75

int N, map[SZ][SZ], psum[SZ][SZ];

int solve() {
	int i, j, k, x, min, bmax, bmin, sum, maxsum = map[0][0];

	for (i = 1; i < N; ++i) {
		for (j = N - 2; j >= i; --j) {
			sum = min = bmin = bmax = 0;
			for (k = 0; k < N; ++k) {
				x = psum[k][N-1] - psum[k][j] + psum[k][i-1];
				if (bmax < sum) bmax = sum;
				sum += x;
				if (min > sum - bmax) min = sum - bmax;

				if (bmin > sum) bmin = sum;
				if (maxsum < sum - bmin) maxsum = sum - bmin;
			}
			if (maxsum < sum - min) maxsum = sum - min;
		}
	}

	for (i = 0; i < N; ++i) {
		for (j = i; j < N; ++j) {
			sum = min = bmin = bmax = 0;
			for (k = 0; k < N; ++k) {
				x = psum[k][j] - psum[k][i] + map[k][i];
				if (bmax < sum) bmax = sum;
				sum += x;
				if (min > sum - bmax) min = sum - bmax;

				if (bmin > sum) bmin = sum;
				if (maxsum < sum - bmin) maxsum = sum - bmin;
			}
			if (maxsum < sum - min) maxsum = sum - min;
		}
	}
	return maxsum;
}

void myscanf(int &x){
	int i, sgn = 0;

	while ((x = getchar()) != EOF && x != '-' && (x < '0' || x > '9'));
	if (x == '-') { sgn = 1; x = getchar(); }

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9') x = x * 10 + i - '0';
	if (sgn) x = -x;
}

int main() {
	int set, i, j;

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);

		for (i = 0; i < N; ++i) {
			myscanf(map[i][0]);
			psum[i][0] = map[i][0];
			for (j = 1; j < N; ++j) {
				myscanf(map[i][j]);
				psum[i][j] = psum[i][j-1] + map[i][j];
			}
		}

		printf("%d\n", solve());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
