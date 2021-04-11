/* @JUDGE_ID: 19899RK 10595 C++ "By Anadan" */
// Knight on the Bee Board
// Accepted (0.053 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

class BeeCoordinates {
protected:
	int x, y;

public:
	// assert N > 0
	BeeCoordinates(int N) {
		int K = int((sqrt(12*N-3) - 3) / 6), num;
		while (N > 3*K*(K+1)+1) ++K;
		num = 3*K*(K-1)+2;

		if (N < num + K) {
			this->x = K - 1 - N + num;
			this->y = N - num + 1;
		} else if (N < num + K*2) {
			this->x = K - 1 - N + num;
			this->y = K;
		} else if (N < num + K*3) {
			this->x = -K;
			this->y = num + K*3 - 1 - N;
		} else if (N < num + K*4) {
			this->x = N - num - K*4 + 1;
			this->y = num + K*3 - 1 - N;
		} else if (N < num + K*5) {
			this->x = N - num - K*4 + 1;
			this->y = -K;
		} else {
			this->x = K;
			this->y = N - num - K*6 + 1;
		}
	}

	BeeCoordinates(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int getX() const { return x; }
	int getY() const { return y; }

	int getNumber() const {
		int res, K;

		if (x >= 0) {
			if (y >= 0) {
				K = x + y;
				if (y) res = 2 + 3*K*(K-1) + y - 1;
				else res = 3*K*(K+1) + 1;
			} else {
				K = (-y < x) ? (x) : (-y);
				if (K == x) {
					res = 3*K*(K+1) + 1 + y;
				} else {
					res = 2 + 3*K*(K-1) + 4*K - 1 + x;
				}
			}
		} else {
			if (y >= 0) {
				K = (-x < y) ? (y) : (-x);
				if (K == y) {
					res = 2 + 3*K*(K-1) + K - 1 - x;
				} else {
					res = 2 + 3*K*(K-1) + 3*K - 1 - y;
				}
			} else {
				K = -x - y;
				res = 2 + 3*K*(K-1) + 4*K - 1 + x;
			}
		}

		return res;
	}
};

#include <string.h>

int N, que[10010];
char map[10010];

const int dx[] = { 2, 1, -1, -2, -3, -3, -2, -1,  1,  2,  3,  3 };
const int dy[] = { 1, 2,  3,  3,  1,  2, -1, -2, -3, -3, -1, -2 };

int wave(int src, int dst) {
	int i = 0, j = 1, k, step = 0, count, num;

	que[0] = src;
	while (i < j) {
		count = 0;
		while (i < j) {
			src = que[i++];
			if (src == dst) return step;

			BeeCoordinates tmp(src+1);
			for (k = 0; k < 12; ++k) {
				num = BeeCoordinates(tmp.getX()+dx[k], tmp.getY()+dy[k]).getNumber() - 1;
				if (num < N && !map[num]) {
					map[num] = 1;
					que[j + count++] = num;
				}
			}
		}

		j += count;
		++step;
	}

	return -1;
}

int main() {
	int M, i, j;

	while (scanf("%d%d", &N, &M) == 2) {
		memset(map, 0, N);
		while (M--) {
			scanf("%d", &i);
			map[i-1] = 1;
		}
		scanf("%d%d", &i, &j);
		M = wave(i-1, j-1);
		if (M >= 0) printf("%d\n", M);
		else puts("Impossible.");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
