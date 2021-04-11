/* @JUDGE_ID: 19899RK 10763 C++ "By Anadan" */
// Foreign Exchange
// Accepted (0.254 seconds using as much as 388 kbytes)

#include <stdio.h>

int main() {
	int N, i, j, a, b, x, y, count;

	while (scanf("%d", &N) == 1 && N) {
		a = b = count = 0;
		for (i = 0; i < N; ++i) {
			// myscanf(x);
			while ((x = getchar()) < '0' || x > '9'); x -= '0';
			while ((j = getchar()) >= '0' && j <= '9') x = x * 10 + j - '0';

			// myscanf(y);
			while ((y = getchar()) < '0' || y > '9'); y -= '0';
			while ((j = getchar()) >= '0' && j <= '9') y = y * 10 + j - '0';

			if (x < y) {
				a ^= x;
				b ^= y;
			} else {
				a ^= y;
				b ^= x;
				++count;
			}
		}
		count <<= 1;
		if (!a && !b && count == N) puts("YES");
		else puts("NO");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
