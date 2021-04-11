/* @JUDGE_ID: 19899RK 10622 C++ "By Anadan" */
// Perfect Pth Powers
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int maxPower(int N) {
	int i, num, negative = 0;
	double tmp;

	if (N == -2147483648) return 31;
	if (N < 0) { negative = 1; N = -N; }

	for (i = 30; i > 1; --i) {
		if (negative && !(i&1)) continue;
		tmp = pow(N, 1.0/i);
		num = floor(tmp + 1e-10);
		if (!(N%num) && fabs(tmp - num) < 1e-10) break;
	}
	return i;
}

int main() {
	int N;
	while (scanf("%d", &N) == 1 && N) {
		printf("%d\n", maxPower(N));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
