/* @JUDGE_ID: 19899RK 10865 C++ "By Anadan" */
// Brownie Points I
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#define SZ 200000

int xx[SZ], yy[SZ];

void myscanf(int &x){
	int i, sgn = 0;

	while ((x = getchar()) != EOF && x != '-' && (x < '0' || x > '9'));
	if (x == '-') { sgn = 1; x = getchar(); }

	x -= '0';
	while ((i = getchar()) >= '0' && i <= '9') x = x * 10 + i - '0';
	if (sgn) x = -x;
}

int main() {
	int i, a, b, x, y, N;

	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; ++i) {
			myscanf(xx[i]);
			myscanf(yy[i]);
		}

		a = b = 0;
		x = xx[N/2];
		y = yy[N/2];
		for (i = 0; i < N; ++i) {
			if (xx[i] > x) {
				if (yy[i] > y) ++a;
				else if (yy[i] < y) ++b;
			} else if (xx[i] < x) {
				if (yy[i] > y) ++b;
				else if (yy[i] < y) ++a;
			}
		}

		printf("%d %d\n", a, b);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
