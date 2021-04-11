/* @JUDGE_ID: 19899RK 10182 C++ "By Anadan" */
// Bee Maja
// Accepted (0.004 seconds with low memory spent)

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

int main() {
	int N;

	while (scanf("%d", &N) == 1) {
		BeeCoordinates tmp(N);
		printf("%d %d\n", tmp.getX(), tmp.getY());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
