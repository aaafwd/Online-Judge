/* @JUDGE_ID: 19899RK 10710 C++ "By Anadan" */
// Chinese Shuffle
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>

typedef long long  qword;

int solved(int N) {
	int res = 1, tmp = 2, power = N - 1;

	if (!(N & 1)) return 0;
	while (power) {
		if (power & 1) {
			res = int((qword(res) * tmp) % N);
			--power;
		} else {
			tmp = int((qword(tmp) * tmp) % N);
			power >>= 1;
		}
	}
	return (res == 1);
}

int main() {
	int N;
	while (scanf("%d", &N) == 1 && N > 0) {
		if (solved(N)) printf("%d is a Jimmy-number\n", N);
		else printf("%d is not a Jimmy-number\n", N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
