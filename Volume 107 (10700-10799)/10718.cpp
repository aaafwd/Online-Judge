/* @JUDGE_ID: 19899RK 10718 C++ "By Anadan" */
// Bit Mask
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>

int main() {
	int i;
	unsigned int N, L, U, M, t1, t2;

	while (scanf("%u%u%u", &N, &L, &U) == 3) {
		M = 0;
		for (i = 31; i >= 0; --i) {
			t1 = M | (1 << i);
			if (t1 <= L) {
				M = t1;
			} else if (!(N & (1 << i))) {
				t2 = (t1 - 1) | (1 << i);
				if (t1 <= U && t2 >= L) M = t1;
			}
		}
		printf("%u\n", M);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
