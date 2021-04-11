/* @JUDGE_ID: 19899RK 10889 C++ "By Anadan" */
// The Lost Gift
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main() {
	int R, B, b1, b2, i;
	double tmp;

	while (scanf("%d%d", &R, &B) == 2 && R) {
		tmp = sqrt(8.0*R + 1);
		i = (int)floor(tmp + 1e-12);
		if (fabs(tmp - i) < 1e-12) {
			b1 = (1+R*2 - i)/2;
			b2 = (1+R*2 + i)/2;
			if (b1 < B || b1 * 7 > B * 10) b1 = -1;
			if (b2 < B || b2 * 7 > B * 10) b2 = -1;
			if (b1 > b2) b1 ^= b2 ^= b1 ^= b2;

			if (b1 == -1 && b2 == -1) puts("No. of black balls invalid");
			else if (b1 != -1 && b2 != -1) printf("%d %d\n", b1-B, b2-B);
			else printf("%d\n", b1+b2+1-B);
		} else {
			puts("No. of red balls invalid");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
